#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Answerme{
    public:
    const string r1 = "a) 1950, MIT\nb) \n) sillicon graphics";
    const string r2 = "HMD = head mounted display; LCD = liquid crystal display; GPU = graphic processing unit; OpenGL ARB = Open graphics library architecture review board; GLUT = graphic library utility toolkit; ";
    const string r3 = "es como un rombo vertical circular. blanco es la punta superior y negra la inferior (correponde a intensity); los colores estan en el circulo (hue) y la saturasion es que tan cerca o lejos estan del centro, entre mas alejado mas fuerte es el color(saturation)";
    const string r4 = "transformacion de cuerpo rigido es la que no modifica su forma (area y volumen); rotacion, traslacion, ";
    const string r51 = "a) menor GhZ (vs CPU); mayores transistores -> mayor numero de cores; tienen su memoria dedicada; mejores con operaciones de punto flotante; puerto PCI express; transferencia mas rapida para graficas";
    const string r52 = "b) es un proceso que se esta corriendo constantemente; GL_IDLE";
    const string r6 = "Coordenadas cartesianas (x, y, z), cilindricas (distancia radial, desplazamiento angular (x-y) y desplazamiento en z)(p, phi, z), esféricas(distancia radial, desplazamiento angular (x-y) y desplazamiento angular en z)(r, teta, phi) y coordenadas 3D";
    const string r71 = "void main() { " \
"gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);  // color rojo con alfa 1, shader de color" \
"}";

    const string r72 = "attribute vec4 a_Position;  //* variable que cambia segun la posision del vertice" \
"uniform mat4 u_ModelMatrix;  // declara la matriz de transformacion (4x4)" \
"void main() {"\
"gl_Position = u_ModelMatrix * a_Position;  // transforma la nueva posicion con el calculo de la matrix de transformacion multiplicada por le vector de posicion nueva "\
"}";
    const string r73 = "pinta el arreglo, con gl triangles, que va de 0 a 'n'";
    const string r74 = "crea una matrix de trasnformaciones de 4x4, pasandole un objeto uniform a cambiar, el segundo parametro siempre es falso, es la transpuesta y el tercer parametro son los valores que va a tomar";
    const string r75 = "le indica con el bit de color que habra color en gl, reseteando el buffer";
    const string r76 = "guarda en el buffer 'vertices' con el tipo array_buffer y le indica que es un static_draw";
    const string r8 = "cactus";

    void print_answers()
    {
        std::cout << r1 << std::endl << r2 << std::endl << r3 << std::endl << r4 << std::endl << r51 << std::endl << r52 << std::endl << r6 << std::endl;
        std::cout << r71 << std::endl << r72 << std::endl << r73 << std::endl << r74 << std::endl << r75 << std::endl << r76 << std::endl << r8 << std::endl ;   

    }
};