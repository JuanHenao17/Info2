#include <iostream>
using namespace std;

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void fun_c_corregida(double a[], int n, double *promedio, double *suma);

int main()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "antes: ";
    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " " ;
    }

    cout << endl;

    fun_b(array, 10);
    cout << "despues: ";
    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }


    //Caso de prueba fun_c
    double promedio, suma;
    double *ap_promedio, *ap_suma;
    ap_promedio = &promedio;
    ap_suma = &suma;
    double arrayb[10] = {2.3, 4.5, 6.6, 12.1, 0.0, 1.0, 7.7, 7.7, 9.99, 3.4};

    fun_c_corregida(arrayb, 10, ap_promedio, ap_suma);
    cout << endl << "El promedio esperado es: 5.529" << endl;
    cout << "El promedio resultante es: " << promedio << endl;
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
