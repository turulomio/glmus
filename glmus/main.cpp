#include <QtGui/QApplication>
#include <QTime>
#include "ui/frmMain.h"

namespace Palo { enum palos { Oros, Copas, Espadas, Bastos }; };



int main(int argc, char** argv)
{
  
  // Create seed for the random
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    QApplication app(argc, argv);
    frmMain foo;
    foo.show();
    return app.exec();
}
