//
//  list.h
//  list
//
//  Created by 徐 BOWEI on 15/8/2.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#ifndef list_list_h
#define list_list_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P , List L);
Position Find(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
Position FindLast(List L);
void Delete(ElementType X,List L);
void Insert(ElementType X,List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void ShowAllElement(List L);
List Merge(List L1,List L2);
List Merge2(List L1,List L2);
Position FindMax(List L);
Position FindMaxByPoint(List L);
List Reverse(List L);
Position FindListAndDeleteItFromList(List L);
#endif
