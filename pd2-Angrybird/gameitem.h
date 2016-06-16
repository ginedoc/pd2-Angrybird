#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPainter>
#include <QTransform>
#include <QtMath>
#include <QDebug>


class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World * world);
    ~GameItem();

    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);

    void set_boundingType(int type);
    int get_BoundingType();
    void collid_handle(int type);

public slots:
    void paint();
//    virtual void collide() = 0;
protected:
    b2Body *g_body;
    QGraphicsPixmapItem g_pixmap;
    QSizeF g_size;
    b2World *g_world;
    static QSizeF g_worldsize, g_windowsize;
private:
    int bounding_type;
};

#endif // GAMEITEM_H
