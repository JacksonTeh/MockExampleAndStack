#include "unity.h"
#include "StringReversal.h"
#include "Stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_reverseString_murkerjee_should_return_eejrekrum(void)
{
	char *result;
	
	result = reverseString("murkerjee");
	TEST_ASSERT_EQUAL_STRING("eejrekrum", result);
}
