#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha();
    Fecha(int d, int m, int a);
    void cargarFecha();
    void mostrarFecha() const;
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
};

#endif
