#ifndef PARTIDA_H
#define PARTIDA_H

#include "setequipos.h"
#include "vaca.h"
#include "mem.h"
#include "setjugadores.h"
#include "wdgGame.h"

class wdgGame;
class SetEquipos;
class Vaca;
class SetJugadores;

//CONJUNTO DE VACAS
class Partida
{
public:
  Partida(Mem *mem, int numreyes);
  virtual ~Partida();
  SetEquipos *equipos;
  SetJugadores *jugadores;
  QList <Vaca*> *vacas;
  Vaca *currentVaca;
  int numVacasJugadas();
  void nuevaVaca();
  wdgGame *wdg;
  
  int numreyes;
  Mem *mem;
};

#endif // PARTIDA_H
