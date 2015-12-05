//
//  hashtab.h
//  HashTable
//
//  Created by 徐 BOWEI on 15/9/10.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

typedef int ElementType;

typedef unsigned int Index;

#ifndef HashTable_hashtab_h
#define HashTable_hashtab_h
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

	struct ListNode;
	typedef struct ListNode *Position;
	struct HashTbl;
	typedef struct HashTbl *HashTable;

	HashTable InitializeTable(int TableSize);
	void DestroyTable(HashTable H);
	Position Find(ElementType Key,HashTable H);
	void Insert(ElementType Key,HashTable H);
	ElementType Retrive(Position P);

	
#endif
