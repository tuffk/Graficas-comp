/*
 * Juan Carlos León Jarquín A01020200
 */

#include "robot.h"

/* animación del caminado */
void timer_walk(int){
  if(flag1) {
    theta[3] += 5.0;
  }
  else {
    theta[3] -= 5.0;
  }
  if(theta[3] >= 110.0) flag1 = false;
  if(theta[3] <= 70.0)  flag1 = true;

  if(flag2) {
    theta[5] += 5.0;
  }
  else {
    theta[5] -= 5.0;
  }
  if(theta[5] >= 110.0) flag2 = false;
  if(theta[5] <= 70.0)  flag2 = true;

  if(flag3) {
    theta[9] += 5.0;
  }
  else {
    theta[9] -= 5.0;
  }
  if(theta[9] >= 200.0) flag3 = false;
  if(theta[9] <= 160.0)  flag3 = true;

  if(flag4) {
    theta[7] += 5.0;
  }
  else {
    theta[7] -= 5.0;
  }
  if(theta[7] >= 200.0) flag4 = false;
  if(theta[7] <= 160.0)  flag4 = true;

  if(hflag) {
    theta[2] += 5.0;
  }
  else {
    theta[2] -= 5.0;
  }
  if(theta[2] >= 30.0) hflag = false;
  if(theta[2] <= -30.0) hflag = true;

  glutPostRedisplay();
  glutTimerFunc(100,timer_walk,0);
}

void timer_kick(int){
  if(flag1) {
    theta[3] -= 15.0;
  }
  else {
    theta[3] += 15.0;
  }
  if(theta[3] >= 60) flag1 = true;
  if(theta[3] <= 0)  flag1 = false;       // 0-45

  if(flag2) {
    theta[4] -= 30;
  }
  else {
    theta[4] += 30;
  }
  if(theta[4] >= 0) flag2 = true;
  if(theta[4] <= -120)  flag2 = false;
  theta[11]=-15;  // 0

  if(flag3) {
    theta[5] -= 15.0;
  }
  else {
    theta[5] += 15.0;
  }
  if(theta[5] >= 60) flag3 = true;
  if(theta[5] <= 0)  flag3 = false;       // 0-45

  if(flag4) {
    theta[6] -= 30;
  }
  else {
    theta[6] += 30;
  }
  if(theta[6] >= 0) flag4 = true;
  if(theta[6] <= -120)  flag4 = false;

  if(flag5) {
    theta[9] += 10.0;
  }
  else {
    theta[9] -= 10.0;
  }
  if(theta[9] >= 200.0) flag5 = false;
  if(theta[9] <= 160.0)  flag5 = true;

  if(flag6) {
    theta[7] += 10.0;
  }
  else {
    theta[7] -= 10.0;
  }
  if(theta[7] >= 200.0) flag6 = false;
  if(theta[7] <= 160.0)  flag6 = true;

  glutPostRedisplay();
  glutTimerFunc(200,timer_kick,0);
}

/* Dibujamos la cabeza del robot */
void head(){
  glPushMatrix();
    glColor3f(1.0, 0.0, 5.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glRotatef(15.0, 0.0, 0.0, 1.0);
    glScalef(HEAD_HEIGHT, HEAD_HEIGHT, HEAD_RADIUS);
    gluSphere(h, 1.0, 10, 10);
  glPopMatrix();
}

/* Dibujamos el cuello del robot */
void neck(){
  glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(n,NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT,10,10);
  glPopMatrix();
}

/* Dibujamos el torso del robot */
void torso(){
  glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(t,TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT,10,10);
  glPopMatrix();
}

/* Ponemos donde va a estar la intersección del cuerpo */
void joint_point(){
  glPushMatrix();
    glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT, JOINT_POINT_RADIUS);
    gluSphere(jp,1.0,10,10);
  glPopMatrix();
}

/* Brazo superior derecho */
void right_upper_arm(){
  glPushMatrix();
    gluCylinder(rua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10, 10);
  glPopMatrix();
}

/* Brazo superior izquierdo */
void left_upper_arm(){
  glPushMatrix();
    gluCylinder(lua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10, 10);
  glPopMatrix();
}

/* Brazo inferior derecho */
void right_lower_arm(){
  glPushMatrix();
    gluCylinder(rla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10, 10);
  glPopMatrix();
}

