//
//  PriorityQueue.h
//  PriorityQueue
//
//  Created by 徐 BOWEI on 15/9/17.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef PriorityQueue_PriorityQueue_h
#define PriorityQueue_PriorityQueue_h

#include <iostream>
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )


struct HeapStruct;
typedef int ElementType;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(PriorityQueue H,ElementType X);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);


#endif
