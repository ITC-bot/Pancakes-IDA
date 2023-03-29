#include <iostream>
#include <string>
#include <unordered_set>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;
float inf = std::numeric_limits<float>::infinity();

// Función que voltea los primeros k pancakes de la pila
void voltear(string& pancakes, int k) {
    int i = 0, j = k - 1;
    while (i < j) {
        char temp = pancakes[i];
        pancakes[i] = pancakes[j];
        pancakes[j] = temp;
        i++;
        j--;
    }
}

// Función que verifica si está ordenada
bool esta_ordenada(string pancakes) {
    for (int i = 1; i < pancakes.size(); i++) {
        if (pancakes[i] < pancakes[i-1]) {
            return false;
        }
    }
    return true;
}

// Función que genera los sucesores de una configuración
vector<string> generar_sucesores(string pancakes) {
    vector<string> sucesores;
    for (int i = 1; i <= pancakes.size(); i++) {
        string sucesor = pancakes;
        voltear(sucesor, i);
        sucesores.push_back(sucesor);
    }
    return sucesores;
}

// Función que genera una cadena aleatoria de caracteres que representen los pancakes a ordenar
string generar_caracteres_aleatorios(int n) {
    string pancakes = "";
    unordered_set<char> chars_set;
    srand(time(NULL));
    while (chars_set.size() < n) {
        char c = 'a' + rand() % 26;
        if (chars_set.find(c) == chars_set.end()) {
            chars_set.insert(c);
            pancakes += c;
        }
    }
    return pancakes;
}

// Función que implementa la heuristica
float h4(const string& pancakes, const string& target) {
    float c = 0;
    for (int i = 0; i < pancakes.size(); i++) {
        if (pancakes[i] != target[i])
            c++;
        if (i < pancakes.size()-1 && abs(pancakes[i]-pancakes[i+1]) > 1)
            c++;
    }
    return c;
}

// Función que implementa la búsqueda con IDA*
string ida_estrella(const string& pancakes, const string& target, float cost, float threshold, string path, int& nodos_visitados) {
    float f = cost + h4(pancakes, target);
    if (f > threshold) {
        return "inf";
    }
    if (esta_ordenada(pancakes)) {
        return pancakes;
    }
    string min_path = "inf";
    for (auto sucesor : generar_sucesores(pancakes)) {
        if (path.find(sucesor) != std::string::npos || cost + h4(sucesor, target) > threshold) {
            nodos_visitados++;
            continue;
        }
        float new_cost = cost + 1;
        string t = ida_estrella(sucesor, target, new_cost, threshold, path + sucesor + " ", nodos_visitados);
        if (t != "inf" && (min_path == "inf" || t.size() < min_path.size())) {
            min_path = t;
        }
    }
    return min_path;
}

int main() {
    int n;
    cout << "Ingrese el numero de caracteres de pancakes: ";
    cin >> n;
    string pancakes = generar_caracteres_aleatorios(n);
    cout << "Pila de pancakes original: " << pancakes << endl;
    string target = pancakes;
    sort(target.begin(), target.end());  // Pila objetivo ordenada
    float threshold = h4(pancakes, target);  // Umbral inicial
    int nodos_visitados = 0;
    while (true) {
        string ruta_movimiento = ida_estrella(pancakes, target, 0, threshold, "", nodos_visitados);
        if (ruta_movimiento == "inf") {
            // Si la ruta de movimiento mínima no fue encontrada, aumenta el umbral
            threshold++;
        } else {
            // Si se encontró la ruta de movimiento mínima, finaliza el ciclo
            cout << "Solucion encontrada : " << ruta_movimiento << endl;
            break;
        }
    }
    cout << "Numero de nodos visitados: " << nodos_visitados << endl;

    return 0;
}
