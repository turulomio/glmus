#ifndef JUEGO_H
#define JUEGO_H

#include "baraja.h"
#include "partida.h"
#include "sleeper.h"

class Baraja;
class Partida;
class wdgGame;
class Sleeper;

class Juego: public QObject
{
Q_OBJECT
public:
    Juego(Partida *partida);
    virtual ~Juego();
    Baraja *baraja;
    Partida *partida;
    /**
     * 0 mus, 1 grande, 2 chica, 3 tenerpares, 4 pares, 5 tener juego, 6 juego, 7 punto
     */
    int section;
    void quienEmpieza();
    void repartirCartas(bool seguidas);
    void jugarMus();
signals:
    void requestPaint(int turno, Jugador *jugador);
public slots:
    void empezar();
 
};

#endif // JUEGO_H
