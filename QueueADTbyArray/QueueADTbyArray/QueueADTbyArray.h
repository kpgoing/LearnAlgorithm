//
//  QueueADTbyArray.h
//  QueueADTbyArray
//
//  Created by 徐 BOWEI on 15/8/6.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef QueueADTbyArray_QueueADTbyArray_h
#define QueueADTbyArray_QueueADTbyArray_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )


struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
static int Add(int value,Queue Q);
void Enqueue( ElementType X, Queue Q );
ElementType Front( Queue Q );
void Dequeue( Queue Q );
ElementType FrontAndDequeue( Queue Q );


#endif
