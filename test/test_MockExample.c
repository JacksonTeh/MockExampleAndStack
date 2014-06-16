#include "unity.h"
#include "MockExample.h"
//#include "Stack.h"
#include "mock_Stack.h"  //it will create mock function automatically

void setUp(void)
{
}

void tearDown(void)
{
}

void test_reverseString_exploration(void)
{
	char *result;
	//Create test fixture
	Stack stackInstance;							//setting up test fixture
	// int staticStackBuffer[10];						//through stackNew
	// stackInstance.buffer = staticStackBuffer;		//if u nid it
	// stackInstance.length = 512;
	// stackInstance.size = 0;
	// printf("stackInstance:%p \n", &stackInstance);
	
	//Mock
	stackNew_ExpectAndReturn(512, &stackInstance);
	stackPush_Expect(&stackInstance, 'b');
	stackPush_Expect(&stackInstance, 'a');
	stackPush_Expect(&stackInstance, 'n');
	stackPush_Expect(&stackInstance, 'a');
	stackPush_Expect(&stackInstance, 'n');
	stackPush_Expect(&stackInstance, 'a');
	
	stackIsEmpty_ExpectAndReturn(&stackInstance, 0);
	stackPop_ExpectAndReturn(&stackInstance, 'a');
	stackIsEmpty_ExpectAndReturn(&stackInstance, 0);
	stackPop_ExpectAndReturn(&stackInstance, 'n');
	stackIsEmpty_ExpectAndReturn(&stackInstance, 0);
	stackPop_ExpectAndReturn(&stackInstance, 'a');
	stackIsEmpty_ExpectAndReturn(&stackInstance, 0);
	stackPop_ExpectAndReturn(&stackInstance, 'n');
	stackIsEmpty_ExpectAndReturn(&stackInstance, 0);
	stackPop_ExpectAndReturn(&stackInstance, 'a');
	stackIsEmpty_ExpectAndReturn(&stackInstance, 0);
	stackPop_ExpectAndReturn(&stackInstance, 'b');
	stackIsEmpty_ExpectAndReturn(&stackInstance, 1);
	
	//Run
	result = reverseString("banana");
	TEST_ASSERT_EQUAL_STRING("ananab", result);
}
