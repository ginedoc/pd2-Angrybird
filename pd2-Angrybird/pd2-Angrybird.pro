#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T21:18:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-Angrybird
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameitem.cpp \
    bird.cpp \
    land.cpp \
    enemy.cpp \
    barrier.cpp \
    sling.cpp \
    red_bird.cpp \
    yellow_bird.cpp \
    contactlistener.cpp \
    black_bird.cpp \
    white_bird.cpp

HEADERS  += mainwindow.h \
    land.h \
    ../Box2D/Box2D/Box2D.h \
    ../Box2D/Box2D/Collision/Shapes/b2ChainShape.h \
    ../Box2D/Box2D/Collision/Shapes/b2CircleShape.h \
    ../Box2D/Box2D/Collision/Shapes/b2EdgeShape.h \
    ../Box2D/Box2D/Collision/Shapes/b2PolygonShape.h \
    ../Box2D/Box2D/Collision/Shapes/b2Shape.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2CircleContact.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2Contact.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2ContactSolver.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    ../Box2D/Box2D/Dynamics/Contacts/b2PolygonContact.h \
    ../Box2D/Box2D/Collision/b2BroadPhase.h \
    ../Box2D/Box2D/Collision/b2Collision.h \
    ../Box2D/Box2D/Collision/b2Distance.h \
    ../Box2D/Box2D/Collision/b2DynamicTree.h \
    ../Box2D/Box2D/Collision/b2TimeOfImpact.h \
    ../Box2D/Box2D/Dynamics/b2Body.h \
    ../Box2D/Box2D/Dynamics/b2ContactManager.h \
    ../Box2D/Box2D/Dynamics/b2Fixture.h \
    ../Box2D/Box2D/Dynamics/b2Island.h \
    ../Box2D/Box2D/Dynamics/b2TimeStep.h \
    ../Box2D/Box2D/Dynamics/b2World.h \
    ../Box2D/Box2D/Dynamics/b2WorldCallbacks.h \
    ../Box2D/Box2D/Dynamics/Joints/b2DistanceJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2FrictionJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2GearJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2Joint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2MotorJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2MouseJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2PulleyJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2RopeJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2WeldJoint.h \
    ../Box2D/Box2D/Dynamics/Joints/b2WheelJoint.h \
    ../Box2D/Box2D/Rope/b2Rope.h \
    bird.h \
    gameitem.h \
    enemy.h \
    barrier.h \
    sling.h \
    red_bird.h \
    yellow_bird.h \
    contactlistener.h \
    black_bird.h \
    white_bird.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../Box2D_v2.1.2/Box2D/Box2D/CMakeLists.txt

LIBS += -L. -lBox2D

RESOURCES += \
    ../Pic/pic.qrc

