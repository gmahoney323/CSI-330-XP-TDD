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
			StringConverter str = new StringConverter(0);
			int expected = 123;
			// might want to separate getting input and actual conversion into two methods
			int actual = str.convertStringInput("one two three");
			Assert::AreEqual(expected, actual);
		}

		// secret feature
		// if you input an actual number (int instead of string) the program will get increasingly "mad"
		// if you input a number too many times, it will quit
		// could have a clause in the function for getting input that will increase anger member variable when given int input
		// maybe have a funny message get printed to console each time program gets mad
		TEST_METHOD(TestAnger) {
			// 0 = starting anger
			// will likely do this by checking in input function
			StringConverter str = new StringConverter(0);
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
			StringConverter str = new StringConverter(0);

			// maybe have it consider whether the second number should be + or - based on 'plus' or 'minus'
			string expected1 = 17;
			string actual1 = str.addConvert("two plus one two");
			Assert::AreEqual(expected, actual);

			string expected2 = "three";
			string actual2 = str.addConvert("nine minus six");
			Assert::AreEqual(expected, actual);
		}

		// secret feature
		// you can choose to reconvert a number to its word form
		// maybe for some flavor, have the output be a vaguely passive aggressive message, like the sample I give here
		TEST_METHOD(TestReConvert) {
			// 0 = starting anger
			StringConverter str = new StringConverter(0);
			string expected = "This SHOULD be one two.";
			string actual = str.reConvert(12);
			Assert::AreEqual(expected, actual);
		}


	};
}
