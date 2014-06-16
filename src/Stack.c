#include "Stack.h"
#include "malloc.h"
#include "stdio.h"
#include "ErrorCode.h"

/*
 * To create stack of specific buffer length
 *
 * Input
 *		length		is the length of the stack
 */
Stack *stackNew(int length)
{
	Stack *stack = malloc(sizeof(Stack));
	stack->buffer = malloc(sizeof(char) * length);
	stack->size = 0;
	stack->length = length;
}

/*
 * To pop data out of the stack and throw an error if stack is empty
 *
 * Input
 *		stackPtr	is a pointer to Stack object
 *
 * Return
 *		dataPop		data that pop out from the stack
 */
int stackPop(Stack *stackPtr)
{
	char dataPop;
	
	if(stackIsEmpty(stackPtr))
		Throw(ERR_STACK_IS_EMPTY);
	
	stackPtr->size--;
	dataPop = stackPtr->buffer[stackPtr->size];
	
	return dataPop;
}

/*
 * To push data into the stack and throw an error if stack is full
 *
 * Input
 *		stackPtr	is a pointer to Stack object
 *		data		data that push into the stack
 */
void stackPush(Stack *stackPtr, char data)
{
	if(stackIsFull(stackPtr))
		Throw(ERR_STACK_IS_FULL);
		
	stackPtr->buffer[stackPtr->size] = data;
	stackPtr->size++;
}

/*
 * To check stack is empty
 *
 * Input
 *		stackPtr	is a pointer to Stack object
 *
 * Return
 *		0	to indicate stack is not empty
 *		1	to indicate stack is empty
 */
int stackIsEmpty(Stack *stackPtr)
{
	if(stackPtr->size == 0)
		return 1;

	return 0;
}

/*
 * To check stack is full
 *
 * Input
 *		stackPtr	is a pointer to Stack object
 *
 * Return
 *		0	to indicate stack is not full
 *		1	to indicate stack is full
 */
int stackIsFull(Stack *stackPtr)
{
	if(stackPtr->size == stackPtr->length)
		return 1;
	
	return 0;
}

/*
 * To free the memory allocated by stack
 *
 * Input
 *		stackPtr	is a pointer to Stack object
 */
void stackDel(Stack *stackPtr)
{
	if(stackPtr != NULL)
	{
		free(stackPtr->buffer);
		free(stackPtr);
	}
		
}