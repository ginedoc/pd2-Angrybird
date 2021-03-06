#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QPushButton>
#include <QLabel>


#include <contactlistener.h>
#include "gameitem.h"
#include "land.h"
#include "bird.h"
#include "yellow_bird.h"
#include "enemy.h"
#include "barrier.h"
#include "sling.h"
#include "genbird.h"
#include "black_bird.h"
#include "white_bird.h"
#include "wall.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *, QEvent *event);
    void closeEvent(QCloseEvent *);
    void ToWin();
    void delay(int);
signals:
    //closing the game
    void quitGame();
    void winGame();
private slots:
    void tick();
    void win();
    void restart();
    void QUITSLOT();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    b2World * world;
    QList<GameItem *> itemlist;
    QList<GameItem *> birdlist;
    QTimer timer;

    // Value of Sling
    int SlingX;
    int SlingY;
    int Sling_Radius;
    // Event Filter
    QPointF Record_po;
    int velocity;
    float angleX;
    float angleY;
    int temp;
    int type;

    // in Game
    Bird * birdie;
    QPushButton *quit_button;
    QPushButton *restart_button;
};

#endif // MAINWINDOW_H
