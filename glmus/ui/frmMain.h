#ifndef _FRMMAIN_H
#define _FRMMAIN_H

#include <QtGui/QMainWindow>
#include <QDebug>
#include "ui_frmMain.h"
#include "wdgGame.h"
#include "mem.h"

class frmMain : public QMainWindow, public Ui_frmMain {
Q_OBJECT

public:
  frmMain();
  virtual ~frmMain();
  wdgGame *game;
  Mem *mem;
protected slots:
  void on_actionJuego4Reyes_triggered(bool);
  void on_actionJuego8Reyes_triggered(bool);
};
#endif /* _FRMMAIN_H */

