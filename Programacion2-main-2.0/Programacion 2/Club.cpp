#include <iostream>
#include "Club.h"
#include <cstring>

using namespace std;

void Club::cargar(){
    cout<<"Codigo de club: ";
    cin>>codigo;
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


void Club::mostrarClubes() {
    FILE* p = fopen("clubes.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo clubes.dat" << endl;
        return;
    }
    Club c;
    while (fread(&c, sizeof(Club), 1, p)) {
        c.mostrar();
        cout << "------------------------" << endl;
    }
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
