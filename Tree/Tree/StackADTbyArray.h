//
//  StackADTbyArray.h
//  StackADTbyArray
//
//  Created by 徐 BOWEI on 15/8/5.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef StackADTbyArray_StackADTbyArray_h
#define StackADTbyArray_StackADTbyArray_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxELements);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
void Pop(Stack S);
ElementType Top(Stack S);
ElementType PopAndTop(Stack S);
void PrintFromTop(Stack S);
#endif

