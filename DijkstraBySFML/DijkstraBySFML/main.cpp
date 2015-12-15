
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include "list.h"
#include <random>
#include "Vertex.hpp"
#define NumVertex 7
#define NotAVertex -1
#define WIDTH 800
#define HEIGH 600
using namespace std;
struct TableCell
{
    List* Header;
    int Known;
    int dist;
    int Path;
};
std::string NAME = "abcdefg";
#define SIZE 7
int G[SIZE][SIZE] = {
    {0,15,2,12,0,0,0},
    {0,0,0,0,4,0,0},
    {0,0,0,0,8,4,0},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,9},
    {0,0,0,0,0,0,10},
    {0,4,0,0,0,0,0}
};
std::vector<Vertex> Vertexs;
vector<sf::CircleShape*> circles;
vector<sf::VertexArray*> lines;
vector<sf::VertexArray*> Pathlines;
vector<sf::Text*> names;
typedef struct TableCell *Table;

void InitTable(int Start, int G[][NumVertex],Table T)
{
    for (int i = 0; i < NumVertex; i++) {
        T[i].Header = (List*)malloc(sizeof(List));
        *(T[i].Header) = (List)malloc(sizeof(struct Node));
        (*(T[i].Header))->Next = NULL;
        for (int j = 0; j < NumVertex; j++) {
            if (G[i][j]) {
                Insert(j, *T[i].Header, FindLast(*T[i].Header));
            }
        }
    }
    
    for (int i = 0; i < NumVertex; i++) {
        T[i].Known = 0;
        T[i].dist = INT16_MAX;
        T[i].Path = NotAVertex;
    }
    T[Start].dist = 0;
}
sf::VertexArray* DrawLine(sf::Vector2f start, sf::Vector2f end)
{
    sf::VertexArray *line = new sf::VertexArray(sf::Lines,2);
    
    (*line)[0].position = start;
    (*line)[1].position = end;
    (*line)[0].color = sf::Color::Yellow;
    (*line)[1].color = sf::Color::Red;
    
    return line;
}
sf::VertexArray* DrawLineInBlueColor(sf::Vector2f start, sf::Vector2f end)
{
    sf::VertexArray *line = new sf::VertexArray(sf::Lines,2);
    
    (*line)[0].position = start;
    (*line)[1].position = end;
    (*line)[0].color = sf::Color::Blue;
    (*line)[1].color = sf::Color::Blue;
    
    return line;
}
void PrintPath(int V,Table T)
{
    if (T[V].Path != NotAVertex) {
        Pathlines.push_back(DrawLineInBlueColor(Vertexs[Vertexs[V].Path].getTheCornerOfCircle(), Vertexs[V].getTheCornerOfCircle()));
        PrintPath(T[V].Path, T);
        printf(" TO ");
    }
    printf("%c",NAME[V]);
}

void Dijkstra(int G[][NumVertex],Table T)
{
    int V, W;
    V = T[0].dist;
    int N = 0;
    for (; ; ) {
        for (int i = 0; i < NumVertex; i++) {
            if (T[i].dist < V && !T[i].Known) {
                V = T[i].dist;
                Vertexs[i].setDist(V);
                N = i;
            }
        }
        
        if(V == INT16_MAX){
            break;
        }
        
        T[N].Known = 1;
        Position P = *T[N].Header;
        while(!IsEmpty(P)) {
            P = P->Next;
            W = P->Element;
            if (!T[W].Known) {
                if (T[N].dist + G[N][W] < T[W].dist) {
                    T[W].dist = T[N].dist + G[N][W];
                    T[W].Path = N;
                    Vertexs[W].Path = N;
                }
            }
        }
        V = INT16_MAX;
    }
}

