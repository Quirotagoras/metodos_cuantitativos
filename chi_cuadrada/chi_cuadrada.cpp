// Compilar - g++ chi_cuadrada.cpp -o chi
// Ejecutar - ./chi

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

float calculo_chi(int, int);

float* d;
int* oi;

int main(){
    int num, n, ei, gl, count;
    float a = 0.05, x;
    string nombreAr;
    ifstream archivo;

    cout << "Introduce el nombre del archivo: ";
    cin >> nombreAr;

    cout << "Introduce el número de datos: ";
    cin >> num;

    d = new float[num]; // arreglo para los datos

    n = sqrt(num); // número de clases

    oi = new int[n]; // arreglo para las clases

    ei = num/n; // número de datos por clase

    gl = n - 1; // grados de libertad

    archivo.open(nombreAr);
    if(!archivo){
        cerr << "No se puede abrir el archivo " << nombreAr << endl;
        exit(1);
    }

    int i = 0;
    while (archivo >> x) {
        d[i] = x;
        i++;
    }

    sort(d, d + num); // ordenar datos

    // Imprimir datos
    /*cout << "Datos:\n[ ";
	for(int i = 0; i < num; i++){
		cout << d[i] << " ";
	}
	cout << "]" << endl;*/

    cout << "Grados de libertad: " << gl << "." << endl;

    archivo.close();
    return 0;
}

float calculo_chi(int n, int ei){
    float x;
    for(int i = 0; i < n; i++){
        x += pow((oi[i] - ei), 2)/ ei;
    }
    return x;
}
