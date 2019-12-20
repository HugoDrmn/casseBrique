#ifndef QGRAPHICSVIEWPERSO_H
#define QGRAPHICSVIEWPERSO_H

#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>
#define LARGEUR 1100
#define HAUTEUR 720
#define NBOBSTACLES 50
#define LARGEURRAQUETTE 85
#define HAUTEURRAQUETTE 15
#define LARGEURBALLE 25
#define LARGEURBRIQUE 100
#define HAUTEURBRIQUE 30

class QGraphicsViewPerso : public QGraphicsView
{
    Q_OBJECT

public:
    QGraphicsViewPerso(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void positionSouris(QPoint pos);
};

#endif // QGRAPHICSVIEWPERSO_H
