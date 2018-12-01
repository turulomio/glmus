#include "partida.h"

Partida::Partida(Mem *mem, int numreyes)
{
  this->mem=mem;
  this->numreyes=numreyes;
  this->jugadores=new SetJugadores();//Crea los jugadores
  this->equipos=new SetEquipos(this->jugadores);
  this->vacas=new QList<Vaca *>();
  this->nuevaVaca();

}
Partida::~Partida()
{

}

int Partida::numVacasJugadas()
{
  return this->vacas->count();
}

void Partida::nuevaVaca()
{
  printf("Holapartida %p\n",this);
  this->currentVaca=new Vaca(this);
  this->vacas->append(this->currentVaca);
}

