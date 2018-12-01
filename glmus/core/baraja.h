#ifndef BARAJA_H
#define BARAJA_H

#include <QtCore/QList>
#include <qglobal.h>
#include <QtDebug>
#include "carta.h"

class Carta;
class Baraja
{

public:
    Baraja();
    virtual ~Baraja();
    
    /**
     * Todas las cartas
     */
    QList<Carta*> *cartas;
    
    /**
     * Cartas en el montón, es decir sin dar
     */
    QList<Carta*> *monton;
    
    /**
     * Cartas descartadas, se colocan en el centro
     */
    QList<Carta*> *centro;
    
    /**
     * Saca una carta del montón aleatoriamente.
     */
    Carta* darCarta();
    
    /**
     * Mete todas las cartas en el monton
     */
    void agrupar();
};

#endif // BARAJA_H
