#include "funciones.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

std::string nombremayorpuntaje="NONE";
int mayorpuntaje=0;

void comparadorpuntajes(int &mayorpuntaje, std::string &nombremayorpuntaje, int nuevopuntaje, std::string nuevonombrepuntaje){
    if(nuevopuntaje>mayorpuntaje){
        nombremayorpuntaje=nuevonombrepuntaje;
        mayorpuntaje=nuevopuntaje;
    }
}

void MostrarPuntaje(){
    std::cout<<"NOMBRE DEL JUGADOR CON MAYOR PUNTAJE: "<<nombremayorpuntaje<<std::endl;
    std::cout<<"SU PUNTAJE FUE DE: "<<mayorpuntaje<<std::endl;
    system("pause>null");
    system("cls");
}

bool esEscalera(int vec[]){
    bool firstinput = false, answer = true;
    int lastvalue, sentido = 3; // sentido=1 menor a mayor || sentido=0 mayor a menor.

    for(int i = 0; i < 6; i++){
        if(!firstinput){
            lastvalue = vec[i];
            firstinput = true;
        }
        else if (sentido == 3){
            if(lastvalue > vec[i]){
                sentido = 0;  // Mayor a menor
            }
            else if (lastvalue < vec[i]){
                sentido = 1;  // Menor a mayor
            }
            else{
                answer = false;  // Si los n�meros son iguales, no es escalera
                break;
            }
        }
        else {
            if(sentido == 1 && lastvalue > vec[i]){  // Verificar si sigue siendo menor a mayor
                answer = false;
                break;
            }
            else if(sentido == 0 && lastvalue < vec[i]){  // Verificar si sigue siendo mayor a menor
                answer = false;
                break;
            }
        }
        lastvalue = vec[i];  // Actualizar el �ltimo valor
    }

    return answer;
}

bool esSexteto(int vec[], int &numsec){
    int initnum;
    initnum = vec[0];
    for(int i=0; i<6; i++){
        if(vec[i]!=initnum){
            return false;
        }
    }
    numsec=vec[0];
    return true;
}

int lanzamientoDados(int lanzada[], bool simulado) {
    int suma;
    if(!simulado){
        for (int i = 0; i < 6; i++) {
            lanzada[i] = (rand() % 6) + 1;
            std::cout << lanzada[i]<< "\t";
            suma += lanzada[i];
        }
        std::cout<<std::endl;
    }
    else{
        int numerodado;
        for (int i = 0; i < 6; i++) {
            std::cout<<"Elije el numero de tu dado: "; // ASIGNAR NUMEROS A LOS DADOS
            std::cin>>numerodado;
            lanzada[i] = numerodado;
        }
        std::cout<<std::endl<<"TUS NUMEROS FUERON: "<<std::endl;
        for (int i = 0; i < 6; i++) {
            std::cout << lanzada[i]<< "\t"; // MOSTRAR VECTOR DE DADOS
            suma += lanzada[i];
        }
        std::cout<<std::endl;
    }

    return suma;
}

