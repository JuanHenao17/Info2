#ifndef CODI_DECODI_H
#define CODI_DECODI_H
#include <string>
using namespace std;

void programa(string nombre_archivo, string archivo_salida);
string codificacion_metodo2(string nombre_archivo, int semilla);
string decodificacion_metodo2(string nombre_archivo, int semilla);
string char2binario(string nombre_archivo);
void escribirArchivoBinario(const string &nombreArchivo, const string &contenido);
string leerArchivoPorCaracter(string nombreArchivo);
string binarioACaracteres(string binario);
void escribirArchivo(string nombreArchivo, string texto, bool limpiar);
string toBinaryString(const string& input);
string encodeBlock(string block, int blockNumber);
void encodeFile(const string& inputFileName, const string& outputFileName, int n);

#endif // CODI_DECODI_H
