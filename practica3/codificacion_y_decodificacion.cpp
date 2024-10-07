#include <algorithm>
#include <iostream>
#include "codi_decodi.h"
# include <fstream>
# include <bitset>

using namespace std;

void programa(string nombre_archivo, string archivo_salida){

    unsigned short int semilla;
    unsigned short int seleccion_metodo;

    while(true){

        cout << "Ingrese la semilla de codificacion (numero entero mayor que 0)" << endl;
        cin >> semilla;

        do{
        cout << endl << "Ingrese 1 si quiere codifcar la informacion por el primer metodo." << endl;
        cout << "Ingrese 2 si quiere codifcar la informacion por el segundo metodo." << endl;
        cout << "Ingrese 3 si quiere decodifcar la informacion por el primer metodo." << endl;
        cout << "Ingrese 4 si quiere decodifcar la informacion por el segundo metodo." << endl;
        cout << "Ingrese 5 si quiere seleccionar otros archivos (salir)." << endl;
        cin >> seleccion_metodo;

        }while(seleccion_metodo!=1 && seleccion_metodo != 2 && seleccion_metodo != 3 && seleccion_metodo != 4 && seleccion_metodo != 5);

        if(seleccion_metodo==1){
            encodeFile(nombre_archivo, archivo_salida, semilla);
            cout << endl << "Archivo codificado correctamente por el primer metodo." << endl;
        }

        else if(seleccion_metodo==2){
            string codificadoStr = codificacion_metodo2(nombre_archivo, semilla);
            escribirArchivoBinario(archivo_salida, codificadoStr);
            cout << endl << "Archivo codificado correctamente por el segundo metodo." << endl;
        }
        else if(seleccion_metodo==3){

        }
        else if(seleccion_metodo==4){

            string decodificadoStr = decodificacion_metodo2(nombre_archivo, semilla);
            string decodificadoChar = binarioACaracteres(decodificadoStr);
            escribirArchivo(archivo_salida, decodificadoChar, true);
            cout << endl << "Archivo decodificado correctamente por el segundo metodo." << endl;
        }

        else if(seleccion_metodo==5){
            break;
        }
    }

}

string codificacion_metodo2(string nombre_archivo, int semilla){

    string bloque_codificado;
    string cadena_binaria;
    string codificado;

    cadena_binaria = char2binario(nombre_archivo); //lee contenido del archivo y lo convierte a binario string

    for(int i=0; i<cadena_binaria.length();i += semilla){
        string bloque = cadena_binaria.substr(i, semilla);
        int tamano_bloque = bloque.length();

        for(int j=0; j<tamano_bloque;j++){
            if (j == 0) {
                bloque_codificado += bloque[bloque.length() - 1]; // último a primero
            } else {
                bloque_codificado += bloque[j - 1]; // resto se desplaza
            }
        }
        codificado += bloque_codificado;
        bloque_codificado = "";
    }
    return codificado;
}

string decodificacion_metodo2(string nombre_archivo, int semilla){

    string decodificado;
    string bloque_decodificado;
    string strBinario_codificado = leerArchivoPorCaracter(nombre_archivo);

    for(int i=0; i<strBinario_codificado.length();i += semilla){
        string bloque = strBinario_codificado.substr(i, semilla);
        int tamano_bloque = bloque.length();

        for (int j = 0; j < tamano_bloque; j++) {
            if (j == tamano_bloque - 1) {
                bloque_decodificado += bloque[0];

            } else {

                bloque_decodificado += bloque[j + 1];
            }
        }

        decodificado += bloque_decodificado;
        bloque_decodificado = "";

    }

    return decodificado;
}

string char2binario(string nombre_archivo)
{
    ifstream archivo;
    try
    {
        archivo.open(nombre_archivo);
        if (!archivo.is_open())
        {
            cout << "Error al abrir el archivo\n";
            return "";
        }
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }

    char caracter;
    string str_binario;

    while (archivo.get(caracter))
    {
        bitset<8> binario(caracter);
        str_binario += binario.to_string();
    }
    archivo.close();

    return str_binario;
}

void escribirArchivoBinario(const string &nombreArchivo, const string &contenido) {
    ofstream archivo(nombreArchivo, ios::binary);  // Modo binario
    if (archivo.is_open()) {
        archivo.write(contenido.c_str(), contenido.size());  // Escribir binario
        archivo.close();
    } else {
        cout << "Error al abrir el archivo binario para escribir." << endl;
    }
}

string leerArchivoPorCaracter(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo\n";
        return "";
    }

    string contenido;
    char c;
    while (archivo.get(c))
    {
        contenido += c;
    }
    archivo.close();

    return contenido;
}

string binarioACaracteres(string binario) {
    string resultado;

    for (int i = 0; i < binario.length(); i += 8) {
        string byte = binario.substr(i, 8);
        char c = bitset<8>(byte).to_ulong();
        resultado += c;
    }
    return resultado;
}

void escribirArchivo(string nombreArchivo, string texto, bool limpiar)
{
    fstream archivo;
    if (limpiar) // Si limpiar es verdadero, se sobreescribe el archivo
    {
        archivo.open(nombreArchivo, ios::out | ios::trunc);
    }
    else // Si limpiar es falso, se agrega contenido al final del archivo
    {
        archivo.open(nombreArchivo, ios::out | ios::app);
    }

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo\n";
        return;
    }

    archivo << texto << endl;
    archivo.close();
}

string encodeBlock(string block, int blockNumber) {
    string encodedBlock;
    int count1 = count(block.begin(), block.end(), '1');
    int count0 = block.size() - count1;

    if (blockNumber == 1) {
        // Invertir todos los bits para el primer bloque
        for (int i=0;i<block.length();i++) {
            char bit = (block[i] == '1') ? '0' : '1';
            encodedBlock += bit;
        }
    } else {
        // Aplicar reglas basadas en los conteos de 1s y 0s
        if (count1 == count0) {
            // Invertir cada bit
            for (char &bit : encodedBlock) {
                bit = (bit == '1') ? '0' : '1';
            }
        } else if (count0 > count1) {
            // Invertir cada 2 bits
            for (size_t i = 0; i < encodedBlock.size(); i += 2) {
                if (i < encodedBlock.size()) {
                    encodedBlock[i] = (encodedBlock[i] == '1') ? '0' : '1';
                }
                if (i + 1 < encodedBlock.size()) {
                    encodedBlock[i + 1] = (encodedBlock[i + 1] == '1') ? '0' : '1';
                }
            }
        } else {
            // Invertir cada 3 bits
            for (size_t i = 0; i < encodedBlock.size(); i += 3) {
                for (size_t j = 0; j < 3 && (i + j) < encodedBlock.size(); ++j) {
                    encodedBlock[i + j] = (encodedBlock[i + j] == '1') ? '0' : '1';
                }
            }
        }
    }

    return encodedBlock;
}

void encodeFile(const string& inputFileName, const string& outputFileName, int n) {
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error: No se pudo abrir el archivo de entrada." << endl;
        return;
    }

    string binaryString = char2binario(inputFileName);
    string encodedString;
    int cont0s = 0;
    int cont1s = 0;

    for (size_t i = 0; i < binaryString.length(); i += n) {
        string block = binaryString.substr(i, n);



        int blockNumber = (i / n) + 1;
        encodedString += encodeBlock(block, blockNumber);
    }

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Error: No se pudo abrir el archivo de salida." << endl;
        return;
    }

    outputFile << encodedString;
    outputFile.close();
}
