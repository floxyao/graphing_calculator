TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#LIBS += -L "C:\Users\admin\Documents\SFML\SFML-2.3.2\lib"
#LIBS += -L "C:\Users\admin\Documents\SFML\SFML-2.3.2\bin"
#LIBS += -L"../../SFML-2.3.2/lib"
#LIBS += -L"../../SFML-2.3.2/bin"
#LIBS += -L"..\..\SFML-2.3.2\lib"
#LIBS += -L"..\..\SFML-2.3.2\bin"

LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#INCLUDEPATH += "C:\Users\admin\Documents\SFML\SFML-2.3.2\include"
#DEPENDPATH += "C:\Users\admin\Documents\SFML\SFML-2.3.2\include"
#INCLUDEPATH += "..\..\SFML-2.3.2\include"
#DEPENDPATH += "..\..\SFML-2.3.2\include"

SOURCES += main.cpp

HEADERS += \
    queue.h \
    const.h \
    util.h \
    number.h \
    token.h \
    operator.h \
    expression.h \
    node.h \
    mystack.h \
    point.h \
    graph.h \
    game.h
