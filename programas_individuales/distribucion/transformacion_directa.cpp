// Compilar - g++ transformacion_directa.cpp -o td
// Ejecutar - ./td

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

#define PI 3.14159265

void transformacion(int, int, int);
void dist_normal(float, float, int);

float* x, *z; // Arreglos dinámicos de datos.

int main(){
    int n, m, sigma;

    cout << "Introduce el número de datos: ";
	cin >> n;

    x = new float[n]; // Crear arreglo de tamaño n.
    z = new float[n];

    cout << "\nIntroduce el valor medio (m): ";
    cin >> m;
    cout << "\nIntroduce el valor de sigma (sigma): ";
    cin >> sigma;

    float r1 = rand() % 1;
    cout << "\nNúmero aleatorio R1: " << r1 << endl;
    float r2 = rand() % 1;
    cout << "Número aleatorio R2: " << r2 << endl;

    dist_normal(r1, r2, n);
    transformacion(m, sigma, n);

    cout << "Xi:\n[ ";
	for(int i = 0; i < n; i++){
		cout << x[i] << " ";
	}
	cout << "]" << endl;

    delete [] x;
    delete [] z;

    return 0;
}

void dist_normal(float r1, float r2, int n){
    float ln, cs;
    for(int i = 0; i < n; i++){
        ln = -2 * log(r1);
        cs = cos(2 * PI * (r2 * PI / 180));
        z[i] = (pow(ln, 1/2)) * cs;
    }
}

void transformacion(int m, int sigma, int n){
    for(int i = 0; i < n; i++){
        x[i] = m + (sigma * z[i]);
    }
}