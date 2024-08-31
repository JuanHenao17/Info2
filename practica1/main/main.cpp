#include <iostream>

using namespace std;

int ejercicio1(){
    int a, b;
    cout << "Ingrese dos numeros:" << endl;
    cin >> a;
    cin >> b;

    if (b == 0) {
        cout << endl << "Error: El divisor no puede ser cero." << endl;
        return 1;
    }

    int c = a%b;
    cout << endl << "El residuo de la division " << a << "/" << b << " es: " << c << endl;
    return 0;
}

int ejercicio2(){
    int a;
    cout << "Ingrese un numero:" << endl;
    cin >> a;
    if (a%2 == 0) {
        cout << endl << a << " es par." << endl;
    }
    else {
        cout << endl << a << " es impar." << endl;
    }
    return 0;
}

int ejercicio3(){

    int a, b;
    cout << "Ingrese dos numeros:" << endl;
    cin >> a;
    cin >> b;

    if (a == b) {
        cout << endl << a << " es igual a " << b << endl;
    }
    else if (a>b) {
        cout << endl << a << " es mayor que " << b << endl;
    }
    else{
        cout << endl << b << " es mayor que " << a << endl;
    }
    return 0;
}

int ejercicio4(){

    int a, b;
    cout << "Ingrese dos numeros:" << endl;
    cin >> a;
    cin >> b;

    if (a == b) {
        cout << endl << a << " es igual a " << b << endl;
    }
    else if (a>b) {
        cout << endl << b << " es menor que " << a << endl;
    }
    else{
        cout << endl << a << " es menor que " << b << endl;
    }
    return 0;
}

int ejercicio5() {

    int a, b;
    cout << "Ingrese dos numeros:" << endl;
    cin >> a;
    cin >> b;

    int c = a/b;
    cout << endl << a << "/" << b << " = " << c << endl;
    return 0;
}

int ejercicio6() {

    int a, b, total = 1;
    cout << "Ingrese dos numeros:" << endl;
    cin >> a;
    cin >> b;

    for (int i=0; i<b; ++i) {
        total *= a;
    }

    cout << endl << a << "∧" << b << " = " << total << endl;

    return 0;
}

int ejercicio7() {

    int a, total = 0;
    cout << "Ingrese un numero:" << endl;
    cin >> a;
    int aux = a;
    for(int i=0; i<a; ++i) {
        total += aux;
        --aux;
    }
    cout << endl << "La sumatoria desde 0 hasta " << a << " es " << total << endl;
    return 0;
}

int ejercicio8() {

    int a;
    long long total = 1;
    cout << "Ingrese un numero:" << endl;
    cin >> a;
    int aux = a;
    for(int i=0; i<a; ++i) {
        total *= aux;
        --aux;
    }
    cout << endl << a << "! = " << total << endl;
    return 0;
}

int main()
{
    ejercicio8();
}

