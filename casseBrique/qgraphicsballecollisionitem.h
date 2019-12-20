#ifndef QGRAPHICSBALLECOLLISIONITEM_H
#define QGRAPHICSBALLECOLLISIONITEM_H


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QtDebug>
#include <QMediaPlayer>
#define LARGEUR 1100
#define HAUTEUR 720
#define NBOBSTACLES 50
#define LARGEURRAQUETTE 85
#define HAUTEURRAQUETTE 15
#define LARGEURBALLE 25
#define LARGEURBRIQUE 100
#define HAUTEURBRIQUE 30

class Widget;

class QGraphicsBalleCollisionItem : public QGraphicsEllipseItem
{
public:
    QGraphicsBalleCollisionItem(qreal x,qreal y, qreal width, qreal height, QGraphicsRectItem *_raquette,Widget *_widget, QGraphicsItem *parent = nullptr);
protected:
    void advance(int step) override;

private:
    QGraphicsRectItem *raquette;
    qreal dx;
    qreal dy;
    Widget * widget;
    int valeurScore = 0;
     int nbVie=3;
    QMediaPlayer player;
};

#endif // QGRAPHICSBALLECOLLISIONITEM_H