/* Brazo inferior izquierdo */
void left_lower_arm(){
  glPushMatrix();
    glRotatef(0.0, 1.0, 0.0, 0.0);
    gluCylinder(lla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10, 10);
  glPopMatrix();
}

/* Mano derecha */
void right_hand(){
  glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
    gluSphere(rhnd,1.0,10,10);
  glPopMatrix();
}

/* Mano izquierda */
void left_hand(){
  glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
    gluSphere(lhnd,1.0,10,10);
  glPopMatrix();
}

/* Muslo derecho */
void right_upper_leg(){
  glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(rul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10, 10);
  glPopMatrix();
}

/* Muslo izquierdo */
void left_upper_leg(){
  glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(lul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10, 10);
  glPopMatrix();
}

/* Chamorro derecho */
void right_lower_leg(){
  glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(rll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT, 10, 10);
  glPopMatrix();
}

/* Chamorro izquierdo */
void left_lower_leg(){
  glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(lll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT, 10, 10);
  glPopMatrix();
}

/* Pie derecho */
void right_foot(){
  glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
    gluSphere(rft,1.0,10,10);
  glPopMatrix();
}

/* Pie izquierdo */
void left_foot(){
  glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
    gluSphere(lft,1.0,10,10);
  glPopMatrix();
}

/* Funciones para GL Color*/
void color(){
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(0.0, 0.0, 0.0);
  glColor3ub(0, 0, 0);
}

void acomoda_torso(){
  glPushMatrix();
    // movemos el torso al centro del plano
    glTranslatef(0,TORSO_HEIGHT, 0.0);
    //le dibujamos el cuello
    neck();
    //l cual acomodamos del centro para arriba del torso
    glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
    glRotatef(theta[1], 1.0, 0.0, 0.0);
    glRotatef(theta[2], 0.0, 1.0, 0.0);
    //dibujas la cabeza
    head();
  glPopMatrix();
}

/* Agrega el punto donde el cuerpo se junta con el brazo izquierdo */
void agregaPuntoBrazoIzq(){
  glPushMatrix();
    //acomodamos donde estara el brazo izquierdo
    glTranslatef(-0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
    //agregamos el punto de unión
    joint_point();
    /* Acomodamos el brazo */
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(theta[3], 1.0, 0.0, 0.0);
    glRotatef(theta[11], 0.0, 0.0, 1.0);
    /* Pintamos el conejo izquierdo */
    left_upper_arm();
    // Planteamos la ubicacion del brazo inferior
    glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT);
    // Agregamos el punto de unión
    joint_point();
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[4], 1.0, 0.0, 0.0);
    /* Pintamos el brazo inferior */
    left_lower_arm();
    // Definimos el lugar de la mano
    glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
    /* AQUI ESTA MANUELA! */
    left_hand();
  glPopMatrix();
}

/* Agrega el punto donde el cuerpo se junta con el brazo derecho */
void agregaPuntoBrazoDer(){
  glPushMatrix();
    //acomodamos donde estara el brazo izquierdo
    glTranslatef(0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
    //agregamos el punto de unión
    joint_point();
    /* Acomodamos el brazo */
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(theta[5], 1.0, 0.0, 0.0);
    glRotatef(theta[12], 0.0, 0.0, 1.0);
    /* Pintamos el conejo derecho */
    right_upper_arm();
    // Planteamos la ubicacion del brazo inferior
    glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT);
    // Agregamos el punto de unión
    joint_point();
    glBindTexture(GL_TEXTURE_2D, texture4);
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[6], 1.0, 0.0, 0.0);
    /* Pintamos el brazo inferior */
    right_lower_arm();
    // Definimos el lugar de la mano
    glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
    /* AQUI ESTA MANUELA! */
    right_hand();
  glPopMatrix();
}

/* Agrega el punto de unión del torso con la pierna izquierda */
void agregaPuntoPiernaIzq(){
  glPushMatrix();
    /*Acomodas en el torso */
    glTranslatef(-(TORSO_RADIUS-JOINT_POINT_RADIUS), -0.15*JOINT_POINT_HEIGHT, 0.0);
    // agregas punto
    joint_point();
    glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[7], 1.0, 0.0, 0.0);
    glRotatef(theta[13], 0.0, 0.0, 1.0);
    //dibujas muslo
    left_upper_leg();
    // ubicas donde va chamorro
    glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
    // punto de chamorro
    joint_point();
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[8], 1.0, 0.0, 0.0);
    // dibujas chamorro
    left_lower_leg();
    //encuentras donde va pie
    glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
    glRotatef(theta[15], 1.0, 0.0, 0.0);
    //dibujas pie
    left_foot();
  glPopMatrix();
}

