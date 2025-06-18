#include <iostream>
#include "jugador.h"
#include "club.h"
#include "gol.h"
#include "ClsFecha.h"

using namespace std;



int main() {
    setlocale(LC_ALL, "spanish");

    int opcion;

    do {
        cout << "----- MENU DE PRUEBA -----" << endl;
        cout << "1. Cargar y guardar Jugador" << endl;
        cout << "2. Mostrar jugadores guardados" << endl;
        cout << "3. Cargar y guardar Club" << endl;
        cout << "4. Mostrar clubes guardados" << endl;
        cout << "5. Cargar y guardar Gol" << endl;
        cout << "6. Mostrar goles guardados" << endl;
        cout << "7. Mostrar jugadores de un club"<<endl;
        cout << "8. Cantidad total de goles por tipo (penal, tiro libre, jugada)"<<endl;

                cout << "0. Salir" << endl;
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                system("pause");
                system("cls");
                switch(opcion) {
                    case 1: {
                        Jugador j;
                        j.cargar();
                        j.guardarJugador(j);
                        system("pause");
                        system("cls");
                        cout << "\n--- Jugador cargado ---" << endl;
                        j.mostrar();
                        break;
                    }
                    case 2: {
                        Jugador j;
                        j.mostrarJugadores();
                        break;
                    }
                    case 3: {
                        Club c;
                        c.cargar();
                        c.guardarClub(c);
                        system("pause");
                        system("cls");
                        cout << "\n--- Club cargado ---" << endl;
                        c.mostrar();
                        break;
                    }
                    case 4: {
                        Club c;
                        c.mostrarClubes();
                        break;
                    }
                    case 5: {
                        Gol g;
                        g.cargar();
                        g.guardarGol();
                        system("pause");
                        system("cls");
                        cout << "\n--- Gol cargado ---" << endl;
                        g.mostrar();
                        break;
                    }

                    case 6: {
                        mostrarGoles();
                        break;
                    }
                    case 7:{
                        int codigo;
                        cout << "Ingrese el código del club: ";
                        cin >> codigo;
                        Jugador j;
                        j.listarPorClub(codigo);
                        break;
                    }
                    case 8:{
                        contarTiposDeGol();
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

