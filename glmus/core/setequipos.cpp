#include "setequipos.h"

SetEquipos::SetEquipos(SetJugadores *jugadores)
{
  this->arr=new Equipo[2];
  this->arr[0].asignarMiembros(&jugadores->arr[0], &jugadores->arr[2]);
  this->arr[1].asignarMiembros(&jugadores->arr[1], &jugadores->arr[3]);
}

SetEquipos::~SetEquipos()
{

}

