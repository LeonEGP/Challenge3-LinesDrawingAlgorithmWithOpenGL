//Programa que implementa el dibujado de puntos para definición de líneas. Empleando OpenGL.
//Programador: León Emiliano García Pérez (A00573074).
//Fecha de entrega: 08.11.2022.

//Forma de compilar:
//  g++ main.cpp -o main -lfreeglut -lglew32 -lopengl32 -lopengl32 -lglu32

//Inclusión de Librerías.
#include <iostream>
#include <cmath>
#include <vector>
#include <GL/glut.h>

//Ajuste a Estandar.
using namespace std;

//Definición de estructura: Punto (int x, int y);
struct Punto {
    int x;
    int y;
};

//Definición de variables globales, para el caso cuando solo se desea imprimir una línea [Es necesario modificar el comentado del main].
Punto p1;
Punto p2;

//Función de inicialización. No recibe parámetros, no tiene valor de retorno. [Propio de OpenGL].
void inicializar(){

    glClearColor(1.0,1.0,1.0,0); //Establecer: Color de la Ventana de Display a = BLANCO.
    glMatrixMode(GL_PROJECTION); // Establecer: Parámetros de proyección.
    gluOrtho2D(0.0,400.0,0.0,400.0); //Definir: Matríz de Proyección Ortográfica 2D.

}

//Función que determina los valores de x y y para la formación de una línea mediante puntos, recibe dos Estructuras Punto (que son las que definen inicio y fin de la línea), retorna un vector de vectores de enteros con los datos x y y.
vector<vector <int>> datosLinea(Punto punto1, Punto punto2){

    Punto primero;
    Punto segundo;

    float discriminante1;
    float discriminante2;
    float pendiente;
    float yAux;

    vector <int> x;
    vector <int> y;

    vector <vector <int>> resultado;

    if (punto1.x < punto2.x){
        primero.x = punto1.x;
        primero.y = punto1.y;
        segundo.x = punto2.x;
        segundo.y = punto2.y;
    } else if (punto1.x > punto2.x){
        primero.x = punto2.x;
        primero.y = punto2.y;
        segundo.x = punto1.x;
        segundo.y = punto1.y;
    } else if (punto1.y < punto2.y){
        primero.x = punto1.x;
        primero.y = punto1.y;
        segundo.x = punto2.x;
        segundo.y = punto2.y;
    } else {
        primero.x = punto2.x;
        primero.y = punto2.y;
        segundo.x = punto1.x;
        segundo.y = punto1.y;
    }

    discriminante1 = segundo.y - primero.y;
    discriminante2 = segundo.x - primero.x;

    pendiente = discriminante1 / discriminante2;

    yAux = primero.y;

    for (float i = primero.x; i<= segundo.x; i++){

        int nuevaX;
        int nuevaY;
        nuevaY = round(yAux);
        nuevaX = round(i);
        x.push_back(nuevaX);
        y.push_back(nuevaY);

        if (pendiente != 1.0){

            float terminoMedio; //A solicitud del tutor: para aumentar la densidad de los puntos.
            terminoMedio = (yAux+yAux+pendiente)/2;

            int otraY;
            otraY = round(terminoMedio);

            x.push_back(nuevaX);
            y.push_back(otraY);

        }

        yAux += pendiente;

    }

    resultado.push_back(x);
    resultado.push_back(y);

    return resultado;

}

//Función que muestra los puntos de cinco lineas definidas dentro de sí misma, no recibe parámetros, no tiene valor de retorno. Se muestra en la Ventana de Display.
void myLines(){

    glClear(GL_COLOR_BUFFER_BIT); //Función de limpieza de Buffer.
    glColor3f(0.0,0.4,0.2); //Establecer: color de dibujado como = VERDE.
    glBegin(GL_POINTS); //Establecer: Cada vértice como un punto único.

    vector<vector <int>> resultado1;
    Punto tC1P1;
    tC1P1.x = 1;
    tC1P1.y = 2;
    Punto tC1P2;
    tC1P2.x = 100;
    tC1P2.y = 20;

    vector<vector <int>> resultado2;
    Punto tC2P1;
    tC2P1.x = 10;
    tC2P1.y = 200;
    Punto tC2P2;
    tC2P2.x = 50;
    tC2P2.y = 10;

    vector<vector <int>> resultado3;
    Punto tC3P1;
    tC3P1.x = 300;
    tC3P1.y = 300;
    Punto tC3P2;
    tC3P2.x = 10;
    tC3P2.y = 10;

    vector<vector <int>> resultado4;
    Punto tC4P1;
    tC4P1.x = 200;
    tC4P1.y = 300;
    Punto tC4P2;
    tC4P2.x = 250;
    tC4P2.y = 50;

    vector<vector <int>> resultado5;
    Punto tC5P1;
    tC5P1.x = 350;
    tC5P1.y = 350;
    Punto tC5P2;
    tC5P2.x = 100;
    tC5P2.y = 300;

    resultado1 = datosLinea(tC1P1,tC1P2);
    resultado2 = datosLinea(tC2P1,tC2P2);
    resultado3 = datosLinea(tC3P1,tC3P2);
    resultado4 = datosLinea(tC4P1,tC4P2);
    resultado5 = datosLinea(tC5P1,tC5P2);

    for (long long unsigned int i = 0; i < resultado1[0].size(); i++){
        glVertex2d(resultado1[0][i],resultado1[1][i]); //Muestra en la Ventana de Display.
    }

    for (long long unsigned int j = 0; j < resultado2[0].size(); j++){
        glVertex2d(resultado2[0][j],resultado2[1][j]); //Muestra en la Ventana de Display.
    }

    for (long long unsigned int k = 0; k < resultado3[0].size(); k++){
        glVertex2d(resultado3[0][k],resultado3[1][k]); //Muestra en la Ventana de Display.
    }

    for (long long unsigned int m = 0; m < resultado4[0].size(); m++){
        glVertex2d(resultado4[0][m],resultado4[1][m]); //Muestra en la Ventana de Display.
    }

    for (long long unsigned int n = 0; n < resultado5[0].size(); n++){
        glVertex2d(resultado5[0][n],resultado5[1][n]); //Muestra en la Ventana de Display.
    }

    glEnd(); //Delimitar: vertices.
    glFlush(); //Forzar: Ejecución de de funciones openGL en tiempo finito.

}

