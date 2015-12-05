
#ifndef CircularList_h
#define CircularList_h
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
List Initialization(List L);
Position ChooseTheFirstOne(List L);
void DeleteList(List L);
int IsLast(Position P , List L);
Position FindAndDeleteFromList(List L);
Position FindLast(List L);
ElementType Retrieve(Position P);


#endif /* CircularList_h */
