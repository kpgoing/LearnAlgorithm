//
//  QueueADTbyList.h
//  QueueADTbyList
//
//  Created by 徐 BOWEI on 15/8/6.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef QueueADTbyList_QueueADTbyList_h
#define QueueADTbyList_QueueADTbyList_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
#include <string>
#include "Vertex.hpp"
using namespace std;
struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef struct QueueRecord *QueuePosition;
typedef Vertex* QueueRecord1;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
int IsLast(QueuePosition P);
QueuePosition FindLast(Queue Q);
Queue CreateQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(QueueRecord1 X,Queue Q);
QueueRecord1 Dequeue(Queue Q);
QueueRecord1 Front(Queue Q);
void Delete(Queue Q);
QueueRecord1 FindLast2(Queue Q);
QueueRecord1 FrontAndDequeue(Queue Q);
void DrawQueue(Queue Q);
#endif