int ronda(int &numeroronda, bool simulado, std::string jugador, int puntaje){
    int puntajefinal, tirada1, tirada2, tirada3;
    int numsec;
    numeroronda++;
    int primerlanzada[6] = {};
    int segundalanzada[6] = {};
    int terceralanzada[6] = {};
    std::cout<<"TURNO DE: "<<jugador<<std::endl;
    std::cout<<"RONDA N: "<<numeroronda<<std::endl;
    std::cout<<"PUNTAJE TOTAL: "<<puntaje<<std::endl;
    std::cout<<"Se han lanzado los dados! Estos fueron los resultados: "<<std::endl<<std::endl;
    std::cout<<"********************************************"<<std::endl;
    std::cout<<"LANZADA N: 1"<<std::endl<<std::endl;
    tirada1 = lanzamientoDados(primerlanzada, simulado);
    std::cout<<std::endl<<std::endl;
    if(esEscalera(primerlanzada)){
        puntajefinal=-2;
        return puntajefinal;
    }
    if(esSexteto(primerlanzada, numsec)){
        if(numsec==6){
            puntajefinal=-5;
        }
        else{
            puntajefinal=numsec*10;
        }
        return puntajefinal;
    }
    std::cout<<"LANZADA N: 2"<<std::endl<<std::endl;
    tirada2 = lanzamientoDados(segundalanzada, simulado);
    if(esEscalera(segundalanzada)){
        puntajefinal=-2;
        return puntajefinal;
    }
    if(esSexteto(segundalanzada, numsec)){
        if(numsec==6){
            puntajefinal=-5;
        }
        else{
            puntajefinal=numsec*10;
        }
        return puntajefinal;
    }
    std::cout<<std::endl<<std::endl;
    std::cout<<"LANZADA N: 3"<<std::endl<<std::endl;
    tirada3 = lanzamientoDados(terceralanzada, simulado);
    if(esEscalera(terceralanzada)){
        puntajefinal=-2;
        return puntajefinal;
    }
    if(esSexteto(terceralanzada, numsec)){
        if(numsec==6){
            puntajefinal=-5;
        }
        else{
            puntajefinal=numsec*10;
        }
        return puntajefinal;
    }
    std::cout<<"********************************************"<<std::endl<<std::endl;

    // EVALUAR PUNTAJES RONDA

    if(tirada1 > tirada2 && tirada1 > tirada3){ // EN CASO DE NO HABER EXCEPCIONES, SE EVALUA NORMALMENTE...
        puntajefinal = tirada1;
    }
    else if(tirada2 > tirada1 && tirada2 > tirada3){
        puntajefinal = tirada2;
    }
    else{
        puntajefinal = tirada3;
    }
    return puntajefinal;
}

