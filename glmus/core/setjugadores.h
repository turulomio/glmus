#ifndef SETJUGADORES_H
#define SETJUGADORES_H

#include <QtCore/QList>
#include "jugador.h"

//Se usa para recorrer los jugadores
class SetJugadores
{

public:
    SetJugadores();
    virtual ~SetJugadores();
    Jugador *arr;
    /**
     * Jugador que es mano
     */
    Jugador *mano;
    /**
     * Jugador que le toca decidir en grande, chica...
     */
    Jugador *turno;
    /**
     * Jugador que reparte
     */
    Jugador *reparte;
    Jugador *nextJugador(Jugador *actual);
    Jugador *beforeJugador(Jugador *actual);
    void nextMano();
    void nextTurno();
  QList <Carta*> *cartasinicio;//Array de cartas para ver quien empieza
};

#endif // SETJUGADORES_H
