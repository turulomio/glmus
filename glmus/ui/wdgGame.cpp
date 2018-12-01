#include "wdgGame.h"

wdgGame::wdgGame(Mem *mem, int numreyes) {
  setupUi(this);
  this->mem=mem ;
  this->scene=new QGraphicsScene();
  this->scene->setSceneRect(0,0,789,789);
  this->scene->setItemIndexMethod(QGraphicsScene::NoIndex);
  this->view->setScene(this->scene);
  this->view->setSceneRect(0,0,789,789);
  
  this->leds=new QGraphicsTextItem[4]; 
  this->leds[0].setPos(10+159+436-20,10+159+436);
  this->leds[0].setHtml("<center>.....................................................................................................</center>");
  this->leds[0].setRotation(270);
  this->leds[1].setPos(179+426,179+25);
  this->leds[1].setHtml("<center>.....................................................................................................</center>");
  this->leds[1].setRotation(180);
  this->leds[2].setPos(10+159+10+20,10+159+10);
  this->leds[2].setHtml("<center>.....................................................................................................</center>");
  this->leds[2].setRotation(90);
  this->leds[3].setPos(10+159+10,10+159+10+4*(99+10)-30 );
  this->leds[3].setHtml("<center>.....................................................................................................</center>");
  
  this->label->setText(this->trUtf8("Repartiendo"));
  this->grpEnvidos->setVisible(false);
  this->grpMus->setVisible(false);
  this->grpTengo->setVisible(false);
  
  QFont serifFont("Times", 18, QFont::Bold);
  for (int i=0;i<4;i++){
    this->scene->addItem(&this->leds[i]);
    this->leds[i].setTextWidth(426);
    this->leds[i].setFont(serifFont);
  }
   
  this->partida=new Partida(this->mem,numreyes);
  this->partida->wdg=this;
  //Mete en la scene las cartas
  foreach(Carta *c, *this->partida->currentVaca->currentJuego->baraja->cartas){
    this->scene->addItem(c);
  }
  QTimer::singleShot(1, this->partida->currentVaca->currentJuego, SLOT(empezar()));
}

wdgGame::~wdgGame() {
}

void wdgGame::actualizarLeds(){
  for (int j=0; j<4;j++){
    Jugador *jugador=&this->partida->jugadores->arr[j];
    if (jugador->speaks->count()>0) this->leds[j].setHtml("<center>"+jugador->speaks->last()+"</center>");
  }
}


void wdgGame::clearLeds(){
  for (int j=0; j<4;j++){
    this->leds[j].setHtml("<center></center>");
  }
}

void wdgGame::actualizarSection()
{
  Juego *juego=this->partida->currentVaca->currentJuego;
  if (juego->section==0){
     // 0 mus, 1 grande, 2 chica, 3 tenerpares, 4 pares, 5 tener juego, 6 juego, 7 punto
    this->label->setText(this->trUtf8("Mus"));
  }else if (juego->section==1){
    this->label->setText(this->trUtf8("A Grande"));
  }else if (juego->section==2){
    this->label->setText(this->trUtf8("A Chica"));
  }
}


void wdgGame::actualizarCartas(){
  qDebug()<<"Actualizando\n";  
  
  //Cartas de usuario
  for (int j=0; j<4;j++){
    Jugador *jugador=&this->partida->jugadores->arr[j];
    int i=0;
    foreach( Carta *c, *jugador->cartas){
      c->setPosition(jugador,i);
      i++;
//       qDebug()<<i << c->palo << c->valor << c->jugador->id << c->position;

    }
  }
  //Cartas de monton
  foreach( Carta *c, *this->partida->currentVaca->currentJuego->baraja->monton) {
     c->setPosition(NULL,this->partida->jugadores->mano->id);
  }  
  //Cartas de centro
  foreach( Carta *c, *this->partida->currentVaca->currentJuego->baraja->centro) {
     c->setPosition(NULL,4);
  }  
  
  
}


void wdgGame::on_cmdHastaCompanero_released()
{
  this->partida->jugadores->arr[3].pidemus=2;

}

void wdgGame::on_cmdMus_released()
{

  this->partida->jugadores->arr[3].pidemus=1;
  this->partida->jugadores->arr[3].speaks->append(this->trUtf8("Mus"));
  this->actualizarLeds();
}

void wdgGame::on_cmdNoMus_released()
{

  this->partida->jugadores->arr[3].pidemus=0;
}
