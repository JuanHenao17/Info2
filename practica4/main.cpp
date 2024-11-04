#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Enrutador {
public:
    string nombre;
    unordered_map<string, int> tablaDeRutas; // Mapa de destino a costo

    Enrutador(string nombre) : nombre(nombre) {}

    void agregarRuta(const string& destino, int costo) {
        tablaDeRutas[destino] = costo;
    }

    void mostrarTabla() {
        cout << "Tabla de enrutamiento para " << nombre << ":\n";
        for (const auto& ruta : tablaDeRutas) {
            cout << "Destino: " << ruta.first << ", Costo: " << ruta.second << endl;
        }
    }

    const unordered_map<string, int>& obtenerTabla() const {
        return tablaDeRutas;
    }
};

class Red {
private:
    vector<Enrutador> enrutadores;

public:
    void agregarEnrutador(const string& nombre) {
        enrutadores.emplace_back(nombre);
    }

    void removerEnrutador(const string& nombre) {
        enrutadores.erase(remove_if(enrutadores.begin(), enrutadores.end(),
                                    [&nombre](const Enrutador& e) { return e.nombre == nombre; }), enrutadores.end());
    }

    void actualizarRuta(const string& origen, const string& destino, int costo) {
        for (auto& enrutador : enrutadores) {
            if (enrutador.nombre == origen) {
                enrutador.agregarRuta(destino, costo);
            }
        }
    }

    void cargarTopologiaDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        string linea;
        while (getline(archivo, linea)) {
            istringstream iss(linea);
            string origen, destino;
            int costo;
            if (iss >> origen >> destino >> costo) {
                actualizarRuta(origen, destino, costo);
                actualizarRuta(destino, origen, costo); // Suponiendo conexión bidireccional
            }
        }
    }

    int costoEnvio(const string& origen, const string& destino) {
        for (const auto& enrutador : enrutadores) {
            if (enrutador.nombre == origen) {
                auto it = enrutador.tablaDeRutas.find(destino);
                if (it != enrutador.tablaDeRutas.end()) {
                    return it->second;
                }
            }
        }
        return -1; // Ruta no encontrada
    }

    void mostrarRed() {
        for (auto& enrutador : enrutadores) {
            enrutador.mostrarTabla();
        }
    }

    vector<string> caminoMasCorto(const string& origen, const string& destino) {
        unordered_map<string, int> costos;
        unordered_map<string, string> predecesores;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        for (const auto& enrutador : enrutadores) {
            costos[enrutador.nombre] = numeric_limits<int>::max();
        }
        costos[origen] = 0;
        pq.push({0, origen});

        while (!pq.empty()) {
            auto [costoActual, actual] = pq.top();
            pq.pop();

            if (actual == destino) break;

            for (const auto& [vecino, costo] : enrutadores[0].obtenerTabla()) { // Suponiendo que el primer enrutador tiene la tabla de todos
                int nuevoCosto = costoActual + costo;
                if (nuevoCosto < costos[vecino]) {
                    costos[vecino] = nuevoCosto;
                    predecesores[vecino] = actual;
                    pq.push({nuevoCosto, vecino});
                }
            }
        }

        vector<string> camino;
        for (string at = destino; at != ""; at = predecesores[at]) {
            camino.push_back(at);
        }
        reverse(camino.begin(), camino.end());
        return camino;
    }

    void generarRedAleatoria(int numEnrutadores, int costoMaximo) {
        srand(time(nullptr));
        for (int i = 0; i < numEnrutadores; ++i) {
            agregarEnrutador("Enrutador" + to_string(i + 1));
        }
        for (int i = 0; i < numEnrutadores; ++i) {
            for (int j = i + 1; j < numEnrutadores; ++j) {
                int costo = rand() % costoMaximo + 1;
                actualizarRuta("Enrutador" + to_string(i + 1), "Enrutador" + to_string(j + 1), costo);
                actualizarRuta("Enrutador" + to_string(j + 1), "Enrutador" + to_string(i + 1), costo);
            }
        }
    }
};

int main() {
    Red red;

    // Cargar topología desde un archivo
    red.cargarTopologiaDesdeArchivo("topologia.txt"); // tener el archivo

    // Mostrar la red
    red.mostrarRed();

    // Costo de envío
    cout << "Costo de enviar de Enrutador1 a Enrutador3: " << red.costoEnvio("Enrutador1", "Enrutador3") << endl;

    // Obtener camino más corto
    vector<string> camino = red.caminoMasCorto("Enrutador1", "Enrutador3");
    cout << "Camino más corto de Enrutador1 a Enrutador3: ";
    for (const string& enrutador : camino) {
        cout << enrutador << " ";
    }
    cout << endl;

    return 0;
}
