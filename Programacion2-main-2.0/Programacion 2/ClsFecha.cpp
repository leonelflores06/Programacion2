#include "Clsfecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha() : dia(1), mes(1), anio(2000) {}
Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

void Fecha::cargarFecha() {
    cout << "Día: "; cin >> dia;
    cout << "Mes: "; cin >> mes;
    cout << "Año: "; cin >> anio;
}

void Fecha::mostrarFecha() const {
    cout << dia << "/" << mes << "/" << anio << endl;
}

int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAnio() const { return anio; }
void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnio(int a) { anio = a; }
