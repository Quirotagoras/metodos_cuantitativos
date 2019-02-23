// Compilar - g++ von_newman.cpp -o von
// Ejecutar - ./von

#include <iostream>
#include <math.h>
#include <string.h>
#define BASE 10
using namespace std;

int num_dig(int);

int main(){
    int n, m, in, contador = 0;
    string num, mitad;
    int base = 10;
    cout << "Introduce un número de 4 dígitos: ";
    cin >> n;
    if(num_dig(n) != 4){
        cout << "El número debe de ser de 4 dígitos." << endl;
        return 0;
    }
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

    cout << "\nIteraciones: " << contador << "." << endl;
    return 0;
}

int num_dig(int n){
    unsigned int number_of_digits = 0;
    do {
        ++number_of_digits; 
        n /= BASE;
    } while (n);
    return number_of_digits;
}