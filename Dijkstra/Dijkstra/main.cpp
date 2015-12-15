//
//  main.cpp
//  Dijkstra
//
//  Created by 徐 BOWEI on 15/11/13.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include "list.h"
#define NumVertex 7
#define NotAVertex -1
struct TableCell
{
    List* Header;
    int Known;
    int dist;
    Vertex Path;
};
std::string NAME = "abcdefg";
typedef struct TableCell *Table;


void InitTable(Vertex Start, int G[][NumVertex],Table T)
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

void PrintPath(Vertex V,Table T)
{
    if (T[V].Path != NotAVertex) {
        PrintPath(T[V].Path, T);
        printf(" TO ");
    }
    printf("%c",NAME[V]);
}

void Dijkstra(int G[][NumVertex],Table T)
{
    Vertex V, W;
    V = T[0].dist;
    int N = 0;
    for (; ; ) {
        for (int i = 0; i < NumVertex; i++) {
//            V = ( T[i].dist < V ? T[i].dist : V );
            if (T[i].dist < V && !T[i].Known) {
                V = T[i].dist;
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
                }
            }
        }
        V = INT16_MAX;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    int G[7][7] = {
        {0,15,2,12,0,0,0},
        {0,0,0,0,4,0,0},
        {0,0,0,0,8,4,0},
        {0,0,0,0,0,0,3},
        {0,0,0,0,0,0,9},
        {0,0,0,0,0,0,10},
        {0,4,0,0,0,0,0}
    };
    Table T = (Table)malloc(NumVertex * sizeof(struct TableCell));
    InitTable(0, G, T);
    for (int i = 0 ; i < NumVertex ; i++) {
        ShowAllElement(*T[i].Header);
    }
    std::cout<<"1"<<std::endl;
    Dijkstra(G, T);
     std::cout<<"2"<<std::endl;
    PrintPath(6, T);
    std::cout<<std::endl;
    return 0;
}
