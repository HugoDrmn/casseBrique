#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene.setSceneRect(0,0,LARGEUR,HAUTEUR);



    //creation de la raquette
    laRaquette=new QGraphicsRectItem(LARGEUR/2-LARGEURRAQUETTE/2,HAUTEUR-60,LARGEURRAQUETTE,HAUTEURRAQUETTE);
    QPen contour(Qt::RoundJoin);
    laRaquette->setPen(contour);
    QPixmap monImageRaquette("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/raquette.png");
    laRaquette->setBrush(monImageRaquette);
    laRaquette->setZValue(2);
    scene.addItem(laRaquette);

    //creation ma balle
    maBoule=new QGraphicsBalleCollisionItem(0,0,LARGEURBALLE,LARGEURBALLE,laRaquette,this);
    maBoule->setBrush(QBrush(Qt::green));
    maBoule->setPos(LARGEUR/2,HAUTEUR-85);
    maBoule->setZValue(2);
    scene.addItem(maBoule);

    //creation vue
    maVue = new QGraphicsViewPerso(this);
    maVue->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
    maVue->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    maVue->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
    maVue->setCursor(Qt::BlankCursor);



    maVue->setScene(&scene);
    maVue->show();
    connect(maVue, &QGraphicsViewPerso::positionSouris, this, &Widget::onQGraphicsView_obtenirPositionSouris);

    connect(&timer,&QTimer::timeout,&scene,&QGraphicsScene::advance);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

    ui->pushButton_lancer->setEnabled(true);
    ui->pushButton->setDisabled(true);

    if(ui->radioButton_gradient->isChecked())
    {
        QColor invisible(0,0,0,0);
        QColor noir(0,0,0);
        QColor roseSombre(80,5,20);
        QColor rose(170,18,50);
        QColor rouge(255,25,40);
        QColor orangeJaune(255,200,0);
        QColor blanc(255,255,255);

        QPixmap textureFlammes("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/FondEnfer.png");

        maVue->setBackgroundBrush(textureFlammes);
        maVue->fitInView(scene.sceneRect(),Qt::KeepAspectRatio);
        maVue->show();



        QPixmap fondBrique("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/BriquesEnfer.png");
        QPen contourBriques(invisible);

        int num=0;
        int numLigne=0;
        for (int j=20;j<=320;j+=50) {


            for(int i=20;i<=980;i+=120)
            {
                obstacles[num]=new QGraphicsRectItem(0,0,100,30);
                obstacles[num]->setPos(i,j);

                obstacles[num]->setPen(contourBriques);
                obstacles[num]->setBrush(fondBrique);

                scene.addItem(obstacles[num]);
                num++;
            }
            numLigne++;
        }
    }
    if(ui->radioButton_foret->isChecked())
    {

        QColor invisible(0,0,0,0);
        QColor noir(0,0,0);

        QGraphicsRectItem *piquesItem = new QGraphicsRectItem(0,0,1100,720);

        QLinearGradient colorGradientFond(QPointF(550,720) , QPointF(550,0));
        colorGradientFond.setColorAt(0,invisible);
        colorGradientFond.setColorAt(1,noir);


        QPixmap textureFond("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/FondForet.png");




        piquesItem->setZValue(3);
        scene.addItem(piquesItem);

        maVue->setBackgroundBrush(textureFond);
        maVue->fitInView(scene.sceneRect(),Qt::KeepAspectRatio);
        maVue->show();


        QPixmap fondBrique("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/BriquesForet.png");
        QPen contourBriques(invisible);

        int num=0;
        int numLigne=0;
        for (int j=20;j<=320;j+=50) {


            for(int i=20;i<=980;i+=120)
            {
                obstacles[num]=new QGraphicsRectItem(0,0,100,30);
                obstacles[num]->setPos(i,j);

                obstacles[num]->setPen(contourBriques);
                obstacles[num]->setBrush(fondBrique);

                obstacles[num]->setZValue(2);
                scene.addItem(obstacles[num]);
                num++;
            }
            numLigne++;
        }
    }
    if(ui->radioButton_donjon->isChecked())
    {
        QColor invisible(0,0,0,0);
        QColor noir(0,0,0);

        QGraphicsRectItem *piquesItem = new QGraphicsRectItem(0,0,1100,720);

        QLinearGradient colorGradientFond(QPointF(550,720) , QPointF(550,0));
        colorGradientFond.setColorAt(0,invisible);
        colorGradientFond.setColorAt(1,noir);


        QPixmap textureFond("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/FondDonjon.png");




        piquesItem->setZValue(3);
        scene.addItem(piquesItem);

        maVue->setBackgroundBrush(textureFond);
        maVue->fitInView(scene.sceneRect(),Qt::KeepAspectRatio);
        maVue->show();


        QPixmap fondBrique("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/BriquesDonjon.png");
        QPen contourBriques(invisible);

        int num=0;
        int numLigne=0;
        for (int j=20;j<=320;j+=50) {


            for(int i=20;i<=980;i+=120)
            {
                obstacles[num]=new QGraphicsRectItem(0,0,100,30);
                obstacles[num]->setPos(i,j);

                obstacles[num]->setPen(contourBriques);
                obstacles[num]->setBrush(fondBrique);

                scene.addItem(obstacles[num]);
                num++;
            }
            numLigne++;
        }
    }

    QColor invisible(0,0,0,0);
    if(ui->radioButton_Spirale->isChecked()){

        QPen contourBoule(invisible);
        maBoule->setPen(contourBoule);
        QPixmap texturePiques("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/Spirale.png");
        maBoule->setBrush(texturePiques);
    }
    if(ui->radioButton_FootBall->isChecked()){

        QPen contourBoule(invisible);
        maBoule->setPen(contourBoule);
        QPixmap texturePiques("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/Ballon.png");
        maBoule->setBrush(texturePiques);
    }
    if(ui->radioButton_Crane->isChecked()){

        QPen contourBoule(invisible);
        maBoule->setPen(contourBoule);
        QPixmap texturePiques("/home/USERS/ELEVES/SNIR2018/hdarmon/casseBrique/Head.png");
        maBoule->setBrush(texturePiques);
    }

    maBoule->setPos(LARGEUR/2,HAUTEUR-85);
    scene.addItem(maBoule);


}
void Widget::onQGraphicsView_obtenirPositionSouris(QPointF _positionSouris)
{
    if(_positionSouris.rx() > LARGEURRAQUETTE/2 && _positionSouris.rx()<LARGEUR-LARGEURRAQUETTE/2 )
    {
        laRaquette->setX(_positionSouris.rx()-LARGEUR/2);
        if(debut==false)
        {
            maBoule->setPos(_positionSouris.rx()-10,HAUTEUR-85);
        }
    }
}

