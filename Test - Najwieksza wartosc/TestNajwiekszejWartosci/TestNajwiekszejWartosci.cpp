#include "pch.h"
#include "CppUnitTest.h"
#include "liczby.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestNajwiekszejWartosci
{
	TEST_CLASS(TestNajwiekszejWartosci)
	{
	public:
		
		TEST_METHOD(najwiekszaWartosc)
		{
			int tab[3]{ 3,5,40 };
			Liczby l1;
			
			l1.ustawLiczby(tab);

			int wynik = l1.maksLiczba();

			int oczekwianyWynik = 40;

			Assert::AreEqual(oczekwianyWynik, wynik);

		}
		TEST_METHOD(najwiekszaWartoscFalse)
		{
			int tab[3]{ 3,5,20 };
			Liczby l1;

			l1.ustawLiczby(tab);

			int wynik = l1.maksLiczba();

			int oczekwianyWynik = 30;

			Assert::AreEqual(oczekwianyWynik, wynik);
		}
	};
}
