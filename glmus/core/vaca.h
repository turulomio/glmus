#ifndef VACA_H
#define VACA_H

#include "juego.h"
//Conjunto de Juegos
class Partida;
class Juego;
class Vaca
{

public:
    Vaca(Partida *partida);
    virtual ~Vaca();
    QList <Juego *> *juegos;
    void nuevoJuego();
    Juego *currentJuego;
    Partida *partida;
};

#endif // VACA_H
