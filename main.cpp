#include <iostream>
#include "jugador.h"
#include "club.h"
#include "gol.h"
#include "ClsFecha.h"

using namespace std;


void guardarJugador(const Jugador& j) {
            FILE* p = fopen("jugadores.dat", "ab");
            if (p == NULL) {
                cout << "No se pudo abrir el archivo jugadores.dat" << endl;
                return;
            }
            fwrite(&j, sizeof(Jugador), 1, p);
            fclose(p);
        }

        void mostrarJugadores() {
            FILE* p = fopen("jugadores.dat", "rb");
            if (p == NULL) {
                cout << "No se pudo abrir el archivo jugadores.dat" << endl;
                return;
            }
            Jugador j;
            while (fread(&j, sizeof(Jugador), 1, p)) {
                j.mostrar();
                cout << "------------------------" << endl;
            }
            fclose(p);
        }


int main() {
    int opcion;

    do {
        cout << "----- MENU DE PRUEBA -----" << endl;
        cout << "1. Probar clase Jugador" << endl;
        cout << "2. Probar clase Club" << endl;
        cout << "3. Probar clase Gol" << endl;
        cout << "4. Probar clase Fecha" << endl;
        cout << "5. Cargar y guardar Jugador" << endl;
        cout << "6. Mostrar jugadores guardados" << endl;
        cout << "7. Cargar y guardar Club" << endl;
        cout << "8. Mostrar clubes guardados" << endl;
        cout << "9. Cargar y guardar Gol" << endl;
        cout << "10. Mostrar goles guardados" << endl;

                cout << "0. Salir" << endl;
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                system("pause");
                system("cls");
                switch(opcion) {
                    case 1: {
                        Jugador j;
                        j.cargar();
                        system("pause");
                        system("cls");
                        cout << "\n--- Jugador cargado ---" << endl;
                        j.mostrar();
                        break;
                    }
                    case 2: {
                        Club c;
                        c.cargar();
                        system("pause");
                        system("cls");
                        cout << "\n--- Club cargado ---" << endl;
                        c.mostrar();
                        break;
                    }
                    case 3: {
                        Gol g;
                        g.cargar();
                        system("pause");
                        system("cls");
                        cout << "\n--- Gol cargado ---" << endl;
                        g.mostrar();
                        break;
                    }
                    case 4: {
                        Fecha f;
                        f.cargarFecha();
                        cout << "\n--- Fecha cargada ---" << endl;
                        f.mostrarFecha();
                        cout << endl;
                        break;
                                }
                    case 5: {
                        Jugador j;
                        j.cargar();
                        guardarJugador(j);
                        break;
                    }
                    case 6: {
                        mostrarJugadores();
                        break;
                    }
                    case 7: {
                        Club c;
                        c.cargar();
                        c.guardarClub(c);
                        break;
                    }
                    case 8: {
                        Club c;
                        c.mostrarClubes();
                        break;
                    }
                    case 9: {
                        Gol g;
                        g.cargar();
                        g.guardarGol();
                        break;
                    }
                    case 10: {
                        mostrarGoles();
                        break;
                    }

                    case 0:
                        cout << "Saliendo..." << endl;
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }

                if(opcion!=0)
                {
                    system("pause");
                    system("cls");
                }

}while(opcion !=0);
}


