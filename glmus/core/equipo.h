#ifndef EQUIPO_H
#define EQUIPO_H

#include "jugador.h"
class Equipo
{

public:
    Equipo();
    virtual ~Equipo();
    int puntuacion;//Puntuación en esta vaca
    int vacasganadas;
    QList <Jugador *> *miembros;
    void asignarMiembros(Jugador *uno, Jugador *dos);
};

#endif // EQUIPO_H
