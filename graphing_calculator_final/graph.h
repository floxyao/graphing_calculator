#ifndef GRAPH_H
#define GRAPH_H
#include "expression.h"
#include "point.h"
#include "SFML/Graphics.hpp"

/*-------------------------------------------------------
 * Graph Class
 * Private Member Variables: An infix expression, hi and lo
 * for graph range, and total amount of points on the line
 --------------------------------------------------------*/
class Graph
{
private:
    Expression exp;
    double hi;
    double lo;
    int maxPoints;

public:
    Graph();
    Graph(Expression ifx, double l, double h, int max);

    Queue<Point> setOfPoints;
    double Interval();
    void generatePoints();
    void ZoomIn(double percent);
    void ZoomOut(double percent);
    void Plot(sf::RenderWindow& window);
    void setGraph(Expression ifx, double l, double h, int max);
    void Draw(sf::RenderWindow& window);
    void DrawAxes(sf::RenderWindow& window);
    void CartesianToGrid(double &xPos, double &yPos);
    void ShowGraphInfo();
    double Scale(double x);
    double yIntercept();
    Point ShowRange();
    sf::RectangleShape CreateBox(int x, int y, sf::Color color);
};

/*============Graph Default Constructors==========*/
Graph::Graph(){
    //cout<<endl<<"Graph default"<<endl;
}

/* ---------------------------------------------------
 * Graph();
 * Takes an expression, low/high range, and max number of points
----------------------------------------------------*/
Graph::Graph(Expression ifx, double l, double h, int max){
    exp=ifx;
    hi=h;
    lo=l;
    maxPoints=max;
}

/*================Graph Member Functions==============*/
/* ---------------------------------------------------
 * Draw();
 * Gets called by game
 * Axes are initialized here
 * Plot gets points that are generated and draws the graph
----------------------------------------------------*/
void Graph::Draw(sf::RenderWindow &window){
    //cout<<"Draw: going to plot stuff: "<<endl;
    DrawAxes(window);
    Plot(window);
}

/* ---------------------------------------------------
 * ShowGraphInfo();
 * Shows Domain, Range, Y-intercept, Max/Min, Amplitude
 * Tried to add period and domain as well but had trouble with tokenizing
----------------------------------------------------*/
void Graph::ShowGraphInfo(){
   // cout<<endl<<"========Graph Info=========";
//    cout<<endl<<"f(x) = "; exp.Print();
//    cout<<endl<<"Domain: "; ShowDomain();
//    cout<<endl<<"Range: "<< ShowRange();
//    cout<<endl<<"Y-Int: "<<yIntercept();
//    cout<<endl<<"Max: "<< getMax();
//    cout<<endl<<"Min: "<< getMin();
//    cout<<endl<<"Amp: "<< (getMax()-getMin())/2;
}

/* ---------------------------------------------------
 * yIntercept();
 * Evaluates the expression when x=0
 * Returns the y-intercept
----------------------------------------------------*/
double Graph::yIntercept(){
    return exp.EvalVariable(0);
}

void Graph::CartesianToGrid(double &xPos, double &yPos){
    xPos/=hi/20;
    xPos+=SCREEN_HEIGHT/2;
    yPos/=lo/20;
    yPos=(yPos)+SCREEN_WIDTH/2;
}

/* ---------------------------------------------------
 * Plot();
 * Takes render window to feed to Game function
 * Until the set of points are empty, keep popping
 * and creating boxes based on the points that are popped
 ----------------------------------------------------*/
void Graph::Plot(sf::RenderWindow &window){
    //cout<<"Plot: Going to plot stuff:"<<endl;
    Queue<Point> points=setOfPoints;
    for (int i=0; !points.isEmpty(); i++){
        Point p=points.Remove();
        double x=p.getX()*20;
        double y=p.getY()*20; //multiply by zoom factor

        CartesianToGrid(x, y);
        sf::RectangleShape box = CreateBox(x, y, sf::Color::Cyan);

        window.draw(box);
    }
//    cout<<"Plot: Out of the for loop: "<<endl;
//    cout<<"lo: "<<lo; cout<<endl;
//    cout<<"hi: "<<hi;
}

/* ---------------------------------------------------
 * CreateBox();
 * Draws a box for the game to display on the screen
 * Sets the color and position
 ----------------------------------------------------*/
sf::RectangleShape Graph::CreateBox(int x, int y, sf::Color color){
    sf::RectangleShape box = sf::RectangleShape(sf::Vector2f(1,1));
    box.setFillColor(color);
    box.setPosition(sf::Vector2f(x, y));
    return box;
}

/* ---------------------------------------------------
 * Zoom();
 * Decreases the range by 10%
 ----------------------------------------------------*/
void Graph::ZoomIn(double percent){
    cout<<endl<<"ENTERING Zoom"<<endl;
    lo=lo*percent;
    hi=hi*percent;
}

void Graph::ZoomOut(double percent){
    lo=lo/percent;
    hi=hi/percent;
}

/* ---------------------------------------------------
 * ShowRange();
 * Returns lo and hi value
 ----------------------------------------------------*/
Point Graph::ShowRange(){
    return Point(lo, hi);
}

/* ---------------------------------------------------
 * generatePoints();
 * Evaluates x as a function of y, stores each point
 * in a Queue of points. Each iteration will add the
 * interval value to x, then evaluates y.
----------------------------------------------------*/
void Graph::generatePoints(){
    double interval=Interval();
    //cout<<endl<<"interval: "<<interval<<endl;
    double x=lo;
    double y=exp.EvalVariable(lo);

    for(int i=0; i!=maxPoints; i++){
        setOfPoints.Add(Point(x,y));

//        cout<<"CARTESIAN: "; cout<<Point(x,y);
//        cout<<"            SCREEN: ("<<x+250<<","<<y+250<<")";
//        cout<<endl;

        x+=interval;
        y=exp.EvalVariable(x);
    }
}

/* ---------------------------------------------------
/* Interval();
 * Returns the increment between the amount of points
----------------------------------------------------*/
double Graph::Interval(){
    return abs(hi-lo)/NUM_OF_POINTS;
}

/* ---------------------------------------------------
/* DrawAxes();
 * Draws the axes on the screen
----------------------------------------------------*/
void Graph::DrawAxes(sf::RenderWindow& window){
    //cout<<endl<<"ENTERED DRAW AXES"<<endl;
    sf::RectangleShape yAxis(sf::Vector2f(1000, 1));
    sf::RectangleShape xAxis(sf::Vector2f(1, 1000));
    yAxis.setPosition(SCREEN_WIDTH/2,0);
    yAxis.setFillColor(sf::Color::White);
    yAxis.rotate(90);
    xAxis.setPosition(0,SCREEN_HEIGHT/2);
    xAxis.setFillColor(sf::Color::White);
    xAxis.rotate(-90);
    window.draw(yAxis);
    window.draw(xAxis);
}

/* ---------------------------------------------------
/* setGraph();
 * This is a mutator, just sets everything f
 * or the graph for the Game class to call
----------------------------------------------------*/
void Graph::setGraph(Expression ifx, double l, double h, int max){
    exp=ifx;
    lo=l;
    hi=h;
    maxPoints=max;

}

//void Graph::TestDraw(sf::RenderWindow &window){
//    sf::RectangleShape box[1000];
//    for (int i = 0; i<590; i++){
//        int boxSize=1;
//        sf::Color color;
//        if (i%2 ==0)
//            color = sf::Color::Red;
//        else
//            color = sf::Color::Blue;
//        box[i] = CreateBox(i*boxSize, 0, color);
//        window.draw(box[i]);
//    }

//}



#endif // GRAPH_H










