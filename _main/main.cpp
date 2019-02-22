// Compilar - g++ main.cpp -o main
// Ejecutar - ./main

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include "metodos.h"

using namespace std;

double f(double);

int main(){
    bool exit = false;
    int op;

    while(!exit){
        cout << "Métodos Cuantitativos" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Estadística" << endl;
        cout << "2. Teorema de Bayes" << endl;
        cout << "3. Sumas de Riemann" << endl;
        cout << "4. Números aleatorios por medio del Cuadrado Medio" << endl;
        cout << "5. Números aleatorios por medio de Congruencia Lineal" << endl;
        cout << "6. Transformación directa para la Distribución Normal" << endl;
        cout << "7. Aceptación y rechazo para la Distribución Gamma" << endl;
        cout << "8. Prueba de Chi cuadrada" << endl;

        cout << "Opción: ";
        cin >> op;

        switch(op) {
            // Salir
            case 0 : {
                exit = true;
                cout << "Hasta luego." << endl << endl;
                break;
            }
            // Estadística
            case 1 : {
                int n;
                float* nums;

                cout << "Introduce el número de datos: ";
                cin >> n;
                if(n < 0){
                    cout << "El número de datos debe ser positivo." << endl;
                    break;
                }

                nums = new float[n];

                for(int i = 0; i < n; i++){
                    cout << "Introduce el dato número " << i+1 << ": ";
                    cin >> nums[i];
                }

                sort(nums, nums+n);
                cout << "\nDatos ordenados:\n[ ";
                for(int i = 0; i < n; i++){
                    cout << nums[i] << " ";
                }
                cout << "]";

                float p = promedio(n, nums);
                cout << "\n\nPromedio: " << p << "." << endl;
                float m = mediana(n, nums);
                cout << "Mediana: " << m << "." << endl;
                float mo = moda(n, nums);
                cout << "Moda: " << mo << "." << endl;
                float v = varianza(n, p, nums);
                cout << "Varianza: " << v << "." << endl;
                float s = desviacion(v);
                cout << "Desviación estándar: " << s << "." << endl;
                float o = oblicuidad(n, p, s, nums);
                cout << "Oblicuidad: " << o << "." << endl;
                float c = curtosis(n, p, s, nums);
                cout << "Curtosis: " << c << "." << endl << endl;

                delete [] nums;

                break;
            }
            // Teorema de Bayes
            case 2 : {
                float pa, paa, pab; // categoría #1, carac #1 de cateogoría #1, carac #2 de categoría #1.
	            float pb, pba, pbb; // categoría #2, carac #1 de cateogoría #2, carac #2 de categoría #2.

                cout << "Introduce el porcentaje de P(A): ";
	            cin >> pa;
                cout << "\nIntroduce el porcentaje de la primer característica [ P(A/Aa) ]: ";
	            cin >> paa;
                cout << "\nIntroduce el porcentaje de la segunda característica [ P(A/Aa) ]: ";
	            cin >> pab;

                cout << "\nIntroduce el porcentaje de P(B): ";
	            cin >> pb;
                cout << "\nIntroduce el porcentaje de la primer característica [ P(B/Ba) ]: ";
	            cin >> pba;
                cout << "\nIntroduce el porcentaje de la segunda característica [ P(B/Bb) ]: ";
	            cin >> pbb;

                float pa_aa = pa * paa, pa_ab = pa * pab;
	            float pb_ba = pb * pba, pb_bb = pb * pbb;
	            float pA = pa_aa + pb_ba, pB = pa_ab + pb_bb;

                cout << "\nResultados:" << endl;
                cout << "P(A) * P(A/Aa): " << pa_aa << "." << endl;
                cout << "P(A) * P(A/Ab): " << pa_ab << "." << endl;

                cout << "P(B) * P(B/Ba): " << pb_ba << "." << endl;
                cout << "P(B) * P(B/Bb): " << pb_bb << "." << endl;

                cout << "P(A/Aa): " << pa_aa / pA << "." << endl;
                cout << "P(A/Ab): " << pa_ab / pB << "." << endl;
                cout << "P(B/Ba): " << pb_ba / pA << "." << endl;
                cout << "P(B/Bb): " << pb_bb / pB << "." << endl << endl;

                break;
            }
            // Sumas de Riemann
            case 3 : {
                double a, b, n, sum;

                cout << "Introduce el límite izquierdo (a): ";
                cin >> a;

                cout << "\nIntroduce el límite derecho (b): ";
                cin >> b;

                cout << "\nIntroduce el número de partes (n): ";
                cin >> n;

                sum = area(f, a, b, n);
                cout << "Área de f: " << sum << endl << endl;

                break;
            }
            // Números aleatorios por Cuadrado Medio
            case 4 : {
                int n, iteraciones;

                cout << "Introduce un número de 4 dígitos: ";
                cin >> n;

                if(num_dig(n) != 4){
                    cout << "El número debe de ser de 4 dígitos." << endl << endl;
                    break;
                }

                iteraciones = cuadrado_medio(n);
                cout << "\nIteraciones: " << iteraciones << "." << endl << endl;
                break;
            }
            // Número aleatorios por Congruencia Lineal
            case 5 : {
                 int semilla, a, c, m, x, r, i = 0;

                cout << "Introduce la semilla: ";
                cin >> semilla;

                cout << "Introduce el valor del multiplicador (a): ";
                cin >> a;

                cout << "Introduce el valor del incremento (c): ";
                cin >> c;

                cout << "Introduce el valor del módulo (m): ";
                cin >> m;

                x = semilla;

                do {
                    x = ((a * x) + c) % m;
                    r = x/m;

                    cout << "X" << i << ": " << x << "." << endl;
                    cout << "R" << i << ": " << r << "." << endl;
                    i++;
                } while (x != semilla);

                cout << endl;

                break;
            }
            // Distribución Normal
            case 6 : {
                int m, sigma;

                cout << "\nIntroduce el valor medio (m): ";
                cin >> m;

                cout << "\nIntroduce el valor de sigma (sigma): ";
                cin >> sigma;

                float r1 = rand() % 1;
                cout << "\nNúmero aleatorio R1: " << r1 << endl;
                float r2 = rand() % 1;
                cout << "Número aleatorio R2: " << r2 << endl;

                dist_normal(m, sigma, r1, r2);

                break;
            }
            // Distribución Gamma
            case 7 : {
                int beta, th;

                cout << "Introduce el valor de Beta: ";
                cin >> beta;

                cout << "\nIntroduce el valor de Theta: ";
                cin >> th;

                float a = 1 / pow((2 * beta - 1), 1/2);
                float b = beta - log(4);

                float x = aceptacion_rechazo(a, b, beta);

                cout << "Media = " << 1/th << endl;
                cout << "Varianza = " << 1/(beta * pow(th, 2)) << endl;

                cout << "x = " << x << endl;
                cout << "x/(beta * theta) = " << (x/(beta * th)) << endl << endl;

                break;
            }
            // Chi cuadrada
            case 8 : {
                cout << "En proceso." << endl << endl;
                break;
            }
            default:{
                cout << "Introduce una opción válida" << endl << endl;
                break;
            }
        }
    }

    return 0;
}

double f(double x){
    return 2.0*x;
}