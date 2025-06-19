#include <iostream>
#include <cstring>
#include "gol.h"
#include "jugador.h"
#include "Club.h"

using namespace std;

void Gol::cargar() {
    Jugador obj;
    cout << "Numero de partido: ";
    cin >> numeroPartido;
    do{
        cout << "DNI del jugador: ";
        cin >> dniJugador;
        if (obj.buscarRegistro(dniJugador) == -1) {
        cout << "El DNI no esta registrado." << endl;
        }
    }while(obj.buscarRegistro(dniJugador) == -1);

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
void contarTiposDeGol() {
    FILE* p = fopen("goles.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo goles.dat" << endl;
        return;
    }

    // Obtener cantidad total de registros
    fseek(p, 0, SEEK_END);
    long tamArchivo = ftell(p);
    int cantRegistros = tamArchivo / sizeof(Gol);
    rewind(p);

    // Memoria dinámica
    Gol* goles = new Gol[cantRegistros];
    fread(goles, sizeof(Gol), cantRegistros, p);
    fclose(p);

    // Contadores
    int golPenal = 0, golTiroLibre = 0, golJugada = 0;

    for (int i = 0; i < cantRegistros; i++) {
        switch (goles[i].getTipoGol()) {
            case 1: golPenal++; break;
            case 2: golTiroLibre++; break;
            case 3: golJugada++; break;
        }
    }

    // Mostrar resultados
    cout << "Cantidad de goles por tipo:" << endl;
    cout << "Penal: " << golPenal << endl;
    cout << "Tiro libre: " << golTiroLibre << endl;
    cout << "Jugada: " << golJugada << endl;

    delete[] goles;
}



// Getters y setters
int Gol::getNumeroPartido() const { return numeroPartido; }
const char* Gol::getDniJugador() const { return dniJugador; }
int Gol::getTipoGol() const { return tipoGol; }

void Gol::setNumeroPartido(int n) { numeroPartido = n; }
void Gol::setDniJugador(const char* d) { strncpy(dniJugador, d, sizeof(dniJugador)); }
void Gol::setTipoGol(int t) { tipoGol = t; }
