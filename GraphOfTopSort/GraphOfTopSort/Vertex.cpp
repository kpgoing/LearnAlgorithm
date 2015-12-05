//
//  Vertex.cpp
//  TopSort
//
//  Created by 徐 BOWEI on 15/10/4.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include "Vertex.hpp"
void Vertex::setName(string name)
{
    this->name = name;
}
string Vertex::getName()
{
    return name;
}
void Vertex::setStatus(int status)
{
    this->status = status;
}
int Vertex::getStatus()
{
    return status;
}
void Vertex::setOrder(int order)
{
    this->order = order;
}
int Vertex::getOrder()
{
    return order;
}
void Vertex::setOrder2(int order2)
{
    this->order2 = order2;
}
int Vertex::getOrder2()
{
    return order2;
}
void Vertex::setTheCornerOfCircle(sf::Vector2f TheCornerOfCircle)
{
    this->TheCornerOfCircle = TheCornerOfCircle;
}
sf::Vector2f Vertex::getTheCornerOfCircle()
{
    return TheCornerOfCircle;
}
bool Vertex::operator!=(Vertex &vertex)
{
    if (this->name != vertex.name || this->status != vertex.status) {
        return true;
    }else
    {
        return false;
    }
}
bool Vertex::operator==(Vertex &vertex)
{
    return (this->name==vertex.name && this->status == vertex.status);
}
void Vertex::setConnectTo(vector<Vertex *> ConnectTo)
{
    this->ConnectTo = ConnectTo;
}
vector<Vertex*> Vertex::getConnectTO()
{
    return this->ConnectTo;
}
void Vertex::setConnectIn(vector<Vertex *> ConnectIn)
{
    this->ConnectIn = ConnectIn;
}
vector<Vertex*> Vertex::getConnectIn()
{
    return this->ConnectIn;
}
void Vertex::addConnectIn(Vertex * vertex)
{
    ConnectIn.push_back(vertex);
    Indegree++;
}
void Vertex::addConnectTo(Vertex * vertex)
{
    ConnectTo.push_back(vertex);
}
int Vertex::getAndSubIndegree()
{
    return --Indegree;
}
void Vertex::addOrder(int n)
{
    order += n;
}