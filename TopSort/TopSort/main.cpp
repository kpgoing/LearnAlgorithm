//
//  main.cpp
//  TopSort
//
//  Created by 徐 BOWEI on 15/10/4.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include <vector>
#include "QueueADTbyList.h"
#include "hashtab.h"
#include "Status.h"
using namespace std;
int main(int argc, const char * argv[]) {
    HashTable Graph;
    Queue First = CreateQueue();
    Queue Second = CreateQueue();
    int count = 0;
    int TopNum[5] = {0};
    int Indegree[5] = {0, 1, 1, 2,0};
    Vertex A("A");
    Vertex B("B");
    Vertex C("C");
    Vertex D("D");
    Vertex E("E");
    std::vector<Vertex*> vertexs = {&A,&B,&C,&D,&E};
    Graph = InitializeTable( 20 );
    HashInsert(vertexs[0], vertexs[2], Graph);
    HashInsert(vertexs[0], vertexs[2], Graph);
    HashInsert(vertexs[1], vertexs[3], Graph);
    HashInsert(vertexs[2], vertexs[3], Graph);
    
    for (int i = 0; i < 5; i++) {
        if (Indegree[i] == 0) {
            vertexs[i]->setStatus(Status::INFIRSTQUEUE);
            Enqueue(vertexs[i], First);
        }
    }
    DrawQueue(First);
    while (!IsEmpty(First)) {
        Vertex* V =Dequeue(First);
        V->setStatus(Status::INSECONDQUEUE);
        Enqueue(V, Second);
        for (int j = 0; j < vertexs.size() ; ++j) {
            if(V == vertexs[j])
            {
                TopNum[j] = ++count;
            }
            
        }
        for (int i = 0; i < vertexs.size(); i++) {
            if (--Indegree[i] == 0) {
                Enqueue(vertexs[i], First);
            }
        }
        
    }
    
    if (count != 5) {
        Error("Graph has a cycle!");
    }

    DrawHashTbl(Graph);
    return 0;
    
}
