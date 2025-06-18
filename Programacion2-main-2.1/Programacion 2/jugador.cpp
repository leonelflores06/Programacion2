#include <iostream>
#include <cstring>
#include "jugador.h"
#include "Club.h"

using namespace std;

void Jugador::cargar() {
    Club obj;
    cout << "DNI: ";
    cin >> dni;
    do {
    cout << "Codigo del club: ";
    cin >> codigoClub;

    if (obj.buscarRegistro(codigoClub) == -1) {
        cout << "El club no está registrado. Ingrese un código válido." << endl;
    }
    } while (obj.buscarRegistro(codigoClub) == -1);

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
void Jugador::guardarJugador(const Jugador& j) {
    Jugador obj;
    FILE* p = fopen("jugadores.dat", "ab");
    if (p == NULL) {
        cout<<"No se pudo abrir el archivo jugadores.dat"<<endl;
        return;
    }
    fwrite(&j, sizeof obj, 1, p);
    fclose(p);
}

void Jugador::mostrarJugadores() {
    Jugador obj;
    FILE* p = fopen("jugadores.dat", "rb");
    if (p == NULL) {
        cout<<"No se pudo abrir el archivo jugadores.dat"<<endl;
        return;
    }
    Jugador j;
    while (fread(&j, sizeof obj, 1, p)) {
        j.mostrar();
        cout << "------------------------" << endl;
    }
    fclose(p);
}

Jugador Jugador::leerRegistro(int pos){
    Jugador obj;
    FILE* p = fopen("jugadores.dat", "rb");
    if(p == nullptr){
        obj.setDNI("NULL");
        return obj;
    }
    obj.setDNI("NULL");
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int Jugador::contarRegistros() {
    FILE* p = fopen("jugadores.dat", "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Jugador);
}
void Jugador::listarPorClub(int codigoBuscado) {
    Jugador obj;
    int cantidad = contarRegistros();
    bool encontrado = false;

    cout<<"Jugadores del club código "<<codigoBuscado<<":"<<endl<<endl;

    for (int i = 0; i < cantidad; i++) {
        obj = leerRegistro(i);
        if (obj.getCodigoClub() == codigoBuscado) {
            obj.mostrar();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout<<"No hay jugadores registrados con ese código de club."<<endl;
    }
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
