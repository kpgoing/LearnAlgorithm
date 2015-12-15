//
//  Vertex.hpp
//  Prim
//
//  Created by 徐 BOWEI on 15/12/6.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <iostream>
#include <string>
#include "Status.h"
#include <SFML/Graphics.hpp>
#define RADIUS 20
using namespace std;
class Vertex {
public:
    Vertex() = default;
    const string &getName() const;
    void setName(const string &name);
    int getVisited() const;
    void setVisited(int visited);
    int getDist() const;
    void setDist(int dist);
    int getId() const;
    void setId(int id);
    void setTheCornerOfCircle(sf::Vector2f TheCornerOfCircle);
    sf::Vector2f getTheCornerOfCircle();
    void setTheLeftUpPointOfCircle(sf::Vector2f TheLeftUpPointOfCircle);
    sf::Vector2f getTheLeftUpPointOfCircle();
    int PreVertex = -1;
    int Path = -1;
private:
    string name = "";
    int id = -1;
    int visited = Status::UN_VISITED;
    int dist = INT16_MAX;
    sf::Vector2f TheCornerOfCircle;
    sf::Vector2f TheLeftUpPointOfCircle;
};

#endif /* Vertex_hpp */
