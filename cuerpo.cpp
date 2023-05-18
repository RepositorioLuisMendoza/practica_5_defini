#include "cuerpo.h"

cuerpo::cuerpo(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
    complete = new QPixmap(":/imagenes/pngwing.com.png");
    image = 0;
    int ANCHO_ESCENA = 500;


    *complete = complete->copy(580, 0, 35 * 1, 35 * 3);
    setPos(150, 76);
    actual = new QPixmap;
    time = new QTimer;
    connect(time, SIGNAL(timeout()), this, SLOT(actualiza_sprite()));
    time->start(100);
}

void cuerpo::select_sprite(int x, int y)
{
    *actual = complete->copy(35 * x, 35 * y, 35, 35);
    setPixmap(*actual);
}

void cuerpo::actualiza_sprite()
{



    if (image<=2)
    {
        select_sprite(0,image);
        image++;
    }
    else
    {
        image=0;
    }




}


void cuerpo::Move_arriba()
{
    posy -= 1*velocidad;
    setPos(posx, posy);
    actualiza_sprite();
    //setRotation(-80);
}

void cuerpo::Move_abajo()
{
    posy += 1*velocidad;
    setPos(posx, posy);
    actualiza_sprite();
    //setRotation(80);
}

void cuerpo::Move_izquierda()
{
    posx -= 1*velocidad;
    setPos(posx, posy);
    actualiza_sprite();
    //setRotation(180);
}

void cuerpo::Move_derecha()
{
    posx += 1*velocidad;
    setPos(posx, posy);
    actualiza_sprite();
    //setRotation(0);

}

void cuerpo::muerte_personaje()
{

    while (muerte<11)
    {
        select_sprite(0,muerte);
        muerte++;
    }
    muerte=0;
}

