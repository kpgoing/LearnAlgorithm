//
//  AVLTree.h
//  AVLTree
//
//  Created by 徐 BOWEI on 15/9/1.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include <stdlib.h>
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

typedef int ElementType;

#ifndef AVLTree_AVLTree_h
#define AVLTree_AVLTree_h

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X,AvlTree T);
AvlTree Delete(ElementType X,AvlTree T);
ElementType Retrieve(Position P);


#endif
