#ifndef GOL_H
#define GOL_H

class Gol {
private:
    int numeroPartido;
    char dniJugador[10];
    int tipoGol;
public:
    void cargar();
    void mostrar() const;

    // Getters
    int getNumeroPartido() const;
    const char* getDniJugador() const;
    int getTipoGol() const;

    // Setters
    void setNumeroPartido(int n);
    void setDniJugador(const char* d);
    void setTipoGol(int t);

    // Archivo
    void guardarGol() const;
};

// Funciones auxiliares
void mostrarGoles();
void contarTiposDeGol();

#endif
