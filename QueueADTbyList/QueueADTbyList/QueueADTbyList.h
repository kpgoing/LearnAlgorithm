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

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef struct QueueRecord *Position;
typedef int  ElementType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
int IsLast(Position P);
Position FindLast(Queue Q);
Queue CreateQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X,Queue Q);
void Dequeue(Queue Q);
ElementType Front(Queue Q);
void Delete(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif
