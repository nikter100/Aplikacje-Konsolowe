#include "pch.h"
#include "CppUnitTest.h"
#include "NWD.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(test1)
		{
			int a = 5, b = 25;
			NWD funkcja1;

			funkcja1.uzupelnijLiczby(a, b);

			int wynik = funkcja1.szukanieNWD();

			int oczekiwany = 5;

			Assert::AreEqual(oczekiwany, wynik);
		}
		TEST_METHOD(test2)
		{
			int a = 7, b = 14;
			NWD funkcja1;

			funkcja1.uzupelnijLiczby(a, b);

			int wynik = funkcja1.szukanieNWD();

			int oczekiwany = 7;

			Assert::AreEqual(oczekiwany, wynik);
		}
		TEST_METHOD(test3Negative)
		{
			int a = 5, b = 15;
			NWD funkcja1;

			funkcja1.uzupelnijLiczby(a, b);

			int wynik = funkcja1.szukanieNWD();

			int oczekiwany = 3;

			Assert::AreEqual(oczekiwany, wynik);
		}
	};
}
