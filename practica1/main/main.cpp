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

int ejercicio26() {

    int a, b, c;
    cout << "Ingrese los tres lados del triangulo:" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a+b>c && a+c>b && b+c>a){
        if(a==b && b==c){
            cout << endl << "Se forma un triangulo equilatero." << endl;
        }
        else if (a == b || a==c || b==c){
            cout << endl << "Se forma un triangulo isoceles." << endl;
        }
        else{
            cout << endl << "Se forma un triangulo escaleno." << endl;
        }
    }
    else{
        cout << endl << "Las longitudes ingresadas no forman un triangulo." << endl;
    }
    return 0;
}

int ejercicio27() {

    int a, b, resultado;
    char operador;

    cout << "INGRESE NUMERO 1: ";
    cin >> a;

    cout << endl << "INGRESE OPERADOR: ";
    cin >> operador;
    if(operador != '+' && operador != '-' && operador != '*' && operador != '/'){
        cout << endl << "OPERADOR INVALIDO";
        return 0;
    }

    cout << endl << "INGRESE NUMERO 2: ";
    cin >> b;

    if (operador == '+'){
        resultado = a+b;
        cout << endl << "RESULTADO: " << resultado << endl;
    }
    else if (operador == '-'){
        resultado = a-b;
        cout << endl << "RESULTADO: " << resultado << endl;
    }
    else if (operador == '*'){
        resultado = a*b;
        cout << endl << "RESULTADO: " << resultado << endl;
    }
    else if (operador == '/'){
        resultado = a/b;
        cout << endl << "RESULTADO: " << resultado << endl;
    }
    return 0;
}

int ejercicio28(){

    int a;
    double pi = 0.0;
    double sign = -1.0;

    cout << endl << "Ingrese el numero de elementos que van a ser usados en la aproximacion: ";
    cin >> a;

    if (a <= 0){
        cout << endl << "Numeros mayores  a cero ";
    }

    for(int i=0; i<a; ++i){
        double elem = sign / (2*i+1);
        pi += elem;
        sign = -sign;
    }

    pi *= 4;
    cout << endl << "pi es aproximadamente: " << abs(pi) << endl;

    return 0;
}

int ejercicio29(){
    cout << "Piensa en un numero entre el 1 y el 100, lo voy a adivinar a continuacion." << endl;
    cout << endl << "Si el numero es mayor ingresa: '>' " << endl;
    cout << endl << "Si el numero es menor ingresa: '<' " << endl;
    cout << endl << "Si acerte el numero ingresa: '=' " << endl;

    int limsup = 100;
    int liminf = 0;
    int mitad;
    char simb = 'x';

    while (simb != '='){
        mitad = (limsup+liminf)/2;
        cout << endl << "El numero en el que estas pensando es?: " << mitad << endl;
        cin >> simb;
        while(simb != '<' && simb != '>' && simb != '='){
            cout << endl << "Ese simbolo es invalido, intenta nuevamente, es?: " << mitad << endl;
            cin >> simb;
        }

        if(simb == '<'){
            limsup = mitad;
        }
        else if(simb == '>'){
            liminf = mitad;
        }
        else{
            cout << endl << "He adivinado el numero, eso es todo " << endl;
        }
    }

    return 0;
}

int ejercicio30(){

    cout << "Voy a pensar en un numero entre el 0 y el 100, lo tendras que adivinar." << endl;
    int guess;
    bool band = true;
    srand(time(0));
    int secret = rand() % 101;

    while (band){
        cout << endl << "Introduce un numero entre 0 y 100." << endl;
        cin >> guess;
        while (guess<0 || guess>100) {
            cout << endl << "Numero fuera de rango, intente nuevamente." << endl;
            cin >> guess;
            }
        if(guess>secret){
            cout << endl << "Menor." << endl;
        }
        else if(guess < secret){
            cout << endl << "Mayor." << endl;
        }
        else{
            cout << endl << "Lo has adivinado, felicitaciones." << endl;
            band = false;
        }
    }
    return 0;
}

int main()
{
    ejercicio30();
}


