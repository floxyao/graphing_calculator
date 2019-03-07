//#include <iostream>
//#include "graph.h"
#include "game.h"
using namespace std;

/* --------------------------------------------------
 * Project: Graphing Calculator
 * Name: Flo Yao
 * Notes: I had trouble with the Queue destructor because
 *        there is memory that has been created on the heap
 *        that it will not delete in the destructor because
 *        the array holding those objects was destroyed first
 *
 *        Also had trouble with zooming in and output
 *        Was not scaling my graph, just adding more/less points
 *
 *        Unary operator
----------------------------------------------------*/
int main()
{
    Game mygame;
    mygame.run();
    return 0;
}

////void testStack();
//void testContainer();
////void testInput();
////void testGraph();
//int main()
//{
//    cout<<endl<<"=====BEGIN===="<<endl<<endl;

//    //testGraph();
//    testContainer();
//    //testStack();
//    //testInput();

//    cout<<endl<<endl<<"======END====="<<endl;
//    return 0;
//}

//void testContainer(){
//    Queue<Token*> inputQ;

//    //inputQ.Add(new Operator('-'));
//    inputQ.Add(new Operator('s'));
//    inputQ.Add(new Operator('x'));
//    //inputQ.Add(new Number(3));
//    inputQ.Add(new Operator('*'));
//    inputQ.Add(new Operator('-'));
//    inputQ.Add(new Number(5));


//    cout<<endl<<"=====DEBUG====="<<endl;
//    cout<<"infix: "; inputQ.Print();

//    Expression e(inputQ);
//    cout<<endl<<"Infix Exp: "; e.Print();
//    cout<<endl<<"Postfix Exp: "; e.ShowPostfix();
//    //e.checkUnary(inputQ);
//    cout<<endl<<"Result: ";
//    cout<<e.EvalVariable(2);

////    cout<<endl<<"=====GRAPH===="<<endl;
////    Graph g(e, -10, 10, 100);
////    g.generatePoints();

////    cout<<endl<<endl<<"Result: ";
////    cout<<endl<<e.EvalVariable(5);
//}


//void testGraph(){
//    Queue<Token*> inputQ;
//    inputQ.Add(new Number(3));
//    inputQ.Add(new Operator('*'));
//    inputQ.Add(new Operator('x'));
//    inputQ.Add(new Operator('+'));
//    inputQ.Add(new Number(2));

//    Expression e(inputQ);
//    cout<<"Infix: ";
//    e.Print();

//    Graph g(e, 0, 20, 20);
//    g.generatePoints();
//    cout<<endl;
//    cout<<"Generating points..."<<endl;
//    g.showPoints();
//}

//void testInput(){
//    Queue<Token*> inputQ;
//    inputQ.Input(cin, "Input Expression: ");
//}

//void testStack(){
//    Stack<Token*> s;

//    s.Push(new Operator('+'));
//    s.Push(new Operator(')'));
//    s.Push(new Operator('*'));
//    s.Print();

//}
