//
//  StackADT.h
//  StackADT
//
//  Created by 徐 BOWEI on 15/8/5.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef StackADT_StackADT_h
#define StackADT_StackADT_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
#endif

