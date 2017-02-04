/*
	uso de teclado
	r => prende rojo 
	R => apaga rojo 
	G => apaga verde 
	g => prende verde
	B => apaga azul
	b => prende azul 
	x/X => mover camara en x +/-
	y/Y => mover camara en y +/-
	z/Z => mover camara en z +/-
*/
/*
	jiame margolin 
	A01019332
	Graficas computaiconales
	tankque topo-volador a control remoto
*/
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

//funcion de armado
void armamela();

//polioherdros para armar el coso
void ruedaIzquierdaT();
void ruedaIzquierdaD();
void ruedaDerechaT();
void ruedaDerechaD();
void taladro();
void malla();
void caparazon();
void cuerpo();
void antena();
void ojo();
void alasI();
void alasD();

//Variables que mueven la pos de la luz
float movX = 1.0;
float movY= 1.0;
float movZ = 1.0;
//variables para prender y apagar luz de colores
float r = 0.0;
float g = 0.0;
float b = 0.0;
//varaibles para pa pos de la cam 
float camX=0.0, camY=0.0, camZ=5.0;
void camReset()
{
	camX=0.0; camY=0.0; camZ=5.0;
} //reset a los valores de la camara



//Arreglos para crear diferentes tipos de materiales
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat no_shininess[] = { 0.0 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

// no inizializar nada
void init(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	glClearColor(0.5, 0.2, 0.2, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

//no se 
void display(void)
{

	GLfloat light_position[] = { movX, movY, movZ, 0.0 };
	GLfloat colors[] = {r, g, b};

	glLightfv(GL_LIGHT0, GL_AMBIENT, colors);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	 gluLookAt (camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	//armar el polioherdros coche 
		armamela();

	glPopMatrix();
	

	glFlush();
}

//ya dije 1 vez que hace esto
void armamela()
{
	ruedaIzquierdaT(); //1
	ruedaIzquierdaD(); //2
	ruedaDerechaT(); //3
	ruedaDerechaD(); //4 
	taladro(); //5 
	malla();//6 
	caparazon(); // 7 
	cuerpo();// 8 
	antena();//9 
	ojo();// 10
	alasI();//11
	alasD();//12
}

//lo normal
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w,
			1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)w / (GLfloat)h,
			1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//insntrucciones al inicio del docuemtno
//funcion para el teclado 
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'r': movX += 1.0;
		r = 1.0;
		glutPostRedisplay();
		break;
	case 'R': movX -= 1.0;
		r = 0.0;
		glutPostRedisplay();
		break;
	case 'G': movY -= 1.0;
		g = 0.0;
		glutPostRedisplay();
		break;
	case 'g': movY += 1.0;
		g = 1.0;
		glutPostRedisplay();
		break;
	case 'B': movZ -= 1.0;
		b = 0.0;
		glutPostRedisplay();
		break;
	case 'b': movZ += 1.0;
		b = 1.0;
		glutPostRedisplay();
		break;
		case 'x':
           camX++;
           glutPostRedisplay();
           break;
      case 'X':
           camX--;
           glutPostRedisplay();
           break;
       case 'y':
           camY++;
           glutPostRedisplay();
           break;
       case 'Y':
           camY--;
           glutPostRedisplay();
           break;
       case 'z':
           camZ++;
           glutPostRedisplay();
           break;
       case 'Z':
           camZ--;
           glutPostRedisplay();
           break;
		case 'i':
			camReset();
			glutPostRedisplay();
		   	break;
		case 'q':
			exit(0);
			break;
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	//preparar todo
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500); //window no windowS
	glutInitWindowPosition(100, 100); //donde window
	glutCreateWindow("hola moy :)"); //hello moy
	init(); //y D"os dijo, que se haga la luz..... y compilo GL
	glutDisplayFunc(display); //Display del objeto
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();// whiel true fork() ... o gl
	return 0;
}

//rueda izq back
void ruedaIzquierdaT() {
	glPushMatrix();
		glTranslatef(-0.7, -0.5, 0.6);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidTorus(.1, .2, 10, 10);
	glPopMatrix();
}

//rueda izq front
void ruedaIzquierdaD() {
	glPushMatrix();
		glTranslatef(0.3, -0.5, 0.6);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidTorus(.1, .2, 10, 10);
	glPopMatrix();
}

//rueda der front
void ruedaDerechaD() {
	glPushMatrix();
		glTranslatef(-0.7, -0.5, 1.4);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidTorus(.1, .2, 10, 10);
	glPopMatrix();
}

// reuda der back
void ruedaDerechaT() {
	glPushMatrix();
		glTranslatef(0.3, -0.5, 1.4);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidTorus(.1, .2, 10, 10);
	glPopMatrix();
}


// cono del taladro
void taladro() {
	glPushMatrix();
		glTranslatef(0.5, 0.0, 1.0);
		glRotatef(90, 0, 1, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidCone(0.25, 1.0, 60, 60);
	glPopMatrix();
}

// cuerda del taladro 
void malla() {
	glPushMatrix();
		glTranslatef(0.5, 0.0, 1.0);
		glScalef(1.01, 1.01, 1.01);
		glRotatef(90, 0, 1, 0);
		glColor3f(0.0, 0.0, 0.0);
		glutWireCone(0.25, 1.0, 60, 60);
	glPopMatrix();
}

// caparazon 
void caparazon() {
	glPushMatrix();
		glTranslatef(-0.2, 0.5, 1.0);
		glScalef(.9, .5, 1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glutSolidSphere(0.8, 20, 20);
	glPopMatrix();
}

//le body 
void cuerpo() {
	glPushMatrix();
		glTranslatef(-0.2, 0.0, 1.0);
		glScalef(1, 0.6, 1);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidIcosahedron();
	glPopMatrix();
}

// antena
void antena() {
	glPushMatrix();
		glTranslatef(-0.8, 0.0, 1.0);
		glRotatef(90, -1, 0, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidCone(.05, 2, 20, 20);
	glPopMatrix();
}

//el ojo
void ojo() {
	glPushMatrix();
		glTranslatef(0.35, 0.2, 2);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(0.1, 15, 15);
	glPopMatrix();
}

//alas
void alasI()
{
	glPushMatrix();
		glTranslatef(0.3, 0.2, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glRotated(-90,0,1,1);
		//glTranslatef(1.5f,1.7f,1.0f);
		glBegin(GL_TRIANGLES);   
			glVertex3f( 0.0f, 0.7f, 0.0f);
			glVertex3f(-0.7f, -0.7f, 0.7f);
			glVertex3f(0.7f, -0.7f, 0.7f);
	  glEnd();
	glPopMatrix();
}

//alas
void alasD()
{
	glPushMatrix();
		glTranslatef(0.3, 0.2, 1.7);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glRotated(-90,0,1,1);
		//glTranslatef(1.5f,1.7f,1.0f);
		glBegin(GL_TRIANGLES);   
			glVertex3f( 0.0f, 0.7f, 0.0f);
			glVertex3f(-0.7f, -0.7f, 0.7f);
			glVertex3f(0.7f, -0.7f, 0.7f);
	  glEnd();
	glPopMatrix();
}