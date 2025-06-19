#ifndef CLUB_H
#define CLUB_H

#include "ClsFecha.h"

class Club {
private:
    int codigo;
    char nombreClub[40];
    char nombrePresidente[40];
    Fecha fechaInscripcion;
    int torneosGanados;
public:
    void cargar();
    void mostrar() const;
    void guardarClub(const Club& c);
    void mostrarClubes();
    int contarRegistros();
    Club leerRegistro(int pos);
    int buscarRegistro(int c);
    void buscarYMostrarClub(int codigoClub);


    // Getters y setters
    int getCodigo() const;
    const char* getNombreClub() const;
    const char* getNombrePresidente() const;
    Fecha getFechaInscripcion() const;
    int getTorneosGanados() const;

    void setCodigo(int c);
    void setNombreClub(const char* n);
    void setNombrePresidente(const char* p);
    void setFechaInscripcion(const Fecha& f);
    void setTorneosGanados(int t);
};

#endif
