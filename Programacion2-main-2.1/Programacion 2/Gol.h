#ifndef GOL_H
#define GOL_H

class Gol {
private:
    int numeroPartido;
    char dniJugador[10];
    int tipoGol;  // 1: Penal, 2: Tiro libre, 3: Jugada
public:
    void cargar();
    void mostrar() const;


    // Getters y setters
    int getNumeroPartido() const;
    const char* getDniJugador() const;
    int getTipoGol() const;

    void setNumeroPartido(int n);
    void setDniJugador(const char* d);
    void setTipoGol(int t);

    //Archivo
    void guardarGol() const;


};
    void mostrarGoles();
    void contarTiposDeGol();

#endif
