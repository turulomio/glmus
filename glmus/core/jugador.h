#ifndef JUGADOR_H
#define JUGADOR_H

#include "baraja.h"
#include <stdio.h>
#include <QtDebug>
class Baraja;
class Carta;

class Jugador:public QObject
{
Q_OBJECT
public:
    Jugador();
    virtual ~Jugador();
    int id;
    bool ia;
    QString nombre; 
    QList<Carta*> *cartas;
    void pedirCarta(Baraja *baraja);
    void showCartas();
    bool tienePares();
    bool tieneJuego();
    bool IAquiereMus();
    int pidemus;//Variable que almacena si el jugador ha pedido mus -1, no ha pedido, 0 no pidemus, 1 pidemus, 2 hasta alla
    QStringList *speaks;
};

#endif // JUGADOR_H
