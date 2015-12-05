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