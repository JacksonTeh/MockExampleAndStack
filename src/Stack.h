#ifndef Stack_H
#define Stack_H

typedef struct
{
	char *buffer;
	int size;
	int length;
}Stack;

Stack *stackNew(int length);
void stackDel(Stack *stackPtr);
int stackPop(Stack *stackPtr);
void stackPush(Stack *stackPtr, char data);
int stackIsEmpty(Stack *stackPtr);
int stackIsFull(Stack *stackPtr);

#endif // Stack_H
