#include <iostream>
using namespace std;

// Defiinción de tipo.
typedef double(*FUNC)(double);
// Definición de métodos.
double f(double);
double area(FUNC, double, double, double=50); // Función que recibe otra función (FUNC).

int main(){
    double a, b, sum;
    cout << "Introduce el límite izquierdo (a): ";
	cin >> a;

    cout << "\nIntroduce el límite derecho (b): ";
	cin >> b;

    cout << "\nIntroduce el número de partes (n): ";
	cin >> a;

    sum = area(f, a, b, n);
    cout << "Área de f: " << sum << endl;

    return 0;
}

double area(FUNC f, double a, double b, double n){
    double dx = (b - a)/n;
    double sum(0.0);
    double x = a;
    while (x <= b){
        sum += f(x)*dx;
        x += dx;
    }
    return sum;
}

double f(double x){
    return 2.0*x;
}