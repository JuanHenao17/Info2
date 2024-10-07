#include <iostream>
#include "codi_decodi.h"

using namespace std;

int main()
{
    string archivo;
    string archivo_salida;
    int opcion;

    while(true){
        cout << "Este programa va a codificar/decodificar informacion.";
        cout << " Si no desea hacer nada oprima '0', si desea avanzar oprima cualquier otro numero." << endl;
        cin >> opcion;

        if(opcion == 0){
            break;
        }

        else{
        cout << "Ingrese el nombre del archivo fuente." << endl;
        cin >> archivo;

        cout << "Ingrese el nombre del archivo de salida." << endl;
        cin >> archivo_salida;

        programa(archivo, archivo_salida);
        }
    }

}
