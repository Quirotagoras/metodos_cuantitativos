// Compilar - g++ bayes.cpp -o bayes
// Ejecutar - ./bayes

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	float pa, paa, pab; // primer categoría, carac #1 de primer cateogoría, carac #2 de primer categoría.
	float pb, pba, pbb; // segunda categoría, carac #1 de segunda cateogoría, carac #2 de segunda categoría.
	string pa_name, pb_name, c1_name, c2_name; // nombres de categorías y características.

	cout << "Nombres:\n";

	cout << "Introduce el nombre de la primer categoría [ P(A) ]: ";
	getline(cin, pa_name);

	cout << "\nIntroduce el nombre de la segunda categoría [ P(B) ]: ";
	getline(cin, pb_name);

	cout << "\nIntroduce el nombre de la primer característica [ P(X/Xa) ]: ";
	getline(cin, c1_name);

	cout << "\nIntroduce el nombre de la segunda característica [ P(X/Xb) ]: ";
	getline(cin, c2_name);


	cout << "\nPorcentajes:\n";
	/* --- Primer categoría --- */
	cout << "Introduce el porcentaje de " << pa_name << " [ P(A)] : ";
	cin >> pa;

	// Primer característica
	cout << "\nIntroduce el porcentaje de " << c1_name << "/" << pa_name << " [ P(A/Aa) ]: ";
	cin >> paa;

	// Segunda característica
	cout << "\nIntroduce el porcentaje de " << c2_name << "/" << pa_name << " [ P(A/Aa) ]: ";
	cin >> pab;


	/* --- Segunda categoría --- */
	cout << "\nIntroduce el porcentaje de " << pb_name << " [ P(B)] : ";
	cin >> pb;

	// Primer característica
	cout << "\nIntroduce el porcentaje de " << c1_name << "/" << pb_name << " [ P(B/Ba) ]: ";
	cin >> pba;

	// Segunda característica
	cout << "\nIntroduce el porcentaje de " << c2_name << "/" << pb_name << " [ P(B/Bb) ]: ";
	cin >> pbb;

	/* --- Cálculos y Resultados --- */
	float pa_aa = pa * paa, pa_ab = pa * pab;
	float pb_ba = pb * pba, pb_bb = pb * pbb;
	float pA = pa_aa + pb_ba, pB = pa_ab + pb_bb;

	cout << "\nResultados:";
	cout << "\nPorcentaje de [ P(A) * P(A/Aa) ]: " << pa_aa << ".";
	cout << "\nPorcentaje de [ P(A) * P(A/Ab) ]: " << pa_ab << ".";

	cout << "\nPorcentaje de [ P(B) * P(B/Ba) ]: " << pb_ba << ".";
	cout << "\nPorcentaje de [ P(B) * P(B/Bb) ]: " << pb_bb << ".";

	cout << "\n\nPorcentaje de " <<  pa_name << "/" << c1_name << " [ P(A/Aa) ]: " << pa_aa / pA << ".";
	cout << "\nPorcentaje de " <<  pa_name << "/" << c2_name << " [ P(A/Ab) ]: " << pa_ab / pB << ".";
	cout << "\nPorcentaje de " <<  pb_name << "/" << c1_name << " [ P(B/Ba) ]: " << pb_ba / pA << ".";
	cout << "\nPorcentaje de " <<  pb_name << "/" << c2_name << " [ P(B/Bb) ]: " << pb_bb / pB << ".";

	cout << "\n";
	return 0;
}