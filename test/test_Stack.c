#include "unity.h"
#include "Stack.h"
#include "CException.h"
#include "ErrorCode.h"
#include "stdio.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_stackIsFull_given_full_stack_should_return_1(void)
{
	int result;
	Stack *stack = stackNew(3);

	stack->size = 3;
	result = stackIsFull(stack);
	
	TEST_ASSERT_EQUAL(3, stack->length);
	TEST_ASSERT_EQUAL(3, stack->size);
	TEST_ASSERT_EQUAL(1, result);
	
	stackDel(stack);
}

void test_stackIsFull_return_0_to_indicate_stack_is_not_full(void)
{
	int result;
	Stack *stack = stackNew(3);

	stack->size = 2;
	result = stackIsFull(stack);
	
	TEST_ASSERT_EQUAL(3, stack->length);
	TEST_ASSERT_EQUAL(2, stack->size);
	TEST_ASSERT_EQUAL(0, result);
	
	stackDel(stack);
}

void test_stackPush_given_length_of_2__and_push_exceed_the_length_into_stack_should_raise_an_exception(void)
{
	CEXCEPTION_T err;
	Stack *stack = stackNew(2);
	
	Try{
		stackPush(stack, 'b');
		stackPush(stack, 'a');
		stackPush(stack, 'n');
		TEST_FAIL_MESSAGE("Should generate an exception due to the stack full");
	}Catch(err)
	{	
		TEST_ASSERT_EQUAL_MESSAGE(ERR_STACK_IS_FULL, err, "Expected ERR_STACK_IS_FULL exception");
		printf("Success: Exception generated. Error code: %d.\n", err);
	}
	
	TEST_ASSERT_EQUAL(2, stack->length);
	TEST_ASSERT_EQUAL(2, stack->size);
	
	stackDel(stack);
}

void test_stackPush_given_banana_push_into_stack_should_store_in_the_stack(void)
{
	Stack *stack = stackNew(6);
	
	stackPush(stack, 'b');
	stackPush(stack, 'a');
	stackPush(stack, 'n');
	stackPush(stack, 'a');
	stackPush(stack, 'n');
	stackPush(stack, 'a');
	
	TEST_ASSERT_EQUAL('b', stack->buffer[0]);
	TEST_ASSERT_EQUAL('a', stack->buffer[1]);
	TEST_ASSERT_EQUAL('n', stack->buffer[2]);
	TEST_ASSERT_EQUAL('a', stack->buffer[3]);
	TEST_ASSERT_EQUAL('n', stack->buffer[4]);
	TEST_ASSERT_EQUAL('a', stack->buffer[5]);
	TEST_ASSERT_EQUAL(6, stack->length);
	TEST_ASSERT_EQUAL(6, stack->size);
	
	stackDel(stack);
}

void test_stackIsEmpty_given_empty_stack_should_return_1(void)
{
	int result;
	Stack *stack = stackNew(3);

	result = stackIsEmpty(stack);
	
	TEST_ASSERT_EQUAL(3, stack->length);
	TEST_ASSERT_EQUAL(0, stack->size);
	TEST_ASSERT_EQUAL(1, result);
	
	stackDel(stack);
}

void test_stackIsEmpty_given_b_in_stack_should_return_0_to_indicate_stack_is_not_empty(void)
{
	int result;
	Stack *stack = stackNew(3);

	stackPush(stack, 'b');	
	result = stackIsEmpty(stack);
	
	TEST_ASSERT_EQUAL(3, stack->length);
	TEST_ASSERT_EQUAL(1, stack->size);
	TEST_ASSERT_EQUAL(0, result);
	
	stackDel(stack);
}

void test_stackPop_given_empty_stack_should_raise_an_exception(void)
{
	CEXCEPTION_T err;
	char result;
	Stack *stack = stackNew(3);

	Try
	{
		result = stackPop(stack);
		TEST_FAIL_MESSAGE("Should generate an exception due to the stack empty");
	}Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_STACK_IS_EMPTY, err, "Expected ERR_STACK_IS_EMPTY exception");
		printf("Success: Exception generated. Error code: %d.\n", err);
	}
	
	TEST_ASSERT_EQUAL(3, stack->length);
	TEST_ASSERT_EQUAL(0, stack->size);
	
	stackDel(stack);
}

void test_stackPop_given_banana_in_the_stack_and_pop_one_time_should_pop_up_a(void)
{
	char result;
	Stack *stack = stackNew(6);
	
	stackPush(stack, 'b');
	stackPush(stack, 'a');
	stackPush(stack, 'n');
	stackPush(stack, 'a');
	stackPush(stack, 'n');
	stackPush(stack, 'a');
	result = stackPop(stack);
	
	TEST_ASSERT_EQUAL(6, stack->length);
	TEST_ASSERT_EQUAL(5, stack->size);
	TEST_ASSERT_EQUAL('a', result);
	
	stackDel(stack);
}

void test_stackPop_given_banana_in_the_stack_and_pop_4_time_should_pop_up_a_n_a_n(void)
{
	char result;
	Stack *stack = stackNew(6);
	
	stackPush(stack, 'b');
	stackPush(stack, 'a');
	stackPush(stack, 'n');
	stackPush(stack, 'a');
	stackPush(stack, 'n');
	stackPush(stack, 'a');
	
	result = stackPop(stack);
	TEST_ASSERT_EQUAL('a', result);
	result = stackPop(stack);
	TEST_ASSERT_EQUAL('n', result);
	result = stackPop(stack);
	TEST_ASSERT_EQUAL('a', result);
	result = stackPop(stack);
	TEST_ASSERT_EQUAL('n', result);
	
	TEST_ASSERT_EQUAL(6, stack->length);
	TEST_ASSERT_EQUAL(2, stack->size);
	
	stackDel(stack);
}

void test_stackPop_given_ban_in_the_stack_and_pop_all_should_return_nab_and_pop_again_should_throw_an_exception(void)
{
	CEXCEPTION_T err;
	char result;
	Stack *stack = stackNew(3);
	
	stackPush(stack, 'b');
	stackPush(stack, 'a');
	stackPush(stack, 'n');
	
	result = stackPop(stack);
	TEST_ASSERT_EQUAL('n', result);
	result = stackPop(stack);
	TEST_ASSERT_EQUAL('a', result);
	result = stackPop(stack);
	TEST_ASSERT_EQUAL('b', result);

	Try
	{
		result = stackPop(stack);
		TEST_FAIL_MESSAGE("Should generate an exception due to the stack empty");
	}Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_STACK_IS_EMPTY, err, "Expected ERR_STACK_IS_EMPTY exception");
		printf("Success: Exception generated. Error code: %d.\n", err);
	}
	
	TEST_ASSERT_EQUAL(3, stack->length);
	TEST_ASSERT_EQUAL(0, stack->size);
	
	stackDel(stack);
}