#include <iostream>
#include <string>
using namespace std;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void fun_c_corregida(double a[], int n, double *promedio, double *suma);
void problema2();
void problema6();

int main()
{

    //Caso de prueba fun_c
    double promedio, suma;
    double *ap_promedio, *ap_suma;
    ap_promedio = &promedio;
    ap_suma = &suma;
    double arrayb[10] = {2.3, 4.5, 6.6, 12.1, 0.0, 1.0, 7.7, 7.7, 9.99, 3.4};

    fun_c_corregida(arrayb, 10, ap_promedio, ap_suma);
    cout << endl << "El promedio esperado es: 5.529" << endl;
    cout << "El promedio resultante es: " << promedio << endl;

    problema6();

}

void fun_a(int *px,int*py){ int
    tmp = *px;
    *px = *py;
    *py = tmp;
}

void fun_b(int a[], int tam){
    int f, l;
    int *b = a;
    for (f = 0, l = tam -1; f < l; f++, l--) {
        fun_a(&b[f], &b[l]);
    }
}

void fun_c_corregida(double a[], int n, double *promedio, double *suma){
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++){
        *suma += *(a + i);
    }
    *promedio = *suma / n;
}

void problema2(){

    srand(time(0));
    const int tam = 200;
    char letras[tam];

    for(int i=0; i<tam; i++){
        letras[i] = 'A' + rand() % 26;
    }

    for(int i=0; i<tam; i++){
        cout << letras[i];
    }

     cout << endl;

    int cont[26]={0};

     for(int i=0; i<tam; i++){
         cont[letras[i]-'A']++;
    }

    for (int i = 0; i < 26; ++i){
        cout << char('A' + i) << ": " << cont[i] << endl;
        }
}

void problema6(){

    string cadena;

    cout << "Introduzca la cadena de caracteres: " << endl;
    getline(cin, cadena);

    string copia = cadena;
    for(int i=0; i< cadena.length(); i++){
        if (copia[i] >= 'a' && copia[i] <= 'z'){
            copia[i] = toupper(copia[i]);
        }
    }

    cout << endl << "Original: " << cadena << endl;
    cout << "En mayuscula: " << copia << endl;

}