//Función que muestra los puntos que representan una línea, toma los valores de los dos Puntos que son variables globales, no tiene parámetros como tal, y no tiene valor de retorno. Se muestra en la Ventana de Display.
void myLine(){

    glClear(GL_COLOR_BUFFER_BIT); //Función de limpieza de Buffer.
    glColor3f(0.0,0.4,0.2); //Establecer: color de dibujado como = VERDE.
    glBegin(GL_POINTS); //Establecer: Cada vértice como un punto único.

    Punto primero;
    Punto segundo;

    float discriminante1;
    float discriminante2;
    float pendiente;
    float yAux;

    if (p1.x < p2.x){
        primero.x = p1.x;
        primero.y = p1.y;
        segundo.x = p2.x;
        segundo.y = p2.y;
    } else if (p1.x > p2.x){
        primero.x = p2.x;
        primero.y = p2.y;
        segundo.x = p1.x;
        segundo.y = p1.y;
    } else if (p1.y < p2.y){
        primero.x = p1.x;
        primero.y = p1.y;
        segundo.x = p2.x;
        segundo.y = p2.y;
    } else {
        primero.x = p2.x;
        primero.y = p2.y;
        segundo.x = p1.x;
        segundo.y = p1.y;
    }

    discriminante1 = segundo.y - primero.y;
    discriminante2 = segundo.x - primero.x;

    pendiente = discriminante1 / discriminante2;

    yAux = primero.y;

    for (float i = primero.x; i<= segundo.x; i++){

        int nuevaX;
        int nuevaY;
        nuevaY = round(yAux);
        nuevaX = round(i);
        glVertex2d(nuevaX,nuevaY); //Muestra en la Ventana de Display.

        if (pendiente != 1.0){ //Evitar dibujado en exceso.

            float terminoMedio; //A solicitud del tutor: para aumentar la densidad de los puntos.
            terminoMedio = (yAux+yAux+pendiente)/2;

            int otraY;
            otraY = round(terminoMedio);

            glVertex2d(nuevaX,otraY); //Muestra en la Ventana de Display.
        }

        yAux += pendiente;

    }

    glEnd(); //Delimitar: vertices.
    glFlush(); //Forzar: Ejecución de de funciones openGL en tiempo finito.

}

//Función de ejecución main recibe un entero y un apuntador de apuntadores de caracteres (un arreglo de caracteres), retorna un entero. [return 0]
int main(int argc, char** argv){

    //Cuando solo se imprime una línea, y se almacena todo en variables globales.
    /*
    cin >> p1.x;
    cin >> p1.y;
    cin >> p2.x;
    cin >> p2.y;
    */

    glutInit(&argc, argv); //Inicialización de GLUT.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Establacer: Modo Display.
    glutInitWindowPosition(100,100); //Establecer: Posición de la Ventana de Display.
    glutInitWindowSize(600,600); //Establecer: Resolución.
    glutCreateWindow("Challenge 3: A00573074"); //Establecer: Nombre de la Ventana de Display.
    inicializar(); //Llamada a la Función de Inicialización.

    //Cuando solo se imprime una línea, en función de los dos Puntos definidos en variables globales.
    /*
    glutDisplayFunc(myLine);
    */

    glutDisplayFunc(myLines); //Muestra las cinco líneas solicitadas en los Casos de Prueba.

    glutMainLoop(); //Establecer: Ventana de Display se mantenga en loop y no desaparezca.

    return 0;
}
