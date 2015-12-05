//
//  TwoStackInOneArray.h
//  TwoStackInOneArray
//
//  Created by 徐 BOWEI on 15/9/24.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#ifndef TwoStackInOneArray_h
#define TwoStackInOneArray_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )


struct DblStack;
typedef struct DblStack *Stack;
typedef int ElementType;

Stack CreateStack(int MaxElements);
int IsEmpty(Stack S,int i);
int IsFull(Stack s);
void Dblpush(Stack,ElementType x,int i);
int Dblpop(Stack,int i,ElementType &x);
Stack MakeEmpty(Stack S);
void ShowStack(Stack S);
#endif /* TwoStackInOneArray_h */
