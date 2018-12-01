#include "frmMain.h"

frmMain::frmMain() {
  setupUi(this);
  this->showMaximized();
  this->mem=new Mem();
  this->game=NULL;
}

frmMain::~frmMain() {
}

void frmMain::on_actionJuego4Reyes_triggered(bool checked){
  if (this->game!=NULL){
    this->game->close();
    delete this->game;
  }
  
  this->game=new wdgGame(this->mem,4);
  this->Ui_frmMain::layout->addWidget(this->game);
}

void frmMain::on_actionJuego8Reyes_triggered(bool checked){
  this->game=new wdgGame(this->mem,8);
  this->Ui_frmMain::layout->addWidget(this->game);
}