int PartidaUnJugador(bool simulado) {
    std::string jugador;
    bool excepcionganadora=false;
    int puntaje=0, numeroronda=0, puntajeronda;
    std::cout<<"Partida iniciada. Buena suerte!"<<std::endl<<std::endl;
    std::cout << "Ingrese su nombre: ";
    std::cin >> jugador;

    while(puntaje < 100){
        system("cls");
        puntajeronda = ronda(numeroronda, simulado, jugador, puntaje); // Se define en la variable el puntaje total de cada RONDA.
        system("pause>null");

        // SE PROCESA EL PUNTAJE
        if(puntajeronda==-2){
            excepcionganadora=true;
            break;
        }
        puntaje+=puntajeronda;

        if(puntajeronda == -5){
            std::cout<<std::endl;
            puntaje=0;
            std::cout<<"UPS! Mala suerte. Obtuviste 6 veces 6, se ha reiniciado tu puntaje!"<<std::endl;
            system("pause>null");
        }
    }

    if(excepcionganadora){
        std::cout<<"Has ganado debido a que has obtenido una escalera, espectacular!!"<<std::endl;
        std::cout<<"El total de rondas fue de: "<<numeroronda<<std::endl<<std::endl;
    }
    else{
        std::cout<<"Has ganado! Llegaste a los 100 puntos en solo "<<numeroronda<<" rondas!! (Total puntaje real = "<<puntaje<<")"<<std::endl<<std::endl;
    }
    comparadorpuntajes(mayorpuntaje, nombremayorpuntaje, puntaje, jugador);
    system("pause>null");
    system("cls");
    int opcion;
    std::cout<<"*****************"<<std::endl;
    std::cout<<"Quieres volver a jugar o finalizar la partida?:"<<std::endl;
    std::cout<<"1. Volver a jugar."<<std::endl;
    std::cout<<"2. Finalizar juego."<<std::endl;
    std::cout<<"*****************"<<std::endl;
    std::cout<<"--> ";
    std::cin>>opcion;
    while(true){
        if(opcion==2){
            system("cls");
            return 2;
        }
        else if(opcion == 1){
            system("cls");
            break;
        }
        else{
            std::cout<<std::endl<<"Error. Elige una opcion correcta."<<std::endl;
            system("pause>null");
            system("cls");
        }
    }
    return 1;
}
int PartidaDosJugadores(bool simulado) {
    std::string jugador1, jugador2;
    std::string nombrejugadoractual;
    bool turno = true; // FALSE = JUGADOR 1, TRUE = JUGADOR 2.
    bool excepcionganadora=false;
    int puntajej1=0, puntajej2=0, numeroronda=0, puntajeronda, jugadoractual;
    std::cout<<"Partida iniciada. Buena suerte!"<<std::endl<<std::endl;
    std::cout << "Ingrese el nombre del jugador 1: ";
    std::cin >> jugador1;
    std::cout << "Ingrese el nombre del jugador 2: ";
    std::cin >> jugador2;

    while(puntajej1 < 100 && puntajej2 < 100){
        turno=!turno;
        if(!turno){
            jugadoractual = 1;
            nombrejugadoractual = jugador1;
            system("cls");
            puntajeronda = ronda(numeroronda, simulado, nombrejugadoractual, puntajej1);
        }
        else{
            jugadoractual = 2;
            nombrejugadoractual = jugador2;
            system("cls");
            puntajeronda = ronda(numeroronda, simulado, nombrejugadoractual, puntajej2);
        }
        system("pause>null");
        // SE PROCESA EL PUNTAJE
        if(puntajeronda==-2){
            excepcionganadora=true;
            break;
        }
        if(!turno){
            puntajej1+=puntajeronda;
        }
        else{
            puntajej2+=puntajeronda;
        }

        if(puntajeronda == -5 && turno==false){
            std::cout<<std::endl;
            puntajej1=0;
            std::cout<<"UPS! Mala suerte. El jugador 1 ha obtenido 6 veces 6, se ha reiniciado su puntaje!"<<std::endl;
            system("pause>null");
        }
        else if(puntajeronda == -5 && turno==true){
            std::cout<<std::endl;
            puntajej2=0;
            std::cout<<"UPS! Mala suerte. El jugador 2 obtuvo 6 veces 6, se ha reiniciado su puntaje!"<<std::endl;
            system("pause>null");
        }
    }

    if(excepcionganadora){
        std::cout<<nombrejugadoractual<<" ha ganado debido a que ha obtenido una escalera, espectacular!! "<<std::endl;
        std::cout<<"El total de rondas fue de: "<<numeroronda<<std::endl<<std::endl;
    }
    else{
        std::cout<<nombrejugadoractual<< " ha ganado! Llego a los 100 puntos en solo "<<numeroronda<<" rondas!! ";
        if(!turno){
            std::cout<<"(Total puntaje real = "<<puntajej1<<")"<<std::endl<<std::endl;
            comparadorpuntajes(mayorpuntaje, nombremayorpuntaje, puntajej1, nombrejugadoractual);
        }
        else{
            std::cout<<"(Total puntaje real = "<<puntajej2<<")"<<std::endl<<std::endl;
            comparadorpuntajes(mayorpuntaje, nombremayorpuntaje, puntajej2, nombrejugadoractual);
        }
    }
    system("pause>null");
    system("cls");
    int opcion;
    std::cout<<"*****************"<<std::endl;
    std::cout<<"Quieres volver a jugar o finalizar la partida?:"<<std::endl;
    std::cout<<"1. Volver a jugar."<<std::endl;
    std::cout<<"2. Finalizar juego."<<std::endl;
    std::cout<<"*****************"<<std::endl;
    std::cout<<"--> ";
    std::cin>>opcion;
    while(true){
        if(opcion==2){
            system("cls");
            return 2;
        }
        else if(opcion == 1){
            system("cls");
            break;
        }
        else{
            std::cout<<std::endl<<"Error. Elige una opcion correcta."<<std::endl;
            system("pause>null");
            system("cls");
        }
    }
    return 1;
}
