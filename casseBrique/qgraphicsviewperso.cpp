#include "qgraphicsviewperso.h"

QGraphicsViewPerso::QGraphicsViewPerso(QWidget *parent): QGraphicsView (parent)
{
    setMouseTracking(true);
}

void QGraphicsViewPerso::mouseMoveEvent(QMouseEvent *event)
{
    emit positionSouris(event->pos());
}
