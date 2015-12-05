//
//  main.c
//  QueueADTbyList
//
//  Created by 徐 BOWEI on 15/8/6.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include <stdio.h>
#include "QueueADTbyList.h"
#include <stdlib.h>

struct QueueRecord {
    ElementType Element;
    Position Next;
};
int IsEmpty(Queue Q)
{
    return Q->Next == NULL;
}
int IsLast(Position P)
{
    return P->Next==NULL;
}
Position FindLast(Queue Q)
{
    Position P;
    P = Q;
    if (!IsLast(P)) {
        P = P->Next;
    }
    return P;
}
Queue CreateQueue(void)
{
    Queue Q;
    Q = malloc(sizeof(struct QueueRecord));
    if (Q==NULL) {
        FatalError("Out of space!");
    }
    MakeEmpty(Q);
    return Q;
}
void MakeEmpty(Queue Q)
{
    if (Q==NULL) {
        Error("Must use CreateQueue first!");
    }
    Position P,TmpCell;
    P = Q->Next;
    Q->Next = NULL;
    if (P!=NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}
void Enqueue(ElementType X,Queue Q)
{
    Position P;
    Position Last = FindLast(Q);
    P = malloc(sizeof(struct QueueRecord));
    if (P==NULL) {
        FatalError("Out of space!");
    }
    P->Element = X;
    Last->Next = P;
    P->Next = NULL;
}
ElementType Front(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty Queue!");
    }
    return Q->Next->Element;
}

void Dequeue(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty Queue!");
    }
    Position P = Q->Next;
    Q->Next = P->Next;
    free(P);
}
ElementType FrontAndDequeue(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty Queue!");
    }
    Position P = Q->Next;
    Q->Next = P->Next;
    int element = P->Element;
    free(P);
    return element;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Queue Q;
    Q = CreateQueue();
    Enqueue(1, Q);
    Enqueue(2, Q);
    Dequeue(Q);
//    printf("%d", FrontAndDequeue(Q));
    printf("%d", FrontAndDequeue(Q));
    return 0;
}
