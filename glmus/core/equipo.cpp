#include "equipo.h"

Equipo::Equipo()
{
  this->miembros=new QList<Jugador*>();
}


Equipo::~Equipo()
{

}

void Equipo::asignarMiembros(Jugador *uno, Jugador *dos)
{
  this->miembros->append(uno);
  this->miembros->append(dos);
}