bool Widget::viePerdu(int Score, int nbVie)
{
    debut =false;
    timer.stop();

    if(nbVie>-1)
    {
        ui->label_NbVies->setText(QString::number(nbVie));
    }

    qDebug() << nbVie;

    if(nbVie==0)
    {
        QMessageBox padpo;
        padpo.setText("Vous avez perdu\n Pas de chance \n Score:"+QString::number(Score));
        padpo.exec();
        nbVie =3;
    }


}

void Widget::onQGraphicsView_Score(int Score)
{
    ui->label_score->setText(QString::number(Score));
    if(Score==5355)
    {
        timer.stop();
        QMessageBox gg;
        gg.setText("Vous avez gagné\nScore: "+QString::number(Score));
        gg.exec();
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        qDebug() << "gauche";
        if(laRaquette->x() > 0-LARGEUR/2+LARGEURRAQUETTE-LARGEURRAQUETTE/2){
            laRaquette->setX(laRaquette->x()-35);
        }
        if(debut==false)
        {
            maBoule->setPos(laRaquette->x()+LARGEUR/2-5,laRaquette->y()+HAUTEUR-60-HAUTEURRAQUETTE-LARGEURBALLE/2);
        }
        break;
    case Qt::Key_Right:
        qDebug() << "droite";
        if(laRaquette->x() < LARGEUR/2-LARGEURRAQUETTE/2){
            laRaquette->setX(laRaquette->x()+35);
        }
        if(debut==false)
        {
            maBoule->setPos(laRaquette->x()+LARGEUR/2-5,laRaquette->y()+HAUTEUR-60-HAUTEURRAQUETTE-LARGEURBALLE/2);
        }
        break;
    case Qt::Key_Space:
        qDebug() << "jouer";
        Widget::on_pushButton_lancer_clicked();
        break;
    }
}

float Widget::obtenirVitesse(float odd)
{
    if(ui->radioButton_facile->isChecked())
    {
        vitesse=0.1;
    }
    if(ui->radioButton_normal->isChecked())
    {
        vitesse=1;
    }
    if(ui->radioButton_difficile->isChecked())
    {
        vitesse=4;
    }
    return vitesse;
}

void Widget::on_pushButton_lancer_clicked()
{
   /* if(ui->radioButton_facile)
    {
        timer.start(20);
    }
    if(ui->radioButton_normal)
    {*/
        timer.start(10);
   /* }
    if(ui->radioButton_difficile)
    {
        timer.start(8);
    }*/

    debut=true;
    ui->pushButton->setDisabled(true);
}

