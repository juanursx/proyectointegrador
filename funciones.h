#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

bool esEscalera(int vec[]);
int lanzamientoDados(int lanzada[], bool simulado);
int ronda(int &numeroronda, bool simulado, std::string jugador);
int PartidaUnJugador(bool simulado);
int PartidaDosJugadores(bool simulado);
void comparadorpuntajes(int &mayorpuntaje, std::string &nombremayorpuntaje, int nuevopuntaje, std::string nuevonombrepuntaje);
void MostrarPuntaje();
#endif // FUNCIONES_H_INCLUDED
