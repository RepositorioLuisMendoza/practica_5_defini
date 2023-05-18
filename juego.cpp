#include "juego.h"

juego::juego()
{
    QPixmap imagen;
    QBrush l;
    QImage r;
    r.load(":/imagenes/fondo.jpeg");
    l.setTextureImage(r);
    imagen.load(":/imagenes/fondo.jpeg");
    bolita_amarilla = new cuerpo(0,0,0);
    addItem(bolita_amarilla);
    setBackgroundBrush(l);
    //bolita_amarilla->select_sprite(1,3);
    //setFocus();//conecta las teclas
}

void juego::keyPressEvent(QKeyEvent *event)
{
    // Movimiento de la bolita amarilla según las teclas de flecha
    if (event->type() == QKeyEvent::KeyPress) {
        switch (event->key()) {
            case Qt::Key_Up:
                bolita_amarilla->Move_arriba();
                break;
            case Qt::Key_Down:
                bolita_amarilla->Move_abajo();
                break;
            case Qt::Key_Left:
                bolita_amarilla->Move_izquierda();
                break;
            case Qt::Key_Right:
                bolita_amarilla->Move_derecha();
                break;
            default:
                QGraphicsScene::keyPressEvent(event);
        }
    }
}
