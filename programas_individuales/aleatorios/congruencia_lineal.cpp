// Compilar - g++ congruencia_lineal.cpp -o cl
// Ejecutar - ./cl

#include <iostream>
using namespace std;

int main(){
    int semilla, a, c, m, x, i = 0;
    float r;

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

    do {
        x = ((a * x) + c) % m;
        r = (float)x/m;

        cout << "[ X_" << i + 1 << ": " << x << ". R_" << i + 1 << ": " << r << " ]." << endl;
        i++;
    } while (x != semilla);

    return 0;
}