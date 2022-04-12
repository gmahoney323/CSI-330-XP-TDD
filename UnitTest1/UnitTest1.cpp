#include "pch.h"
#include "CppUnitTest.h"
#include "../Testing/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestClassInit)
		{
			coolClass testclass = coolClass();
			Assert::IsTrue(testclass.thisIsTrue());
		}

		TEST_METHOD(TestMethod1) {
			int i = 2;
			int j = 2;
			int actual = i * j;
			Assert::AreEqual(4, actual);
		}

		TEST_METHOD(TestMethod2) {
			bool boolean = true;
			Assert::IsTrue(boolean);
		}
		
	};
}