/* Agrega el punto de unión del torso con la pierna derecha */
void agregaPuntoPiernaDer(){
  glPushMatrix();
    /*Acomodas en el torso */
    glTranslatef(TORSO_RADIUS-JOINT_POINT_RADIUS, -0.15*JOINT_POINT_HEIGHT, 0.0);
    // agregas punto
    joint_point();
    glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[9], 1.0, 0.0, 0.0);
    glRotatef(theta[14], 0.0, 0.0, 1.0);
    //dibujas muslo
    left_upper_leg();
    // ubicas donde va chamorro
    glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
    // punto de chamorro
    joint_point();
    glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
    glRotatef(theta[10], 1.0, 0.0, 0.0);
    // dibujas chamorro
    left_lower_leg();
    //encuentras donde va pie
    glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
    glRotatef(theta[16], 1.0, 0.0, 0.0);
    //dibujas pie
    left_foot();
  glPopMatrix();
}

/* Enseña lo que programas*/
void display(void){
  color();
  glRotatef(theta[0], 0.0, 1.0, 0.0);
  torso();
  acomoda_torso();
  agregaPuntoBrazoIzq();
  agregaPuntoBrazoDer();
  agregaPuntoPiernaIzq();
  agregaPuntoPiernaDer();
  glFlush();
  glutSwapBuffers();
}

