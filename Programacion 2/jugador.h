#ifndef JUGADOR_H
#define JUGADOR_H

#include "ClsFecha.h"

class Jugador {
private:
    char dni[10];
    int codigoClub;
    char nombre[30];
    char apellido[30];
    char telefono[20];
    char email[40];
    Fecha fechaNacimiento;
public:
    void cargar();
    void mostrar() const;

    // Getters y setters
    const char* getDNI() const;
    int getCodigoClub() const;
    const char* getNombre() const;
    const char* getApellido() const;
    const char* getTelefono() const;
    const char* getEmail() const;
    Fecha getFechaNacimiento() const;

    void setDNI(const char* d);
    void setCodigoClub(int c);
    void setNombre(const char* n);
    void setApellido(const char* a);
    void setTelefono(const char* t);
    void setEmail(const char* e);
    void setFechaNacimiento(const Fecha& f);
};

#endif

