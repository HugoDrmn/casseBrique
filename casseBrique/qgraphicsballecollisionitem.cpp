#include "qgraphicsballecollisionitem.h"
#include "widget.h"

QGraphicsBalleCollisionItem::QGraphicsBalleCollisionItem(qreal x, qreal y,
                                                         qreal width,
                                                         qreal height,
                                                         QGraphicsRectItem *_raquette,Widget *_widget,
                                                         QGraphicsItem *parent):QGraphicsEllipseItem (x,y,width,height,parent),raquette(_raquette),dx(-2),dy(-2),widget(_widget)
{
    player.setMedia(QUrl::fromLocalFile("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/son.mp3"));
    player.setVolume(100);
}

void QGraphicsBalleCollisionItem::advance(int step)
{
    moveBy(dx,dy);
    qreal largeurBoule=rect().width();
    qreal largeurScene=scene()->width();
    qreal hauteurScene=scene()->height();

    if(x()<=0 || x()>=(largeurScene-largeurBoule))
    {
        dx=-dx;
    }
    if(y()<=0 || y()>=hauteurScene)
    {
        dy=-dy;
    }
    if(y()>=hauteurScene-largeurBoule )
    {
        dy=0;
        dx=0;
        if(nbVie==1)
        {
            nbVie=0;
        }
        if(nbVie==2)
        {
            nbVie=1;
        }
        if(nbVie==3)
        {
            nbVie=2;
        }
        widget->viePerdu(valeurScore,nbVie);
    }


    QList<QGraphicsItem*> listeDesObjetEnCollisions=this->collidingItems();
    if(listeDesObjetEnCollisions.count()>0)
    {
        foreach(QGraphicsItem *objet,listeDesObjetEnCollisions)
        {
            if(objet!=raquette)
            {
                scene()->removeItem(objet);
                player.play();
                if(objet->y()==20)
                {
                    valeurScore += 200;
                }
                if(objet->y()==70)
                {
                    valeurScore += 150;
                }
                if(objet->y()==120)
                {
                    valeurScore += 100;
                }
                if(objet->y()==170)
                {
                    valeurScore += 75;
                }
                if(objet->y()==220)
                {
                    valeurScore += 40;
                }
                if(objet->y()==270)
                {
                    valeurScore += 20;
                }
                if(objet->y()==320)
                {
                    valeurScore += 10;
                }
                widget->onQGraphicsView_Score(valeurScore);

                if(y()<=objet->y()+largeurBoule&&y()>=objet->y()-HAUTEURBRIQUE-largeurBoule)
                {
                    dx=-dx;
                }else
                    if(x()>=objet->x()-largeurBoule&&x()<=objet->x()+LARGEURBRIQUE+largeurBoule)
                    {
                        dy=-dy;
                    }
            }else{
                float vitesse;
                vitesse= widget->obtenirVitesse(vitesse);
                if(dx<0)
                {
                    vitesse=-vitesse;
                }else {
                    vitesse=vitesse;
                }
                int angle=QRandomGenerator::global()->bounded(3);
                if (angle==0)
                {
                    dx=vitesse*2;
                    dy=-2;
                }
                if (angle==1)
                {
                    dx=vitesse*2;
                    dy=-1.9;
                }
                if (angle==2)
                {
                    dx=1.9*vitesse;
                    dy=-2.0;
                }

            }
        }
    }
}
