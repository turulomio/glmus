#ifndef SETEQUIPOS_H
#define SETEQUIPOS_H

#include "equipo.h"
#include "setjugadores.h"
class Equipo;
class SetJugadores;
//Clase que se usa para recorrer los equipos
class SetEquipos
{

public:
    SetEquipos(SetJugadores *jugadores);
    virtual ~SetEquipos();
    Equipo *arr;
};

#endif // SETEQUIPOS_H
