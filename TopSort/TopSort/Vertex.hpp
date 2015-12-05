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

    
private:
    string name = "";
    int status = 0;
    
};
#endif /* Vertex_hpp */
