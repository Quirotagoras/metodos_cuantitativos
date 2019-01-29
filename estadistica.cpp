// Compilar - g++ estadistica.cpp -o estadistica
// Ejecutar - ./estadistica

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

float* nums; // Arreglo dinámico de datos.

// Definición de métodos
float promedio(int n);
float mediana(int n);
float moda(int n);
float varianza(int n, float p);
float desviacion(float v);
float oblicuidad(int n, float p, float s);
float curtosis(int n, float p, float s);


int main(){
	int n; // número de datos.

	cout << "Introduce el número de datos: ";
	cin >> n;
	if(n < 0){
		cout << "El número de datos debe ser positivo.\n";
		return 0;
	}

	nums = new float[n]; // Crear arreglo de tamaño n.

	for(int i = 0; i < n; i++){
		cout << "Introduce el dato número " << i+1 << ": ";
		cin >> nums[i];
	}

	std::sort(nums, nums+n);
	cout << "\nDatos ordenados:\n[ ";
	for(int i = 0; i < n; i++){
		cout << nums[i] << " ";
	}
	cout << "]";

	float p = promedio(n);
	cout << "\n\nPromedio: " << p << ".\n";
	float m = mediana(n);
	cout << "Mediana: " << m << ".\n";
	float mo = moda(n);
	cout << "Moda: " << mo << ".\n";
	float v = varianza(n, p);
	cout << "Varianza: " << v << ".\n";
	float s = desviacion(v);
	cout << "Desviación estándar: " << s << ".\n";
	float o = oblicuidad(n, p, s);
	cout << "Oblicuidad: " << o << ".\n";
	float c = curtosis(n, p, s);
	cout << "Curtosis: " << c << ".\n";

	delete [] nums;

	cout << "\n";

	return 0;
}

float promedio(int n){
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += nums[i];
	}

	return sum/n;
}

float mediana(int n){
	if(n % 2 == 0){
		return (nums[(n-1)/2] + nums[n/2])/2;
	}
	return nums[n/2];
}

float moda(int n){
	float num = nums[0], moda = num;
	float cont = 1, contModa = 1;

	for(int i = 0; i < n; i++){
		if(nums[i] == num){
			++cont;
		}else{
			if(cont > contModa){
				contModa = cont;
				moda = cont;
			}
			cont = 1;
			num = nums[i];
		}
	}
	
	return moda;
}

float varianza(int n, float p){
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += pow((nums[i] - p), 2);
	}

	return sum/n;
}

float desviacion(float v){
	return sqrt(v);
}

float oblicuidad(int n, float p, float s){
	float sum = 0;
	float s3 = pow(s, 3);
	for(int i = 0; i < n; i++){
		sum += pow((nums[i] - p), 3);
	}

	return sum/(n*s3);
}

float curtosis(int n, float p, float s){
	float sum = 0;
	float s4 = pow(s, 4);
	for(int i = 0; i < n; i++){
		sum += pow((nums[i] - p), 4);
	}

	return (sum/(n*s4)) - 3;
}