#include "vaca.h"

Vaca::Vaca(Partida *partida)
{
  this->partida=partida;
  this->juegos=new QList <Juego *>();
  this->nuevoJuego();
}

Vaca::~Vaca()
{

}

void Vaca::nuevoJuego()
{
  this->currentJuego=new Juego(this->partida);
  this->juegos->append(this->currentJuego);

}
