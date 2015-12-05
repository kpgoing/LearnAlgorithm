//
//  main.cpp
//  Dijkstra
//
//  Created by 徐 BOWEI on 15/11/13.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include "list.h"
#define NumVertex 5
#define NotAVertex -1
typedef int Vertex;
struct TableCell
{
    List* Header;
    int Known;
    int dist;
    Vertex Path;
};

typedef struct TableCell *Table;


void InitTable(Vertex Start, int G[][NumVertex],Table T)
{
    for (int i = 0; i < NumVertex; i++) {
        T[i].Header = (List*)malloc(sizeof(List));
        *(T[i].Header) = (List)malloc(sizeof(struct Node));
        (*(T[i].Header))->Next = NULL;
        for (int j = 0; j < NumVertex; j++) {
            if (i != j) {
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

void PrintPath(Vertex V,Table T)
{
    if (T[V].Path != NotAVertex) {
        PrintPath(T[V].Path, T);
        printf(" TO ");
    }
    printf("%d",V);
}

void Dijkstra(int G[][NumVertex],Table T)
{
    Vertex V, W;
    V = T[0].dist;
    for (; ; ) {
        for (int i = 0; i < NumVertex; i++) {
            V = T[i].dist < V ? T[i].dist : V;
        }
        
        T[V].Known = 1;
        Position P = *T[V].Header;
        while(!IsEmpty(P)) {
            P = P->Next;
            W = P->Element;
            if (!T[W].Known) {
                if (T[V].dist + G[V][W] < T[W].dist) {
                    T[W].dist = T[V].dist + G[V][W];
                    T[W].Path = V;
                }
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    int G[5][5] = {
        { 0,1,1,1,1},
        { 1,0,1,1,1},
        { 1,1,0,1,1},
        { 1,1,1,0,1},
        { 1,1,1,1,0},
    };
    Table T = (Table)malloc(10 * sizeof(struct TableCell));
    InitTable(1, G, T);
    Dijkstra(G, T);
    PrintPath(1, T);
    return 0;
}