void reshape(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (w <= h)
    glOrtho(-30.0, 30.0, -30.0 * (GLfloat) h / (GLfloat) w, 30.0 * (GLfloat) h / (GLfloat) w, -200, 200);
  else
    glOrtho(-30.0 * (GLfloat) w / (GLfloat) h, 30.0 * (GLfloat) w / (GLfloat) h, -30.0, 30.0, -200, 200);

  gluPerspective(1.0, (float)w/h, 2.0, 1.0);
  gluLookAt(translation[3].value, translation[4].value, eye[2], at[0], at[1], at[2], up[0], up[1],up[2]);
  glTranslatef(translation[0].value, translation[1].value, translation[2].value);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void redisplay_all(void){
    reshape(WIN_WIDTH, WIN_HEIGHT);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
  /*if(key=='q') choise=2; //mueves la cabeza horizontalmente
  if(key=='a') choise=1; //mueves la cabeza verticalmente
  if(key=='w') choise=3; //brazo izquierdo horizontalmente
  if(key=='s') choise=11; //brazo izquierdo verticalmente
  if(key=='e') choise=5;  //brazo derecho horizontalmente
  if(key=='d') choise=12; //brazo derecho verticalmente
  if(key=='r') choise=7;   //pierna izquierda horizontalmente
  if(key=='f') choise=13;  //pierna izquierda verticalmente
  if(key=='t') choise=9;   // pierna derecha horizontalmente
  if(key=='g') choise=14;  //pierna derecha verticalmente
  if(key=='z') choise=0;   //torso
  if(key=='x') choise=4;   //Hombro izq
  if(key=='c') choise=6;   //Hombro der
  if(key=='v') choise=8;   //chamorro izquierdo
  if(key=='b') choise=10;  //chamorro derecho
  if(key==',') choise=15;   //pie izquierdo
  if(key=='.') choise=16;   //pie derecho*/
  if(key=='m')
  {
    glutTimerFunc(100,timer_walk,0);
  } //camina!
  if(key=='n'){
    glutTimerFunc(100,timer_kick,0);
  } //se mueve completo!
}

/* Area del mouse */
void area_update(area* area, int update){
  if (selection != area->id)
    return;

  area->value += update * area->step;

  if (area->value < area->min)
    area->value = area->min;
  else if (area->value > area->max)
    area->value = area->max;
}

/* area para el click del mouse */
int area_hit(area* area, int x, int y){
  if ((x > 0 && x < WIN_WIDTH) && (y > 0 && y < WIN_HEIGHT))
    return area->id;
  return 0;
}

int old_y, old_x;

void menu(int id) {
   if(id <3 ) m_choise=id;
   if(id == 3 ) exit(1);
}

/* RATON!!! \o/ */
void mouse(int button, int state, int x, int y)
{
  selection = 0;
  if (button==GLUT_LEFT_BUTTON && state == GLUT_DOWN && (m_choise==0||m_choise==2)) {
    selection += area_hit(&translation[0], x, y);
    if (m_choise==0) selection += area_hit(&translation[0], x, y);
    if (m_choise==2) selection += area_hit(&translation[3], x, y);
    old_x = x;
    redisplay_all();
  }
  if (button==GLUT_RIGHT_BUTTON && state == GLUT_DOWN && ((m_choise==0||m_choise==1)||m_choise==2)) {
    if (m_choise==0) selection += area_hit(&translation[1], x, y);
    if (m_choise==1) selection += area_hit(&translation[2], x, y);
    if (m_choise==2) selection += area_hit(&translation[4], x, y);
    old_y = y;
    redisplay_all();
  }
}

/* funcion onclick era muy mainstream */
void pressed_mouse(int x, int y)
{
  area_update(&translation[0], x-old_x);
  area_update(&translation[1], old_y-y);
  area_update(&translation[2], old_y-y);
  area_update(&translation[3], x-old_x);
  area_update(&translation[4], old_y-y);
  old_y = y;
  old_x = x;
  redisplay_all();
}

void luces(){
  GLfloat mat_specular[]={1.0, 1.0, 1.0, 1.0};
  GLfloat mat_diffuse[]={1.0, 1.0, 1.0, 1.0};
  GLfloat mat_ambient[]={1.0, 1.0, 1.0, 1.0};
  GLfloat mat_shininess={100.0};
  GLfloat light_ambient[]={1.0, 0.0, 0.0, 1.0};
  GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
  GLfloat light_specular[]={1.0, 0.0, 0.0, 1.0};
  GLfloat light_position[]={10.0, 10.0, 10.0, 0.0};

  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}

void material(){
  glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glDepthFunc(GL_LEQUAL);
}

void quadratics(){
  h=gluNewQuadric();
  gluQuadricDrawStyle(h, GLU_FILL);
  n=gluNewQuadric();
  gluQuadricDrawStyle(n, GLU_FILL);
  t=gluNewQuadric();
  gluQuadricDrawStyle(t, GLU_FILL);
  jp=gluNewQuadric();
  gluQuadricDrawStyle(jp, GLU_FILL);
  lua=gluNewQuadric();
  gluQuadricDrawStyle(lua, GLU_FILL);
  lla=gluNewQuadric();
  gluQuadricDrawStyle(lla, GLU_FILL);
  lhnd=gluNewQuadric();
  gluQuadricDrawStyle(lhnd, GLU_FILL);
  rhnd=gluNewQuadric();
  gluQuadricDrawStyle(rhnd, GLU_FILL);
  rft=gluNewQuadric();
  gluQuadricDrawStyle(rft, GLU_FILL);
  lft=gluNewQuadric();
  gluQuadricDrawStyle(lft, GLU_FILL);
  rua=gluNewQuadric();
  gluQuadricDrawStyle(rua, GLU_FILL);
  rla=gluNewQuadric();
  gluQuadricDrawStyle(rla, GLU_FILL);
  lul=gluNewQuadric();
  gluQuadricDrawStyle(lul, GLU_FILL);
  lll=gluNewQuadric();
  gluQuadricDrawStyle(lll, GLU_FILL);
  rul=gluNewQuadric();
  gluQuadricDrawStyle(rul, GLU_FILL);
  rll=gluNewQuadric();
  gluQuadricDrawStyle(rll, GLU_FILL);
}

void init(){
  luces();
  material();
  quadratics();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WIN_WIDTH,WIN_HEIGHT);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Robot");
  init();
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMotionFunc(pressed_mouse);
  glutMouseFunc(mouse);
  glutCreateMenu(menu);
  glutAddMenuEntry("view_hor/vert", 0);
  glutAddMenuEntry("view_zoom_in/out", 1);
  glutAddMenuEntry("view_lft-rgt/up-dow", 2);
  glutAddMenuEntry("quit", 3);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
  glutKeyboardFunc(keyboard);
  redisplay_all();
  glutMainLoop();
}
