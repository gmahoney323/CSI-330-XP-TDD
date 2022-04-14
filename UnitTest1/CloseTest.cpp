#include "pch.h"
#include "CppUnitTest.h"
#include "../Testing/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CloseTest
{
	TEST_CLASS(CloseTest)
	{
	public:
		
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
			StringConverter str = new StringConverter(0);
			str.increaseAnger(1);
			str.increaseAnger(3);
			str.increaseAnger(1);
			int expected = 5;
			int actual = str.getAnger();
			Assert::AreEqual(expected, actual);
		}
	};
}
