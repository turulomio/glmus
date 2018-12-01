#ifndef _WDGGAME_H
#define _WDGGAME_H

#include <QtGui/QMainWindow>
#include <QtGui/QGraphicsScene>
#include <QtCore/QTimer>
#include "ui_wdgGame.h"
#include "mem.h"
#include "partida.h"

class Partida;

class wdgGame : public QWidget, public Ui_wdgGame {
Q_OBJECT

public:
  wdgGame(Mem *mem, int numreyes);
  virtual ~wdgGame();
  QGraphicsScene *scene;
  Mem *mem;
  Partida *partida;
  QGraphicsTextItem *leds;
//   QTimer *timer;
public slots:
  void actualizarCartas();
  void actualizarLeds();
  void actualizarSection();
  void clearLeds();
protected slots:
  void on_cmdMus_released();
  void on_cmdNoMus_released();
  void on_cmdHastaCompanero_released();
};
#endif 

