#include "jugador.h"

Jugador::Jugador()
{
  this->cartas=new QList<Carta*>();
  this->ia=true;
  this->pidemus=-1;
}

Jugador::~Jugador()
{

}

void Jugador::pedirCarta(Baraja* baraja)
{
  this->speaks=new QStringList();
  Carta *c=baraja->darCarta();
  c->setHide(false);//Levanta carta cuando funcione solo con id=3
  this->cartas->append(c);
}



void Jugador::showCartas(){
  int i=0;
  foreach( Carta *c, *this->cartas){
    c->setPosition(this,i);
    i++;
  }
}

bool Jugador::IAquiereMus()
{
  if (this->tieneJuego() && this->tienePares()){
    this->speaks->append(this->trUtf8("No hay mus"));
    return false;
  }
  this->speaks->append(this->trUtf8("Mus"));
  return true;

}

bool Jugador::tieneJuego()
{
  int suma=0;
  foreach( Carta *c, *this->cartas){
    suma=suma+c->valor;
  }
  if (suma>31){
    return true;
  }else{
    return false;
  }

}

bool Jugador::tienePares()
{
  if (this->cartas->at(0)->valor==this->cartas->at(1)->valor) return true;
  if (this->cartas->at(0)->valor==this->cartas->at(2)->valor) return true;
  if (this->cartas->at(0)->valor==this->cartas->at(3)->valor) return true;
  if (this->cartas->at(1)->valor==this->cartas->at(2)->valor) return true;
  if (this->cartas->at(1)->valor==this->cartas->at(3)->valor) return true;
  if (this->cartas->at(2)->valor==this->cartas->at(3)->valor) return true;
  return false;
}
