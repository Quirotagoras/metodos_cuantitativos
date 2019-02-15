// Compilar - g++ aceptacion_rechazo.cpp -o ar
// Ejecutar - ./ar

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

struct Point{
    // Elementos
    float x, y;
    // Constructores
    Point(): x(0), y(0){}
    Point(float x, float y): x(x), y(y){}
};

int contar_bajo_curva(int);

Point* points;

int main(){
    int n, N, A = 1;

    float r1, r2;

    cout << "Introduce el número de puntos a generar: ";
	cin >> N;

    points = new Point[N];

    for(int i = 0; i < N; i++){
        r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); // Número aleatorio etre [0, 1]
        r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        //cout << "R1: " << r1 << ", R2: " << r2 << endl;
        points[i] = Point(r1, r2);
    }

    n = contar_bajo_curva(N);

    // Imprimir puntos
    /*cout << "Puntos:\n[ ";
	for(int i = 0; i < N; i++){
		cout << "(" << points[i].x << ", " << points[i].y << ") ";
	}
	cout << "]" << endl;*/

    cout << "Puntos bajo la curva: " << n << endl;

    cout << "n/N = " << (float)n/N << endl;

    delete [] points;

    return 0;
}

int contar_bajo_curva(int N){
    int contador = 0;
    float op;
    for(int i = 0; i < N; i++){
        //op = sqrt(1 - pow(points[i].x, 2));
        op = 9.481 * points[i].x * pow((1 - points[i].x), 3);
        if(points[i].y <= op){
            contador++;
        }
    }
    return contador;
}
