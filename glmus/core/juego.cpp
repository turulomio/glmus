#include "juego.h"

Juego::Juego(Partida *partida)
{
  this->baraja=new Baraja();
  this->partida=partida;  
  this->section=0;
  //Inicializa jugadores
  for (int i=0; i<4; i++){
    this->partida->jugadores->arr[i].pidemus=-1;
  }
}

Juego::~Juego()
{

}

void Juego::quienEmpieza(){
  this->partida->jugadores->mano=&this->partida->jugadores->arr[3];
  this->partida->jugadores->turno=&this->partida->jugadores->arr[3];
  this->partida->jugadores->reparte=&this->partida->jugadores->arr[2];
}

void Juego::repartirCartas(bool seguidas)
{
  for (int j=0; j<4;j++){
    Jugador *jugador=&this->partida->jugadores->arr[j];
    int numcartas=jugador->cartas->count();
    for (int c=0; c<4-numcartas;c++){
      jugador->pedirCarta(this->baraja);
    }
    jugador->showCartas();
  }
}

void Juego::empezar()
{
  this->quienEmpieza();
  this->repartirCartas(true);
  this->partida->wdg->actualizarSection();
  this->partida->wdg->actualizarCartas();
  this->partida->wdg->clearLeds();
  this->jugarMus();
}


void Juego::jugarMus()
{
  for(int i=0;i<4;i++){
    Jugador *turno=this->partida->jugadores->turno;
    if (turno->ia==true){
      if (turno->IAquiereMus()==true){
	turno->pidemus=1; 
	qDebug() << turno->id  << " mus";
	this->partida->wdg->actualizarLeds();
      }else {
	turno->pidemus=0;
	qDebug() << turno->id  << "no hay mus";
	this->partida->wdg->actualizarLeds();
	QApplication::processEvents();
	break;
      }
      QApplication::processEvents();
      Sleeper::sleep(1);
    } else {
      
	qDebug() << turno->id  << "esperando mus";
      this->partida->wdg->grpMus->setVisible(true);
      while(turno->pidemus==-1){
	QApplication::processEvents();
      Sleeper::sleep(1);
      }
      this->partida->wdg->grpMus->setVisible(false);
    }
    this->partida->jugadores->nextTurno(); 
  }
  
  this->partida->jugadores->turno=this->partida->jugadores->mano;
  Sleeper::sleep(1);
  this->partida->currentVaca->currentJuego->section=1;
  this->partida->wdg->actualizarSection();//Para que salga grande
  this->partida->wdg->clearLeds();
  this->partida->jugadores->arr[2].speaks->append("COPON");
  this->partida->wdg->actualizarLeds();

}


