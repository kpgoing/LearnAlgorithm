//
//  Vertex.hpp
//  TopSort
//
//  Created by 徐 BOWEI on 15/10/4.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace::std;
class Vertex
{
public:
    Vertex() = default;
    Vertex(string aname):name(aname){};
    void setName(string name);
    string getName();
    void setStatus(int status);
    int getStatus();
    bool operator!=( Vertex& vertex);
    bool operator==(Vertex& vertex);
    void setOrder(int order);
    int getOrder();
    void setOrder2(int order2);
    int getOrder2();
    void setTheCornerOfCircle(sf::Vector2f TheCornerOfCircle);
    sf::Vector2f getTheCornerOfCircle();
    void setConnectTo(vector<Vertex*> ConnectTo);
    vector<Vertex*> getConnectTO();
    void setConnectIn(vector<Vertex*> ConnectIn);
    vector<Vertex*> getConnectIn();
    void addConnectIn(Vertex* vertex);
    void addConnectTo(Vertex* vertex);
    int getAndSubIndegree();
    void addOrder(int n);
private:
    string name = "";
    int status = 0;
    int order = 0;
    int order2 = 0;
    int Indegree = 0;
    sf::Vector2f TheCornerOfCircle;
    vector<Vertex*> ConnectTo;
    vector<Vertex*> ConnectIn;
};
#endif /* Vertex_hpp */
