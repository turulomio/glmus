#include "setjugadores.h"

SetJugadores::SetJugadores()
{
  this->arr=new Jugador[4];
  this->arr[0].id=0;
  this->arr[1].id=1;
  this->arr[2].id=2;
  this->arr[3].id=3;
  this->arr[3].nombre="Mariano";
  this->arr[3].ia=false;
  
  //Deberá cambiarse
  this->mano=NULL;
  printf("Hola setjugadores %p\n",this->mano);
  this->turno=NULL;
  this->reparte=NULL;
  
}

SetJugadores::~SetJugadores()
{
}

/**
 * Se hace así porque habrá cambio de turno y de mano
 */
Jugador * SetJugadores::nextJugador(Jugador *actual)
{
  if (actual->id==3) {
    return &this->arr[0];
  } else {
    return &this->arr[actual->id+1];
  }

}

/**
 * Se hace así porque habrá cambio de turno y de mano
 */
Jugador * SetJugadores::beforeJugador(Jugador *actual)
{
  if (actual->id==0) {
    return &this->arr[3];
  } else {
    return &this->arr[actual->id-1];
  }

}

void SetJugadores::nextMano()
{
  this->mano=this->nextJugador(this->mano);
  this->turno=this->mano;
  this->reparte=this->nextJugador(this->reparte);

}


void SetJugadores::nextTurno()
{
  this->turno=this->nextJugador(this->turno);

}


