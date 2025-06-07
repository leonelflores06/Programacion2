#include <iostream>
#include <cstring>
#include "jugador.h"

using namespace std;

void Jugador::cargar() {
    cout << "DNI: ";
    cin >> dni;
    cout << "Codigo del club: ";
    cin >> codigoClub;
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(nombre, 30);
    cout << "Apellido: ";
    cin.getline(apellido, 30);
    cout << "Telefono: ";
    cin.getline(telefono, 20);
    cout << "Email: ";
    cin.getline(email, 40);
    cout << "Fecha de nacimiento: " << endl;
    fechaNacimiento.cargarFecha();
}

void Jugador::mostrar() const {
    cout << "DNI: " << dni << endl;
    cout << "Club: " << codigoClub << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Email: " << email << endl;
    cout << "Fecha de nacimiento: ";
    fechaNacimiento.mostrarFecha();
    cout << endl;
}

// Getters y setters
const char* Jugador::getDNI() const { return dni; }
int Jugador::getCodigoClub() const { return codigoClub; }
const char* Jugador::getNombre() const { return nombre; }
const char* Jugador::getApellido() const { return apellido; }
const char* Jugador::getTelefono() const { return telefono; }
const char* Jugador::getEmail() const { return email; }
Fecha Jugador::getFechaNacimiento() const { return fechaNacimiento; }

void Jugador::setDNI(const char* d) { strncpy(dni, d, sizeof(dni)); }
void Jugador::setCodigoClub(int c) { codigoClub = c; }
void Jugador::setNombre(const char* n) { strncpy(nombre, n, sizeof(nombre)); }
void Jugador::setApellido(const char* a) { strncpy(apellido, a, sizeof(apellido)); }
void Jugador::setTelefono(const char* t) { strncpy(telefono, t, sizeof(telefono)); }
void Jugador::setEmail(const char* e) { strncpy(email, e, sizeof(email)); }
void Jugador::setFechaNacimiento(const Fecha& f) { fechaNacimiento = f; }
