//
//  hashtab.h
//  HashTable
//
//  Created by 徐 BOWEI on 15/9/10.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

//typedef int ElementType;

//typedef unsigned int Index;

#ifndef HashTable_hashtab_h
#define HashTable_hashtab_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
#include <string>
#include "Vertex.hpp"
using namespace std;
typedef Vertex* ElementType;

	struct ListNode;
	typedef struct ListNode *Position;
	struct HashTbl;
	typedef struct HashTbl *HashTable;

	HashTable InitializeTable(int TableSize);
	void DestroyTable(HashTable H);
	Position Find(ElementType Key,HashTable H);
	void HashInsert(ElementType Key, ElementType TheAdjPoint, HashTable H);
	ElementType Retrive(Position P);
    void DrawHashTbl(HashTable H);
	
#endif
