#ifndef GAME_H
#define GAME_H
#include "graph.h"

/*-------------------------------------------------------
 * Game Class
 --------------------------------------------------------*/
class Game{
public:
    Game();
    void Draw();
    void run();
    void processEvents();
    void update();
    void render();
    void Input(string prompt);

private:
    sf::RenderWindow window;
    Graph g;
};

/*============Game Default Constructors==========*/
/* --------------------------------------------------
 * Game();
 * I input the tokens separately in the constructor
 * Also call the graph object to generate its points and to
 * set the range and number of points on the graph
----------------------------------------------------*/
Game::Game(){
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graph");
    window.setFramerateLimit(60);

    //s = sin
    //c = cos
    //t = tan
    Queue<Token*> inputQ;
    inputQ.Add(new Number(1));
    inputQ.Add(new Operator('-'));
//    inputQ.Add(new Number(10));
    //inputQ.Add(new Operator('t'));
    inputQ.Add(new Operator('x'));
    //inputQ.Add(new Operator('-'));
    inputQ.Add(new Operator('^'));
    //inputQ.Add(new Operator('+'));
    inputQ.Add(new Number(2));
    Expression e(inputQ);
    g.setGraph(e, -50, 50, NUM_OF_POINTS);
    g.generatePoints();
}


/*============Game Member Functions==========*/
/* ------------------------------------------------
/* Run();
 * Will continuosly loops while window is open
 -------------------------------------------------*/
void Game::run(){
    while (window.isOpen()){
        processEvents();
        update();
        render(); //clear/draw/display
        //cin.get();
    }
}
/* ----------------------------------------------
 * processEvents();
 * Takes external input
 -----------------------------------------------*/
void Game::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)){
        switch (event.type){
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                g.ZoomIn(0.90);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                g.ZoomOut(0.90);
            }
        default:
            break;
        }
    }
}

/* ------------------------------------------------
 * Updates();
 * Calls the show graph info from graph object
 * Don't think my graph needs to be constantly updating
 -------------------------------------------------*/
void Game::update(){
    g.ShowGraphInfo();
}

/* ------------------------------------------------
/* Render();
 * Shows and clears display
 -------------------------------------------------*/
void Game::render(){
    window.clear();
    Draw();
    window.display();

}

/* ------------------------------------------------
/* Draw();
 * Draws the picture on the screen
 -------------------------------------------------*/
void Game::Draw(){
    g.Draw(window);
}





#endif // GAME_H
