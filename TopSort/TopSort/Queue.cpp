//
//  Queue.cpp
//  TopSort
//
//  Created by 徐 BOWEI on 15/10/4.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include "QueueADTbyList.h"
#include <stdlib.h>

struct QueueRecord {
    QueueRecord1 Element;
    QueuePosition Next;
};
int IsEmpty(Queue Q)
{
    return Q->Next == NULL;
}
int IsLast(QueuePosition P)
{
    return P->Next==NULL;
}
QueuePosition FindLast(Queue Q)
{
    QueuePosition P;
    P = Q;
    if (!IsLast(P)) {
        P = P->Next;
    }
    return P;
}
QueueRecord1 FindLastInElement(Queue Q)
{
    QueuePosition P;
    P = Q;
    if (!IsLast(P)) {
        P = P->Next;
    }
    return P->Element;
}
Queue CreateQueue(void)
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q==NULL) {
        FatalError("Out of space!");
    }
//    MakeEmpty(Q);
    Q -> Next = NULL;
    return Q;
}
void MakeEmpty(Queue Q)
{
    if (Q==NULL) {
        Error("Must use CreateQueue first!");
    }
    QueuePosition P,TmpCell;
    //这里会出现野指针的问题，具体情况视编译器而定
    P = Q->Next;
    Q->Next = NULL;
    if (P!=NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}
void Enqueue(QueueRecord1 X,Queue Q)
{
    QueuePosition P;
    QueuePosition Last = FindLast(Q);
    P = (QueueRecord*)malloc(sizeof(struct QueueRecord));
    if (P==NULL) {
        FatalError("Out of space!");
    }
    P->Element = X;
    Last->Next = P;
    P->Next = NULL;
}
QueueRecord1 Front(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty Queue!");
    }
    return Q->Next->Element;
}

QueueRecord1 Dequeue(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty Queue!");
    }
    QueuePosition P = Q->Next;
    QueueRecord1 V = P -> Element;
    Q->Next = P->Next;
    free(P);
    return V;
}
QueueRecord1 FrontAndDequeue(Queue Q)
{
    if (IsEmpty(Q)) {
        Error("Empty Queue!");
    }
    QueuePosition P = Q->Next;
    Q->Next = P->Next;
    Vertex* element = P->Element;
    free(P);
    return element;
}
void DrawQueue(Queue Q)
{
    QueuePosition P;
    P = Q;
    if (!IsLast(P)) {
        P = P->Next;
        std::cout<<P->Element->getName()<<"--";
    }
    std::cout<<endl;
}
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    Queue Q;
//    Q = CreateQueue();
//    Enqueue(1, Q);
//    Enqueue(2, Q);
//    Dequeue(Q);
////    printf("%d", FrontAndDequeue(Q));
//    printf("%d", FrontAndDequeue(Q));
//    return 0;
//}
