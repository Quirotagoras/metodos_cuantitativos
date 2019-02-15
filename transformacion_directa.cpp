// Compilar - g++ transformacion_directa.cpp -o td
// Ejecutar - ./td

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

void transformacion(int, int, int);
void dist_normal(int, int, int);

float* x, *z; // Arreglos dinámicos de datos.

int main(){
    int n, m, sigma;

    cout << "Introduce el número de datos: ";
	cin >> n;

    x = new float[n]; // Crear arreglo de tamaño n.
    z = new float[n];

    cout << "Introduce el valor del valor medio (m): " << endl;
    cin >> m;
    cout << "Introduce el valor de sigma (sigma): " << endl;
    cin >> sigma;

    float r1 = rand() % 1;
    cout << "Número aleatorio R1: " << r1 << endl;
    float r2 = rand() % 1;
    cout << "Número aleatorio R2: " << r2 << endl;

    cout << "Xi:\n[ ";
	for(int i = 0; i < n; i++){
		cout << x[i] << " ";
	}
	cout << "]";

    return 0;
}

void dist_normal(int m, int sigma, int n){
    for(int i = 0; i < n; i++){
        z[i] = 1;
    }
}

void transformacion(int m, int sigma, int n){
    for(int i = 0; i < n; i++){
        x[i] = m + (sigma * z[i]);
    }
}