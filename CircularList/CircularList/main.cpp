

#include <stdio.h>
#include "CircularList.h"
#include <stdlib.h>
#include <time.h>
struct Node
{
    ElementType Element;
    Position Next;
};
Position ChooseTheFirstOne(List L){
    srand((unsigned) time(NULL));
    int N = rand()%30;
    L = L->Next;
    
    while (N!=0) {
        L = L->Next;
        N--;
    }
    return L;
}

List Initialization(List L)
{
    L = (List)malloc(sizeof(struct Node));
    L->Next = L;
    return L;
}
int IsLast(Position P,List L)
{
    return P->Next == L;
}
Position FindLast(List L)
{
    Position P;
    P = L;
    while (!IsLast(P, L)) {
        P = P->Next;
    }
    return P;
}
void DeleteList(List L)
{
    Position P;
    Position TmpCell;
    P = L->Next;
    L->Next = L;
    while(P->Next!=L)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}
void Insert(ElementType X,List L, Position P)
{
    Position TmpCell;
    
    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        puts("out of space!");
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
    
}
Position FindAndDeleteFromList(int N,List L)
{
    int i = 0;
    Position PreP =NULL;
    while (i<N) {
        PreP = L;
        L = L->Next;
        i++;
    }
    PreP->Next = L->Next;
    return L;
}
ElementType Retrieve(Position P)
{
    return P->Element;
}
int main(int argc, const char * argv[]) {
    List L = Initialization(L);
    Position P;
    int i = 1;
    while (i<31) {
        Insert(i, L, FindLast(L));
        i++;
    }
    i = 0;
    L = ChooseTheFirstOne(L);
    while (i<15) {
        P = FindAndDeleteFromList(11, L);
        L = P;
        printf("%d ",Retrieve(P));
        i++;
    }
    return 0;
}
