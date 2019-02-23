#include <math.h>
#include <string.h>

#define PI 3.14159265
#define BASE 10

using namespace std;

struct Point{
    float x, y;

    Point(): x(0), y(0){}
    Point(float x, float y): x(x), y(y){}
};

// Estadística
float promedio(int n, float* nums){
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += nums[i];
	}

	return sum/n;
}

float mediana(int n, float* nums){
	if(n % 2 == 0){
		return (nums[(n-1)/2] + nums[n/2])/2;
	}
	return nums[n/2];
}

float moda(int n, float* nums){
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

float varianza(int n, float p, float* nums){
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += pow((nums[i] - p), 2);
	}

	return sum/n;
}

float desviacion(float v){
	return sqrt(v);
}

float oblicuidad(int n, float p, float s, float* nums){
	float sum = 0;
	float s3 = pow(s, 3);
	for(int i = 0; i < n; i++){
		sum += pow((nums[i] - p), 3);
	}

	return sum/(n*s3);
}

float curtosis(int n, float p, float s, float* nums){
	float sum = 0;
	float s4 = pow(s, 4);
	for(int i = 0; i < n; i++){
		sum += pow((nums[i] - p), 4);
	}

	return (sum/(n*s4)) - 3;
}

// Teorema de Bayes
void bayes(float pa, float paa,  float pab,  float pb, float pba, float pbb, string pa_name, string pb_name, string c1_name, string c2_name){
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
}

// Cuadrado Medio
int num_dig(int n){
    unsigned int number_of_digits = 0;
    do {
        ++number_of_digits; 
        n /= BASE;
    } while (n);
    return number_of_digits;
}

int cuadrado_medio(int n){
    int m, in, contador = 0;
    string num, mitad;

    in = n;
    m = n;
    do{
        n = pow(m, 2);
        num = to_string(n);
        if(num_dig(n)%2 == 0){
            mitad = num.substr(2, 4);
        }else{
            mitad = num.substr(1, 4);
        }
        m = stoi(mitad);
        cout << "N: " << n << " Inicial: " << in << " M: " << m << endl;
        contador++;
    }while(in != m && m > 0);

    return contador;
}

// Distribución Normal
void transformacion(int m, int sigma, float z1, float z2){
    float x1, x2;

    x1 = m + (sigma * z1);
    x2 = m + (sigma * z2);

    cout << "X1 = " << x1 << endl;
    cout << "X2 = " << x2 << endl;
}

void dist_normal(int m, int sigma, float r1, float r2){
    float ln, cs, z1, z2;

    ln = -2 * log(r1);
    cs = cos(2 * PI * (r2 * PI / 180));

    z1 = (pow(ln, 1/2)) * cs;
    z2 = (pow(ln, 1/2)) * cs;

    transformacion(m, sigma, z1, z2);
}

// Distribución Gamma
float aceptacion_rechazo(float a, float b, int beta){
    float r1, r2, v, x, op;
    bool bandera = false;
    do{
        r1 = rand() % 1;
        cout << "Número aleatorio R1: " << r1 << endl;
        r2 = rand() % 1;
        cout << "Número aleatorio R2: " << r2 << endl;
        v = r1/(1 - r1);
        x = beta * pow(v, a);

        op = b + (((beta * a) + 1) * log (v)) - log(pow(r1, 2) * r2);
        if(x <= op){
            bandera = true;
        }
    } while(!bandera);

    return x;
}

// Contar bajo la curva
int contar_bajo_curva(unsigned int N, int pw, Point *points){
    int contador = 0;
    float op;
    for(int i = 0; i < N; i++){
        //op = pow((1 - pow(points[i].y, pw)), 1/pw);
        op = pow(points[i].x, pw) + pow(points[i].y, pw);
        if(op < 1){
            contador++;
        }
    }
    return contador;
}

// Chi cuadrada
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