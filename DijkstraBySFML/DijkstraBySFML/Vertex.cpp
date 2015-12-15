//  Vertex.cpp
//  Prim
//
//  Created by 徐 BOWEI on 15/12/6.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include "Vertex.hpp"

const string & Vertex::getName() const {
    return name;
}

void Vertex::setName(const string &name) {
    this->name = name;
}

int Vertex::getVisited() const {
    return visited;
}

void Vertex::setVisited(int visited) {
    this->visited = visited;
}

int Vertex::getDist() const {
    return dist;
}

void Vertex::setDist(int dist) {
    this->dist = dist;
}

int Vertex::getId() const {
    return id;
}

void Vertex::setId(int id) {
    this->id = id;
}
void Vertex::setTheLeftUpPointOfCircle(sf::Vector2f TheLeftUpPointOfCircle)
{
    this->TheLeftUpPointOfCircle = TheLeftUpPointOfCircle;
}
sf::Vector2f Vertex::getTheLeftUpPointOfCircle()
{
    return TheLeftUpPointOfCircle;
}
void Vertex::setTheCornerOfCircle(sf::Vector2f TheCornerOfCircle)
{
    this->TheCornerOfCircle = TheCornerOfCircle;
    setTheLeftUpPointOfCircle(TheCornerOfCircle - sf::Vector2f(RADIUS,RADIUS));
}
sf::Vector2f Vertex::getTheCornerOfCircle()
{
    return TheCornerOfCircle;
}
