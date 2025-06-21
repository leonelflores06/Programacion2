#include <iostream>
#include <cstring>
#include "jugador.h"
#include "Club.h"
#include "gol.h"
#include "ClsFecha.h"

using namespace std;


int obtenerCodigoClubPorDNI(const char* dniBuscado) {
    Jugador j;
    FILE* p = fopen("jugadores.dat", "rb");
    if (p == NULL) return -1;

    while (fread(&j, sizeof(Jugador), 1, p) == 1) {
        if (strcmp(j.getDNI(), dniBuscado) == 0) {
            fclose(p);
            return j.getCodigoClub();
        }
    }

    fclose(p);
    return -1;
}

const char* obtenerNombreClub(int codigoBuscado) {
    static Club c;
    FILE* p = fopen("clubes.dat", "rb");
    if (p == NULL) return "Desconocido";

    while (fread(&c, sizeof(Club), 1, p) == 1) {
        if (c.getCodigo() == codigoBuscado) {
            fclose(p);
            return c.getNombreClub();
        }
    }

    fclose(p);
    return "Desconocido";
}

void clubConMasGoles() {
    FILE* pGoles = fopen("goles.dat", "rb");
    if (pGoles == NULL) {
        cout << "No se pudo abrir goles.dat" << endl;
        return;
    }

    int codigosClub[100];
    int golesClub[100];
    int totalClubs = 0;

    Gol g;
    while (fread(&g, sizeof(Gol), 1, pGoles) == 1) {
        int codClub = obtenerCodigoClubPorDNI(g.getDniJugador());
        if (codClub == -1) continue;

        // Buscar si el club ya está en el array
        bool encontrado = false;
        for (int i = 0; i < totalClubs; i++) {
            if (codigosClub[i] == codClub) {
                golesClub[i]++;
                encontrado = true;
                break;
            }
        }

        // Si no estaba, lo agregamos
        if (!encontrado && totalClubs < 100) {
            codigosClub[totalClubs] = codClub;
            golesClub[totalClubs] = 1;
            totalClubs++;
        }
    }

    fclose(pGoles);

    // Buscar el club con más goles
    int maxGoles = 0;
    int codClubMax = -1;

    for (int i = 0; i < totalClubs; i++) {
        if (golesClub[i] > maxGoles) {
            maxGoles = golesClub[i];
            codClubMax = codigosClub[i];
        }
    }

    if (codClubMax != -1) {
        cout <<  "El club con mas goles es: " << obtenerNombreClub(codClubMax)
             << " (" << maxGoles << " goles)" << endl;
    } else {
        cout << "No se registraron goles." << endl;}
}

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
        cout << "9. Mostrar club con mas goles" << endl;
        cout << "10. Buscar Jugador por dni" <<endl;
        cout << "11. Ranking de clubes por torneos ganados" << endl;

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
                        break;
                    }
                    case 9: {
                        clubConMasGoles();
                        break;
                    }
                    case 10: {
                        Jugador j;
                        char dniBuscar[20];
                        cout << "Ingrese el DNI del jugador: ";
                        cin.ignore();
                        cin.getline(dniBuscar, sizeof(dniBuscar));
                        cout<<endl<<endl;
                        j.buscarPorDNI(dniBuscar);
                        break;
                    }
                    case 11: {
                        rankingClubes();
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














/*

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}
*/
