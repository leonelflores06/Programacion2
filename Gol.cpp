#include <iostream>
#include <cstring>
#include "gol.h"

using namespace std;

void Gol::cargar() {
    cout << "Numero de partido: ";
    cin >> numeroPartido;
    cout << "DNI del jugador: ";
    cin >> dniJugador;
    cout << "Tipo de gol (1: Penal, 2: Tiro libre, 3: Jugada): ";
    cin >> tipoGol;
}

void Gol::mostrar() const {
    cout << "Partido: " << numeroPartido << endl;
    cout << "Jugador (DNI): " << dniJugador << endl;
    cout << "Tipo de gol: ";
    switch(tipoGol) {
        case 1: cout << "Penal"; break;
        case 2: cout << "Tiro libre"; break;
        case 3: cout << "Jugada"; break;
        default: cout << "Desconocido";
    }
    cout << endl;
}

void Gol::guardarGol()const {
    FILE* p = fopen("goles.dat", "ab");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo goles.dat" << endl;
        return;
    }
    fwrite(this, sizeof(Gol), 1, p);
    fclose(p);
}


void mostrarGoles() {
    FILE* p = fopen("goles.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo goles.dat" << endl;
        return;
    }
    Gol g;
    while (fread(&g, sizeof(Gol), 1, p)) {
        g.mostrar();
        cout << "------------------------" << endl;
    }
    fclose(p);
}


// Getters y setters
int Gol::getNumeroPartido() const { return numeroPartido; }
const char* Gol::getDniJugador() const { return dniJugador; }
int Gol::getTipoGol() const { return tipoGol; }

void Gol::setNumeroPartido(int n) { numeroPartido = n; }
void Gol::setDniJugador(const char* d) { strncpy(dniJugador, d, sizeof(dniJugador)); }
void Gol::setTipoGol(int t) { tipoGol = t; }
