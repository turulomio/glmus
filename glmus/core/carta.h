#ifndef CARTA_H
#define CARTA_H

#include <QtGui/QPixmap>
#include <QtGui/QPainter>
#include <QtGui/QGraphicsPixmapItem>
#include <QDebug>
#include "jugador.h"

class Jugador;
class Carta : public QGraphicsPixmapItem
{
public:
    Carta(int palo, int valor);
    virtual ~Carta();
    int palo;
    int valor;
    bool hide;//Devuelve si está escondida
    QPixmap qpixmap();
    Jugador *jugador;//Establece el jugador que lo tiene si es null está en monton posicion 0 o centro posicion 1
    int position;
    void setPosition(Jugador *jugador, int posicion);
    void setHide(bool hide);
    
};

#endif // DADO_H
