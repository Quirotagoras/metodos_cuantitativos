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

	cout << "\nIntroduce el nombre de la primer característica [ P(Xa/X) ]: ";
	getline(cin, c1_name);

	cout << "\nIntroduce el nombre de la segunda característica [ P(Xb/X) ]: ";
	getline(cin, c2_name);


	cout << "\nPorcentajes:\n";
	/* --- Primer categoría --- */
	cout << "Introduce el porcentaje de " << pa_name << " [ P(A)] : ";
	cin >> pa;

	// Primer característica
	cout << "\nIntroduce el porcentaje de " <<  c1_name << "/" << pa_name << " [ P(Aa/A) ]: ";
	cin >> paa;

	// Segunda característica
	cout << "\nIntroduce el porcentaje de " << c2_name << "/" <<  pa_name  << " [ P(Ab/A) ]: ";
	cin >> pab;


	/* --- Segunda categoría --- */
	cout << "\nIntroduce el porcentaje de " << pb_name << " [ P(B)] : ";
	cin >> pb;

	// Primer característica
	cout << "\nIntroduce el porcentaje de " << c1_name << "/" << pb_name << " [ P(Ba/B) ]: ";
	cin >> pba;

	// Segunda característica
	cout << "\nIntroduce el porcentaje de " << c2_name << "/" << pb_name << " [ P(Bb/B) ]: ";
	cin >> pbb;

	/* --- Cálculos y Resultados --- */
	float pa_aa = pa * paa, pa_ab = pa * pab;
	float pb_ba = pb * pba, pb_bb = pb * pbb;
	float pA = pa_aa + pb_ba, pB = pa_ab + pb_bb;

	cout << "\nResultados:" << endl;
	// Primer categoría
	cout << "Porcentaje de [ P(A) * P(Aa/A) ]: " << pa_aa << "." << endl;
	cout << "Porcentaje de [ P(A) * P(Ab/A) ]: " << pa_ab << "." << endl;
	cout << "Porcentaje total de " << pa_name << "[ P(A) ]: " << pA << "." << endl;

	// Segunda categoría
	cout << "Porcentaje de [ P(B) * P(Ba/B) ]: " << pb_ba << "." << endl;
	cout << "Porcentaje de [ P(B) * P(Bb/B) ]: " << pb_bb << "." << endl;
	cout << "Porcentaje total de " << pb_name << "[ P(B) ]: " << pB << "." << endl << endl;

	// Teorema de Bayes
	cout << "Porcentaje de " <<  pa_name << "/" << c1_name << " [ P(A/Aa) ]: " << pa_aa / pA << "." << endl;
	cout << "Porcentaje de " <<  pa_name << "/" << c2_name << " [ P(A/Ab) ]: " << pa_ab / pB << "." << endl;
	cout << "Porcentaje de " <<  pb_name << "/" << c1_name << " [ P(B/Ba) ]: " << pb_ba / pA << "." << endl;
	cout << "Porcentaje de " <<  pb_name << "/" << c2_name << " [ P(B/Bb) ]: " << pb_bb / pB << "." << endl;

	cout << endl;

	return 0;
}