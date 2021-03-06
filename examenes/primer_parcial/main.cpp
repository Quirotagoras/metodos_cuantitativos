// Compilar - g++ main.cpp -o main
// Ejecutar - ./main

#include <iostream>
#include <algorithm>
#include "metodos.h"

using namespace std;

float* val;

int main(){
    bool exit = false;
    int op;

    while(!exit){
        cout << "Métodos Cuantitativos" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Estadística" << endl;
        cout << "2. Teorema de Bayes" << endl;
        cout << "3. Números aleatorios por medio del Cuadrado Medio" << endl;
        cout << "4. Números aleatorios por medio de Congruencia Lineal" << endl;
        cout << "5. Transformación directa para la Distribución Normal" << endl;
        cout << "6. Aceptación y rechazo para la Distribución Gamma" << endl;
        cout << "7. Contar puntos bajo la curva" << endl;
        cout << "8. Prueba de Chi cuadrada (Correr primero la Congruencia Lineal)" << endl;

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
                float pa, paa, pab;
                float pb, pba, pbb;
                string pa_name, pb_name, c1_name, c2_name;

                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

                cout << "Nombres:" << endl;

                cout << "Introduce el nombre de la primer categoría [ P(A) ]: ";
                getline(cin, pa_name);

                cout << "\nIntroduce el nombre de la segunda categoría [ P(B) ]: ";
                getline(cin, pb_name);

                cout << "\nIntroduce el nombre de la primer característica [ P(Xa/X) ]: ";
                getline(cin, c1_name);

                cout << "\nIntroduce el nombre de la segunda característica [ P(Xb/X) ]: ";
                getline(cin, c2_name);


                cout << "\nPorcentajes:" << endl;
                cout << "Introduce el porcentaje de " << pa_name << " [ P(A)] : ";
                cin >> pa;
                cout << "\nIntroduce el porcentaje de " <<  c1_name << "/" << pa_name << " [ P(Aa/A) ]: ";
                cin >> paa;
                cout << "\nIntroduce el porcentaje de " << c2_name << "/" <<  pa_name  << " [ P(Ab/A) ]: ";
                cin >> pab;

                cout << "\nIntroduce el porcentaje de " << pb_name << " [ P(B)] : ";
                cin >> pb;
                cout << "\nIntroduce el porcentaje de " << c1_name << "/" << pb_name << " [ P(Ba/B) ]: ";
                cin >> pba;
                cout << "\nIntroduce el porcentaje de " << c2_name << "/" << pb_name << " [ P(Bb/B) ]: ";
                cin >> pbb;

                bayes(pa, paa, pab, pb, pba, pbb, pa_name, pb_name, c1_name, c2_name);

                break;
            }
            // Números aleatorios por Cuadrado Medio
            case 3 : {
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
            case 4 : {
                 int semilla, a, c, n, m, x, i = 0;
                 float r;

                cout << "Introduce el número de valores: ";
                cin >> n;

                cout << "Introduce la semilla: ";
                cin >> semilla;

                cout << "Introduce el valor del multiplicador (a): ";
                cin >> a;

                cout << "Introduce el valor del incremento (c): ";
                cin >> c;

                cout << "Introduce el valor del módulo (m): ";
                cin >> m;

                cout << endl;

                x = semilla;

                val = new float[n];

                for (int i = 0; i < n; i++){
                    x = ((a * x) + c) % m;
                    r = (float)x/(float)m;

                    cout << "[ X_" << i + 1 << ": " << x << ". R_" << i + 1 << ": " << r << " ]." << endl;
                    val[i] = r;
                }

                cout << endl;

                break;
            }
            // Distribución Normal
            case 5 : {
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
            case 6 : {
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
            // Contar bajo la curva
            case 7: {
                unsigned int N;
                int n, pw, A = 1;
                Point* points;

                float r1, r2;

                cout << "Introduce el número de puntos a generar: ";
                cin >> N;

                cout << "Introduce el exponente: ";
                cin >> pw;

                points = new Point[N];

                for(int i = 0; i < N; i++){
                    r1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                    r2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                    points[i] = Point(r1, r2);
                }

                n = contar_bajo_curva(N, pw, points);

                cout << "Puntos bajo la curva: " << n << endl;

                cout << "n/N = " << (float)n/N << endl << endl;

                delete [] points;

                break;
            }
            // Chi cuadrada
            case 8 : {
                int num, n, ei, gl, count;
                int* oi;
                float a, x, chi;
                
                cout << "Introduce el número de datos: ";
                cin >> num;

                cout << "Introduce el nivel de confianza: ";
                cin >> a;
                
                n = sqrt(num);

                oi = new int[n];

                ei = num/n;
                gl = n - 1;

                sort(val, val + num);

                llenar_clases(val, oi, num, n);

                chi = calculo_chi(oi, n, ei);

                cout << endl << "Clases:\n[ ";
                for(int i = 0; i < n; i++){
                    cout << oi[i] << " ";
                }
                cout << "]" << endl;

                cout << endl << "Chi cuadrada: " << chi << "." << endl;
                cout << "Nivel de confianza: " << a << "." << endl;
                cout << "Grados de libertad: " << gl << "." << endl << endl;

                delete [] oi;

                break;
            }
            default:{
                cout << "Introduce una opción válida" << endl << endl;
                break;
            }
        }
    }

    delete [] val;

    return 0;
}