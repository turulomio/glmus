#include "baraja.h"

Baraja::Baraja()
{
  this->cartas=new QList<Carta*>();
  this->monton=new QList<Carta*>();
  this->centro=new QList<Carta*>();
  for (int i=1; i<5;i++){//Recorre los palos
    for (int j=1; j<11; j++){
      Carta *a=new Carta(i,j);
      a->setHide(true);
      this->cartas->append(a);
      this->monton->append(a);
    }
  }
//  this->darCarta();
}

Baraja::~Baraja()
{

}

Carta* Baraja::darCarta()
{
  int pos=qrand() % this->monton->count();
//   qDebug()<< qrand()<< pos;
  Carta *c=this->monton->at(pos);
  this->monton->removeAt(pos);
  return c;
  
}

void Baraja::agrupar()
{
  this->monton->clear();
  foreach(Carta *c, *this->cartas){
    this->monton->append(c);
  }
  this->centro->clear();
}