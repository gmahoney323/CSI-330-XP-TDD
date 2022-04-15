#include "pch.h"
#include "CppUnitTest.h"
#include "../Testing/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumTest
{
	TEST_CLASS(NumTest)
	{
	public:
		// Grant's tests
		TEST_METHOD(TestConvertInput)
		{
			StringConverter str;
			int expected = 123;
			// might want to separate getting input and actual conversion into two methods
			int actual = str.convertStringInput("one two three");
			Assert::AreEqual(expected, actual);
		}

		
		TEST_METHOD(TestAnger) {
			// 0 = starting anger
			// will do this normally by checking in input function
			StringConverter str;
			str.increaseAnger(1);
			str.increaseAnger(3);
			str.increaseAnger(1);
			int expected = 5;
			int actual = str.getAnger();
			Assert::AreEqual(expected, actual);
		}
		
		// Collin's tests
		TEST_METHOD(TestAddition)
		{
			StringConverter str;

			// maybe have it consider whether the second number should be + or - based on 'plus' or 'minus'
			int expected1 = 14;
			int actual1 = str.addConvert("two plus one two");
			Assert::AreEqual(expected1, actual1);

			int expected2 = 3;
			int actual2 = str.minusConvert("nine minus six");
			Assert::AreEqual(expected2, actual2);
		}


		TEST_METHOD(TestReConvert) {
			// 0 = starting anger
			StringConverter str;
			string expected = "This SHOULD be one two.";
			string actual = str.reConvert(12);
			Assert::AreEqual(expected, actual);
		}
	};
}
