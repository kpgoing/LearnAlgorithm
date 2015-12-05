
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
#include <iostream>
#include <vector>
#include "QueueADTbyList.h"
#include "hashtab.h"
#include "Status.h"
// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#define SIZE_GRAPH 7
#define WIDTH 800
#define HEIGH 600
#define RADIUS 20
using namespace std;
void CreteAConnection(Vertex*A, Vertex*B)
{
    A->addConnectTo(B);
    B->addConnectIn(A);
    
}
int main(int, char const**)
{
    vector<sf::CircleShape*> circles;
    vector<sf::VertexArray*> lines;
    vector<sf::Text*> names;
    
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
//    int order2 = 0;
    vector<int> order2(SIZE_GRAPH,0);
    HashTable Graph;
    Queue First = CreateQueue();
    int count = 0;
    int TopNum[ SIZE_GRAPH ] = {0};
    Vertex A("A");
    Vertex B("B");
    Vertex C("C");
    Vertex D("D");
    Vertex E("E");
    Vertex G("G");
    Vertex F("F");
    CreteAConnection(&A,&B);
    CreteAConnection(&A,&C);
    CreteAConnection(&B,&D);
    CreteAConnection(&C,&D);
    CreteAConnection(&E,&F);
    CreteAConnection(&F,&D);
    CreteAConnection(&F,&G);
//    CreteAConnection(&F,&C);
    vector<int> Indegree;
    std::vector<Vertex*> vertexs = {&A, &B, &C, &D, &E, &F, &G};
    for(auto e : vertexs)
    {
        Indegree.push_back(e->getConnectIn().size());
        cout<<e->getName()<<":"<<e->getConnectIn().size()<<endl;
    }
    Graph = InitializeTable( 20 );
//    HashInsert(&A, &B, Graph);
//    HashInsert(&A, &C, Graph);
//    HashInsert(&B, &D, Graph);
//    HashInsert(&C, &F, Graph);
//    HashInsert(&E, &G, Graph);
    bool flag = false;
    for (int i = 0; i < SIZE_GRAPH; i++) {
        if (Indegree[i] == 0) {
//            vector<Vertex*> connectto = vertexs[i]->getConnectTO();
//            for(auto e : connectto)
//            {
//                e->addOrder();
//            }
            vertexs[i]->setStatus(Status::INFIRSTQUEUE);
            Enqueue(vertexs[i], First);
            cout<<"the first time:"<<vertexs[i]->getName()<<endl;
            vertexs[i]->setOrder2(order2[0]);
            order2[0]++;
//            flag = true;
            }
    }
//    if (flag) {
//        ++order;
//        flag = false;
//    }
    DrawQueue(First);
    int a = 1;
    Vertex* V;
    while (!IsEmpty(First)) {
        cout<<"xunhuan"<<a++<<"times"<<endl;
        V =Dequeue(First);
        cout<<"出队："<<V->getName()<<endl;
        V->setStatus(Status::INSECONDQUEUE);
        //画圆
        sf::CircleShape* circle = new sf::CircleShape;
        sf::Vector2f TheCornerOfCircle((V->getOrder()+1)*WIDTH/(SIZE_GRAPH+1), (V->getOrder2()+1) * HEIGH/(SIZE_GRAPH + 1));
        V->setTheCornerOfCircle(TheCornerOfCircle + sf::Vector2f(RADIUS,RADIUS));
        circle->setPosition(TheCornerOfCircle);
        circle->setRadius(RADIUS);
        circles.push_back(circle);
        //文字显示
        sf::Text* name = new sf::Text(V->getName(),font,40);
        name->setColor(sf::Color::Red);
        sf::Vector2f namesize = name->getScale();
//        sf::Vector2f fz((V->getOrder()+1)*WIDTH/SIZE_GRAPH, (V->getOrder2()+1) * HEIGH/SIZE_GRAPH);
        name->setPosition(V->getTheCornerOfCircle() - sf::Vector2f(RADIUS,RADIUS));
        names.push_back(name);
        //debug
        cout<<V->getName()<<":";
        cout<<"order:"<<V->getOrder()<<"order2:"<<V->getOrder2()<<endl;
        //连线
        vector<Vertex*> connectin;
        connectin = V->getConnectIn();
        if (!connectin.empty()) {
            for(auto e : connectin)
            {
                if (e->getStatus() == Status::INSECONDQUEUE) {
                    sf::VertexArray *line = new sf::VertexArray(sf::Lines,2);
                    (*line)[0].position = e->getTheCornerOfCircle();
                    (*line)[1].position = V->getTheCornerOfCircle();
                    (*line)[0].color = sf::Color::Yellow;
                    (*line)[1].color = sf::Color::Red;
                    cout<<"drawline"<<endl;
                    lines.push_back(line);
                }
            }
        }
        for (int j = 0; j < vertexs.size() ; ++j) {
            if(V == vertexs[j])
            {
                TopNum[j] = ++count;
//                cout<<TopNum[j]<<"!!!";
            }
            
        }
        
        vector<Vertex*> ConnectTo = V->getConnectTO();
        for (auto e : ConnectTo) {
            e->setOrder(V->getOrder()+1);
            cout<<" 即将减少入度的点:"<<e->getName()<<endl;
            if (e->getAndSubIndegree() == 0) {
                Enqueue(e, First);
                e->setStatus(Status::INFIRSTQUEUE);
                cout<<"**************"<<endl;
                DrawQueue(First);
                cout<<"入队："<<(FindLast2(First)->getName())<<endl;
//                e->setOrder(order);
                 e->setOrder2(order2[e->getOrder()]);
                order2[e->getOrder()]++;
            }
            }
//        if (flag) {
//            ++order;
//            flag = false;
//        }
    
       
//        cout<<"现在队列最前的是："<<Front(First)->getName()<<endl;
    }
    
//    if (count != SIZE_GRAPH) {
//        Error("Graph has a cycle!");
//    }

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
//    sf::Image icon;
//    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
//        return EXIT_FAILURE;
//    }
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Create a graphical text to display

    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
//        return EXIT_FAILURE;
//    }

    // Play the music
//    music.play();
    cout<<circles.size()<<endl;
    // Start the game loop
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
        
        // Draw the sprite
//        window.draw(sprite);

        // Draw the string
//        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
