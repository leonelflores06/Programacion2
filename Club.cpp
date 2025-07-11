#include <iostream>
#include "Club.h"
#include <cstring>

using namespace std;


void Club::mostrarClubes() {
    Club obj;
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
    fseek(p, pos * sizeof obj, SEEK_SET);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}


int Club::buscarRegistro(int c) {
    Club obj;
    FILE *p = fopen("clubes.dat", "rb");
    if(p == nullptr){
        return -1;
    }
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
        std::cout << "No existe un club con ese c�digo." << std::endl;
        return;
    }
    Club c = leerRegistro(pos);
    c.mostrar();
}


void Club::cargar(){
    do{
        cout<<"Codigo de club: ";
        cin>>codigo;
        if (buscarRegistro(codigo) != -1) {
            cout << "El club est� registrado. Ingrese un nuevo c�digo." << endl;
        }
    }while(buscarRegistro(codigo) != -1);
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

void rankingClubes() {
    Club clubes[100];
    int total = clubes[0].contarRegistros();

    if (total == 0) {
        cout << "No hay clubes registrados." << endl;
        return;
    }

    for (int i = 0; i < total; i++) {
        clubes[i] = clubes[0].leerRegistro(i);
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (clubes[i].getTorneosGanados() < clubes[j].getTorneosGanados()) {
                Club aux = clubes[i];
                clubes[i] = clubes[j];
                clubes[j] = aux;
            }
        }
    }

    cout << "Ranking de clubes por torneos ganados:\n" << endl;
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << clubes[i].getNombreClub()
                  << " - " << clubes[i].getTorneosGanados() << " torneos ganados" << endl;
    }
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
