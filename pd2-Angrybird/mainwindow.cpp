#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

#define RED_BIRD 0
#define YELLOW_BIRD 1
#define BLACK_BIRD 2
#define WHITE_BIRD 3

static int bird_turn = 0;
int enemy_num;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    SlingX(150),SlingY(420),Sling_Radius(150),
    temp(0),type(0)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene();
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(800,600);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/background.png").scaled(800,600));

    // Quit Game button
    quit_button = new QPushButton();
    quit_button->setGeometry(30,0,50,50);
    quit_button->setIcon(QPixmap(":/QUIT.png").scaled(1000,1000));
    connect(quit_button,SIGNAL(pressed()),this,SLOT(QUITSLOT()));
    scene->addWidget(quit_button);
    // Restart Game Button
    restart_button = new QPushButton();
    restart_button->setGeometry(30,60,50,50);
    restart_button->setIcon(QPixmap(":/RESTART.png"));
    connect(restart_button,SIGNAL(pressed()),this,SLOT(restart()));
    scene->addWidget(restart_button);



    // Create World
    b2Vec2 gravity(0.0f, -9.8f);
    world = new b2World(gravity);
    

    // Set screen size
    GameItem::setGlobalSize(QSizeF(40,30),QSizeF(800,600));
    // Create Ground
    itemlist.push_back(new Land(QPixmap(":/GROUND.png").scaled(800,100),world,scene));
    // Create Enemy
    itemlist.push_back(new Enemy(32.0f,10.0f,1.25f,&timer,QPixmap(":/enemy1.png").scaled(45,45),world,scene));
    itemlist.push_back(new Enemy(27.8f,10.0f,1.25f,&timer,QPixmap(":/enemy1.png").scaled(45,45),world,scene));
    // Create Barrier
    itemlist.push_back(new Barrier(22.0f,20.0f,4.5f,&timer,QPixmap(":/wood2.png").scaled(90,10),world,scene,false));
    itemlist.push_back(new Barrier(17.8f,20.0f,4.5f,&timer,QPixmap(":/wood2.png").scaled(90,10),world,scene,false));
    itemlist.push_back(new Barrier(16.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    itemlist.push_back(new Barrier(20.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    itemlist.push_back(new Barrier(24.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));

    itemlist.push_back(new Barrier(32.0f,20.0f,4.5f,&timer,QPixmap(":/wood2.png").scaled(90,10),world,scene,false));
    itemlist.push_back(new Barrier(27.8f,20.0f,4.5f,&timer,QPixmap(":/wood2.png").scaled(90,10),world,scene,false));
    itemlist.push_back(new Barrier(26.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    itemlist.push_back(new Barrier(30.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    itemlist.push_back(new Barrier(34.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    // Create Sling
    itemlist.push_back(new Sling(world,scene));
    // Create bird image (up right)






    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    connect(this,SIGNAL(winGame()),this,SLOT(win()));
    timer.start(1000/60);

    // Listen for Collision
    world->SetContactListener(new ContactListener());
}
bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    QPointF ps = mouseEvent->pos();

    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        // ADD BIRD IMAGE

    }
    if(event->type() == QEvent::MouseMove)
    {
        mouseEvent = static_cast<QMouseEvent*>(event);


        /* TODO : add your code here */
        if(abs(ps.x()-SlingX)<Sling_Radius && abs(ps.y()-SlingY)<Sling_Radius){
            Record_po = QPoint(ps.x()-SlingX , ps.y()-SlingY);
            velocity = sqrt(pow(Record_po.x(),2)+pow(Record_po.y(),2))*4/30;
        }
            //        std::cout << "Move !" << std::endl ;

    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        if(abs(ps.x()-SlingX)<Sling_Radius && abs(ps.y()-SlingY)< Sling_Radius){
            angleX = Record_po.x() / sqrt(pow(Record_po.x(),2)+pow(Record_po.y(),2));
            angleY = Record_po.y() / sqrt(pow(Record_po.x(),2)+pow(Record_po.y(),2));

            if(temp == 0 || temp == 1){
                temp++;
            }
            if(temp == 2){
                qDebug() << bird_turn;
                switch(bird_turn){
                case RED_BIRD:
                {
                    birdie = new Red_Bird(ps.x()/20,(600-ps.y())/20,1.0f,&timer,QPixmap(":/red.png").scaled(40,40),world,scene);
                    birdie->setLinearVelocity(b2Vec2(-velocity*angleX,velocity*angleY));

                    birdie->Sskill();
                    birdlist.push_back(birdie);

                    break;
                }
                case YELLOW_BIRD:
                {
                    birdie = new Yellow_Bird(ps.x()/20,(600-ps.y())/20,1.0f,&timer,QPixmap(":/Yellow.png").scaled(40,40),world,scene);
                    birdie->setLinearVelocity(b2Vec2(-velocity*angleX,velocity*angleY));
                    birdie->Sskill();
                    birdlist.push_back(birdie);

                    break;
                }
                case BLACK_BIRD:
                {
                    birdie = new Black_Bird(ps.x()/20,(600-ps.y())/20,1.0f,&timer,QPixmap(":/black.png").scaled(40,40),world,scene);
                    birdie->setLinearVelocity(b2Vec2(-velocity*angleX,velocity*angleY));
                    birdie->Sskill();
                    birdlist.push_back(birdie);
                    break;
                }
                case WHITE_BIRD:
                {
                    birdie = new White_Bird(ps.x()/20,(600-ps.y())/20,1.0f,&timer,QPixmap(":/white.png").scaled(40,40),world,scene);
                    birdie->setLinearVelocity(b2Vec2(-velocity*angleX,velocity*angleY));
                    birdie->Sskill();
                    birdlist.push_back(birdie);
                    break;
                }
                }

                temp = 0;
                bird_turn++;
//                birdie->remove_bird(scene,world);
            }
        }
        if(bird_turn > 4){
            bird_turn -=1;
            qDebug() << "EXIT";
        }

        // std::cout << "Release !" << std::endl ;
    }

    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    //close event
    emit quitGame();
}

void MainWindow::ToWin()
{

    if(enemy_num == 0) emit winGame();
}

void MainWindow::tick()
{
//    ToWin();
    world->Step(1.0/60,6,2);
    scene->update();
}

void MainWindow::win()
{
    qDebug() << "YOU WIN";
}

void MainWindow::QUITSLOT()
{
    std::cout << "QUIT GAME SIGNAL RECEIVE ! " << std::endl;
}

void MainWindow::restart()
{
    enemy_num = 2;
    temp = 0;

    int t;
    t = itemlist.length();

    for(int i=0;i<t-bird_turn;i++){
        qDebug() << "d" << i+1;
        delete itemlist[i];
    }
        qDebug() << bird_turn << birdlist;


    birdlist.clear();
    itemlist.clear();

    bird_turn = 0;

    world->SetGravity(b2Vec2(100,0));
    delay(1000);
    scene->destroyed();
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);


    world->SetGravity(b2Vec2(0,-9.8));
    // Set screen size
    GameItem::setGlobalSize(QSizeF(40,30),QSizeF(800,600));
    // Create Ground
    itemlist.push_back(new Land(QPixmap(":/GROUND.png").scaled(800,100),world,scene));
    // Quit Game button
    quit_button = new QPushButton();
    quit_button->setGeometry(30,0,50,50);
    quit_button->setIcon(QPixmap(":/QUIT.png").scaled(1000,1000));
    connect(quit_button,SIGNAL(pressed()),this,SLOT(QUITSLOT()));
    scene->addWidget(quit_button);
    // Restart Game Button
    restart_button = new QPushButton();
    restart_button->setGeometry(30,60,50,50);
    restart_button->setIcon(QPixmap(":/RESTART.png"));
    connect(restart_button,SIGNAL(pressed()),this,SLOT(restart()));
    scene->addWidget(restart_button);




    // Create Enemy
    itemlist.push_back(new Enemy(32.0f,10.0f,1.25f,&timer,QPixmap(":/enemy1.png").scaled(45,45),world,scene));
    itemlist.push_back(new Enemy(27.8f,10.0f,1.25f,&timer,QPixmap(":/enemy1.png").scaled(45,45),world,scene));
    // Create Barrier
    itemlist.push_back(new Barrier(22.0f,20.0f,4.5f,&timer,QPixmap(":/wood2.png").scaled(90,10),world,scene,false));
    itemlist.push_back(new Barrier(17.8f,20.0f,4.5f,&timer,QPixmap(":/wood2.png").scaled(90,10),world,scene,false));
    itemlist.push_back(new Barrier(16.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    itemlist.push_back(new Barrier(20.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    itemlist.push_back(new Barrier(24.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));

    itemlist.push_back(new Barrier(32.0f,20.0f,4.5f,&timer,QPixmap(":/wood2.png").scaled(90,10),world,scene,false));
    itemlist.push_back(new Barrier(27.8f,20.0f,4.5f,&timer,QPixmap(":/wood2.png").scaled(90,10),world,scene,false));
    itemlist.push_back(new Barrier(26.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    itemlist.push_back(new Barrier(30.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
    itemlist.push_back(new Barrier(34.0f,10.0f,4.5f,&timer,QPixmap(":/wood1.png").scaled(10,90),world,scene,true));
}

void MainWindow::delay(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
