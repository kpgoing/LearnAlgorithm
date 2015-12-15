#include <iostream>
#include "list.h"
#include <stdlib.h>
#define SIZE 6
int visited[SIZE] = {0};
int graph[SIZE][SIZE] = {
    {0,1,1,1,0,0},
    {1,0,0,0,1,0},
    {1,0,0,0,1,0},
    {1,0,0,0,0,1},
    {0,1,1,0,0,0},
    {0,0,0,1,0,0}
};
struct TableCell
{
    List* Header;
};

typedef struct TableCell *Table;


void InitTable(int G[][SIZE],Table T)
{
    for (int i = 0; i < SIZE; i++) {
        T[i].Header = (List*)malloc(sizeof(List));
        *(T[i].Header) = (List)malloc(sizeof(struct Node));
        (*(T[i].Header))->Next = NULL;
        for (int j = 0; j < SIZE; j++) {
            if (i != j) {
                Insert(j, *T[i].Header, FindLast(*T[i].Header));
            }
        }
    }
}
void dfs(Table T,int N)
{
    std::cout<<N<<"->";
    visited[N] = 1;
    Position P = (*(T[N].Header))->Next; 
    if(P != NULL)
    {
        while (!visited[P->Element])
        {   
            dfs(T,P->Element);
        }
        P = P ->Next;
    }
}

int main(int argc, char const *argv[])
{
    Table T;
    InitTable(graph,T);
    dfs(T,0);
    return 0;
}




