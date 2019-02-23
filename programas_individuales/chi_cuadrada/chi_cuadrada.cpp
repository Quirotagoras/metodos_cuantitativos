// Compilar - g++ chi_cuadrada.cpp -o chi
// Ejecutar - ./chi

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

void llenar_clases(float*, int*, int, int);
float calculo_chi(int*, int, int);

float* d;
int* oi;

int main(){
    int num, n, ei, gl, count;
    float a, x, chi;
    string nombreAr;
    ifstream archivo;

    cout << "Introduce el nombre del archivo: ";
    cin >> nombreAr;

    cout << "Introduce el número de datos: ";
    cin >> num;

    cout << "Introduce el nivel de confianza: ";
    cin >> a;

    d = new float[num]; // arreglo para los datos

    n = sqrt(num); // número de clases

    oi = new int[n]; // arreglo para las clases

    ei = num/n; // número esperado en la iésima clase

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

    llenar_clases(d, oi, num, n);

    chi = calculo_chi(oi, n, ei);

    // Imprimir datos
    /*cout << "Datos:\n[ ";
	for(int i = 0; i < num; i++){
		cout << d[i] << " ";
	}
	cout << "]" << endl;*/

    // Imprimir clases
    cout << "Clases:\n[ ";
	for(int i = 0; i < n; i++){
		cout << oi[i] << " ";
	}
	cout << "]" << endl;

    cout << "Chi cuadrada: " << chi << "." << endl;
    cout << "Nivel de confianza: " << a << "." << endl;
    cout << "Grados de libertad: " << gl << "." << endl;

    archivo.close();
    delete [] d;
    delete [] oi;

    return 0;
}

void llenar_clases(float *d, int *oi, int num, int n){
    int count, j = 0;
    float paso = 1/(float)n, start = 0.0, end = paso;
    for(int i = 0; i < n; i++){
        count = 0;

        while(d[j] >= start && d[j] < end && j <= num){
            count++;
            j++;
        }

        oi[i] = count;
        start = end;
        end += paso;
    }
}

float calculo_chi(int *oi, int n, int ei){
    float x;
    for(int i = 0; i < n; i++){
        x += pow((oi[i] - ei), 2)/ ei;
    }
    return x;
}
