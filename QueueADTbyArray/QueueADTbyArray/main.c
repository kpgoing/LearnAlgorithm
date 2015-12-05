//
//  main.c
//  QueueADTbyArray
//
//  Created by 徐 BOWEI on 15/8/6.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include <stdio.h>
#include "QueueADTbyArray.h"
#include <stdlib.h>

struct QueueRecord {
    int Capacity;;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}
int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{
    Queue Q;
    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL) {
        FatalError("Out of space!");
    }
    Q->Array = malloc(sizeof(ElementType)*MaxElements);
    if (Q == NULL) {
        FatalError("Out of space!");
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}
void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Rear = 0;
    Q->Front = 1;
}
void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}
static int Add(int value,Queue Q)
{
    if (++value == Q->Capacity) {
        value = 0;
    }
    return value;
}
void Enqueue(ElementType X,Queue Q)
{
    if (IsFull(Q)) {
        Error("Queue is full!");
    }
    else
    {
        Q->Size++;
        Q->Rear = Add(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}
ElementType Front(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty queue!");
    }
    return Q->Array[Q->Front];
}
void Dequeue(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty queue!");
    }
    Q->Size--;
    Q->Front = Add(Q->Front, Q);
}
ElementType FrontAndDequeue(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty queue!");
    }
    Q->Size--;
    int number = Q->Front;
    Q->Front = Add(Q->Front, Q);
    return Q->Array[number];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Queue Q = CreateQueue(100);
    Enqueue(1, Q);
    Enqueue(2, Q);
    printf("%d\n",Front(Q));
    printf("%d\n",Front(Q));
    printf("%d\n",FrontAndDequeue(Q));
    printf("%d\n",FrontAndDequeue(Q));
    printf("***%d\n",Q->Size);
//    printf("%d\n",FrontAndDequeue(Q));
    DisposeQueue(Q);
    return 0;
}
