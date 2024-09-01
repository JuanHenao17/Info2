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

int ejercicio9() {

    const float pi = 3.1416;
    int a;

    cout << "Ingrese el radio del circulo:" << endl;
    cin >> a;

    float perimetro = 2*pi*a;
    float area = pi * a * a;

    cout << endl << "Perimetro: " << perimetro << endl;
    cout << endl << "Area: " << area << endl;

    return 0;
}

int ejercicio10(){

    int a;

    do{
        cout << "Ingrese un numero entre 1 y 100:" << endl;
        cin >> a;

    }while(a>100);

    for (int i = 1; i <= 100; ++i) {
        if (i%a == 0){
            cout << endl << i << endl;}

    }

    return 0;
}

int ejercicio21(){

    char letra;
    cout << "Ingrese una letra: " << endl;
    cin >> letra;
    if (isupper(letra)){
        letra = tolower(letra); }
    else{
        letra = toupper(letra);
    }

    cout << endl << "Letra convertida: " << letra << endl;

    return 0;
}

int ejercicio22(){

    int segs, horas, mins;
    cout << "Ingrese una cantidad de segundos: " << endl;
    cin >> segs;

    horas = segs/3600;
    segs -= (3600*horas);

    mins = segs/60;
    segs -= (60*mins);

    cout << endl << horas << ":" << mins << ":" << segs << endl;

    return 0;
}

int ejercicio23() {

    int a, b, mcd;
    cout << "Ingrese dos numeros:" << endl;
    cin >> a;
    cin >> b;

    for (int i = 1; i <= a; ++i) {
        if (a%i == 0){
            if (b%i == 0){
                mcd = i;}
        }
    }

    int mcm = (a*b)/mcd;
    cout << endl << "El MCM de " << a << " y " << b << " es: " << mcm << endl;

    return 0;
}

int ejercicio24() {

    int fila;
    cout << "Ingrese un numero:" << endl;
    cin >> fila;
    int espacios = fila - 2;
    cout << endl;

    for(int i = 0; i < fila; ++i){
        cout << "+";
    }
    cout << endl;

    for (int i = 0; i < espacios; ++i){
        cout << "+";
        for (int j = 0; j < espacios; ++j){
            cout << " ";
        }
        cout << "+";
        cout << endl;
    }

    for(int i = 0; i < fila; ++i){
        cout << "+";
    }

    return 0;
}

int ejercicio25() {

    long long int a;
    cout << "Ingrese un numero:" << endl;
    cin >> a;
    int cont = 0;

    if(a==0){
        cout << endl << "0 tiene un digito." << endl;
        return 0;
    }

    while (a>0) {
        a /= 10;
        cont++;

    }
    cout << endl << "Tiene " << cont << " digitos." << endl;
    return 0;
}

int main()
{
    ejercicio25();
}


