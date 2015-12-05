//
//  Tree.h
//  Tree
//
//  Created by 徐 BOWEI on 15/11/10.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#ifndef Tree_h
#define Tree_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
struct Node;
typedef struct Node *ThePointToNode;
typedef ThePointToNode Tree;
typedef ThePointToNode Position;
typedef int ElementType;
Tree MakeEmpty(Tree T);
Position Find(Tree T, ElementType X);
Position FindMin(Tree T);
Tree Insert(Tree T, ElementType X);
Tree Delete(Tree T, ElementType X);
int GetTheCountOfLeaves(Tree T);
void ExchangeTheSon(Tree T);
void GetTheRoadsFromAllLeavesToRoot(Tree T);
#endif /* Tree_h */
