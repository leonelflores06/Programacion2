#include <iostream>
#include "Club.h"
#include <cstring>

using namespace std;


void Club::mostrarClubes() {
    FILE* p = fopen("clubes.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo clubes.dat" << endl;
        return;
    }
    Club c;
    while (fread(&c, sizeof obj, 1, p)) {
        c.mostrar();
        cout << "------------------------" << endl;
    }
    fclose(p);
}
int Club::contarRegistros() {
    FILE *p = fopen("clubes.dat", "rb");
    if (p == nullptr) {
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Club);
}

Club Club::leerRegistro(int pos) {
    Club obj;
    FILE *p = fopen("clubes.dat", "rb");
    if (p == nullptr) {
        obj.setCodigo(-2);
        return obj;
    }
    obj.setCodigo(-1);
    fseek(p, pos * sizeof obj, 2);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int Club::buscarRegistro(int c) {
    Club obj;
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        obj = leerRegistro(i);
        if (obj.getCodigo() == c) {
            return i;
        }
    }
    return -1;
}
void Club::buscarYMostrarClub(int codigo) {
    int pos = buscarRegistro(codigo);
    if (pos < 0) {
        std::cout << "No existe un club con ese código." << std::endl;
        return;
    }
    Club c = leerRegistro(pos);
    c.mostrar();
}


void Club::cargar(){
    Club obj;
    do{
        cout<<"Codigo de club: ";
        cin>>codigo;
        if (obj.buscarRegistro(codigo) != -1) {
            cout << "El club está registrado. Ingrese un nuevo código." << endl;
        }
    }while(obj.buscarRegistro(codigo) != -1);
    cout<<"Nombre del club: ";
    cin.ignore();
    cin.getline(nombreClub, 40);
    cout<<"Nombre del presidente: ";
    cin.getline(nombrePresidente, 40);
    cout<<"Fecha de inscripcion: "<<endl;
    fechaInscripcion.cargarFecha();
    cout<<"Torneos ganados: ";
    cin>>torneosGanados;
}
void Club::mostrar() const{
    cout<<"Codigo del club: "<<codigo<<endl;
    cout<<"Nombre del club: "<<nombreClub<<endl;
    cout<<"Nombre del presidente: "<<nombrePresidente<<endl;
    cout<<"Fecha de nacimiento: ";
    fechaInscripcion.mostrarFecha();
    cout<<"Torneos Ganados: "<<torneosGanados;
    cout<<endl;
}

void Club::guardarClub(const Club& c) {
    FILE* p = fopen("clubes.dat", "ab");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo clubes.dat" << endl;
        return;
    }
    fwrite(&c, sizeof(Club), 1, p);
    fclose(p);
}


// Getters y setters
int Club::getCodigo() const{return codigo;}
const char* Club::getNombreClub() const{return nombreClub;}
const char* Club::getNombrePresidente() const{return nombrePresidente;}
Fecha Club::getFechaInscripcion() const{return fechaInscripcion;}
int Club::getTorneosGanados() const{return torneosGanados;}

void Club::setCodigo(int c){codigo = c;}
void Club::setNombreClub(const char* n){strncpy(nombreClub, n, sizeof(nombreClub));}
void Club::setNombrePresidente(const char* p){strncpy(nombrePresidente, p, sizeof(nombrePresidente));}
void Club::setFechaInscripcion(const Fecha& f){fechaInscripcion = f;}
void Club::setTorneosGanados(int t){torneosGanados = t;}
