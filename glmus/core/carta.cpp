#include "carta.h"

Carta::Carta(int palo, int valor)
{
  this->palo=palo;
  this->valor=valor;
  this->hide=false;
  this->jugador=NULL;
  this->position=0;
  this->setPixmap(this->qpixmap());//99x159

}

Carta::~Carta()
{

}

QPixmap Carta::qpixmap(){
  if (this->hide==true){
    return QPixmap(":/pc.spanish/back.png");
  } else{
    QString resultado;
    QString valor;
    switch (this->palo){
	case 1:
	    resultado="oros";
	    break;
	case 2:
	    resultado="copas";
	    break;
	case 3:
	    resultado="espadas";
	    break;
	case 4:
	    resultado="bastos";
	    break;
    }
    if (this->valor<=7){
      valor=QString("%1").arg(this->valor);
    } else if (this->valor==8){
      valor=QString("J");
    } else if (this->valor==9){
      valor=QString("Q");
    } else if (this->valor==10){
      valor=QString("K");
    }
      
    resultado=QString(":/pc.spanish/%1%2.png").arg(resultado).arg(valor);
    return QPixmap(resultado);
  }
}

void Carta::setHide(bool hide)
{
  this->hide=hide;
  this->setPixmap(this->qpixmap());//99x159
}


/*Si el jugador es None, la carta se pone en el centro
 Jugador 0 a la right
 1 up
 2 left
 3 down
 */
void Carta::setPosition(Jugador* jugador, int posicion)
{
  this->jugador=jugador;
  this->position=posicion;
  
  //Separación entre cartas y tablero de 10 empezando en 0.0
  if (this->jugador==NULL){
    switch(posicion){
      case 0:
	this->setRotation(270);
	this->setPos(620,179+99-129);
	break;
      case 1:
	this->setRotation(180);
	this->setPos(179+99-129,10+159);
	break;
      case 2:
	this->setRotation(90);
	this->setPos(10+159,506+129);
	break;
      case 3:
	this->setPos(506+129,620);
	break;
      case 4:
	this->setPos(320,256);
	break;
	
    }
    return;
  }  
  if (this->jugador->id==0){
    this->setRotation(270);
    switch(posicion){
      case 0:
	this->setPos(620,179+99);
	break;
      case 1:
	this->setPos(620,288+99);
	break;
      case 2:
	this->setPos(620,397+99);
	break;
      case 3:
	this->setPos(620,506+99);
	break;
	
    }
  }  
  if (this->jugador->id==1){
    this->setRotation(180);
    switch(posicion){
      case 0:
	this->setPos(179+99,10+159);
	break;
      case 1:
	this->setPos(288+99,10+159);
	break;
      case 2:
	this->setPos(397+99,10+159);
	break;
      case 3:
	this->setPos(506+99,10+159);
	break;
	
    }
  }    
  if (this->jugador->id==2){
    this->setRotation(90);
    switch(posicion){
      case 0:
	this->setPos(10+159,179);
	break;
      case 1:
	this->setPos(10+159,288);
	break;
      case 2:
	this->setPos(10+159,397);
	break;
      case 3:
	this->setPos(10+159,506);
	break;
    }
  }
  if (this->jugador->id==3){
    switch(posicion){
      case 0:
	this->setPos(179,620);
	break;
      case 1:
	this->setPos(288,620);
	break;
      case 2:
	this->setPos(397,620);
	break;
      case 3:
	this->setPos(506,620);
	break;
	
    }
  }  
}