//void DrawCircle(std::vector<Vertex> Vertexs, vector<sf::CircleShape*> circles)
//{
//    default_random_engine eOfWdith(time(0));
//    default_random_engine eOfHeigh(time(0)+10);
//    default_random_engine eOfWdith(time(0));
//    default_random_engine eOfHeigh(time(0)+10);
//    for (int i = 0; i < Vertexs.size() ; i++) {
//        sf::CircleShape* circle = new sf::CircleShape;
//        //rand the position
//        uniform_int_distribution<unsigned> uOfWidth(0 + RADIUS,WIDTH - RADIUS);
//        uniform_int_distribution<unsigned> uOfHeigh(0 + RADIUS,HEIGH - RADIUS);
//        sf::Vector2f TheCornerOfCircle(uOfWidth(eOfWdith),uOfHeigh(eOfHeigh));
//        Vertexs[i].setTheCornerOfCircle(TheCornerOfCircle);
//        circle->setPosition(Vertexs[i].getTheLeftUpPointOfCircle());
//        circle->setRadius(RADIUS);
//        circle->setFillColor(sf::Color::White);
//        circles.push_back(circle);
//        sf::Text* name = new sf::Text(Vertexs[i].getName(),font,40);
//        name->setColor(sf::Color::Red);
//        name->setPosition(Vertexs[i].getTheLeftUpPointOfCircle()+sf::Vector2f(3,-3));
//        names.push_back(name);
//    }
//
//}
int main(int, char const**)
{


    Table T = (Table)malloc(NumVertex * sizeof(struct TableCell));
    InitTable(0, G, T);
    for (int i = 0 ; i < NumVertex ; i++) {
        ShowAllElement(*T[i].Header);
    }
    
    for(int i = 0 ; i < NAME.size() ; i++){
        Vertex V = *new Vertex();
        V.setName(NAME.substr(i,1));
        V.setId(i);
        V.setVisited(0);
        Vertexs.push_back(V);
    }
    std::cout<<"1"<<std::endl;
    Dijkstra(G, T);
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    
    default_random_engine eOfWdith(time(0));
    default_random_engine eOfHeigh(time(0)+10);
    for (int i = 0; i < Vertexs.size() ; i++) {
        sf::CircleShape* circle = new sf::CircleShape;
        //rand the position
        uniform_int_distribution<unsigned> uOfWidth(0 + RADIUS,WIDTH - RADIUS);
        uniform_int_distribution<unsigned> uOfHeigh(0 + RADIUS,HEIGH - RADIUS);
        sf::Vector2f TheCornerOfCircle(uOfWidth(eOfWdith),uOfHeigh(eOfHeigh));
        Vertexs[i].setTheCornerOfCircle(TheCornerOfCircle);
        circle->setPosition(Vertexs[i].getTheLeftUpPointOfCircle());
        circle->setRadius(RADIUS);
        circle->setFillColor(sf::Color::White);
        circles.push_back(circle);
        sf::Text* name = new sf::Text(Vertexs[i].getName(),font,40);
        name->setColor(sf::Color::Red);
        name->setPosition(Vertexs[i].getTheLeftUpPointOfCircle()+sf::Vector2f(3,-3));
        names.push_back(name);
        
    }
    
//    for(auto e : Vertexs)
//    {
//        if (e.Path != NotAVertex) {
//            lines.push_back(DrawLine(Vertexs[e.Path].getTheLeftUpPointOfCircle(), e.getTheLeftUpPointOfCircle()));
//        }
//    }
    for (int i = 0; i < NumVertex; i++) {
        for (int j = 0; j < NumVertex; j++) {
            if (G[i][j]) {
                lines.push_back(DrawLine(Vertexs[i].getTheCornerOfCircle(), Vertexs[j].getTheCornerOfCircle()));
            }
        }
    }
    
    PrintPath(6, T);
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "DijkstraBySFML");
    

    
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        // Clear screen
        window.clear();
        
        
        for(auto e : circles)
        {
            window.draw(*e);
        }
        for(auto e : names)
        {
            window.draw(*e);
        }
        for(auto e : lines)
        {
            window.draw(*e);
        }
        for(auto e : Pathlines)
        {
            window.draw(*e);
        }
//        for(vector<sf::VertexArray*>::reverse_iterator rit = lines.rbegin();rit!=lines.rend(); rit--)
//        {
//            window.draw(**rit);
//        }
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}
