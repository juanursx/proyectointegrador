#include <iostream>
#include "funciones.h"
using namespace std;

int main(int argc, char *argv[]) {
    srand(time(0)); // Crea semilla principal para los numeros aleatorios.
    int opcion;
    bool simulado=false;
    string playername;
    do  // MENU PRINCIPAL DEL JUEGO
    {
        cout<<"*** PROYECTO INTEGRADOR PROGRAMACION ***"<<endl<<endl;
        cout<<"1. Juego nuevo para un jugador."<<endl;
        cout<<"2. Juego nuevo para dos jugadores."<<endl;
        cout<<"3. Mostrar puntuacion mas alta."<<endl;
        if(!simulado){
            cout<<"4. Modo simulado."<<endl;
        }
        cout<<"0. Salir."<<endl;
        cout<<"--> ";
        cin>>opcion;
        switch(opcion){
            case 1:{
                system("cls");
                int eleccion = PartidaUnJugador(simulado);
                if(eleccion==2){
                    opcion=0; // SE FINALIZA LA PARTIDA AL PONER OPCION SALIR EN MODO UNJUGADOR.
                }
                break;
            }
            case 2:{
                system("cls");
		        int eleccion=PartidaDosJugadores(simulado);
                if (eleccion == 2){
                    opcion=0;
                }
                break;
            }
            case 3:{
                system("cls");
                MostrarPuntaje();
                break;
            }
            case 4:{
                simulado=true;
                system("cls");
                continue;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"Opcion no valida, intentalo nuevamente."<<endl;
                system("pause");
                system("cls");
                continue;
            }
        }
    } while (opcion !=0);
    cout<<"Programa finalizado.";
	return 0;
}
