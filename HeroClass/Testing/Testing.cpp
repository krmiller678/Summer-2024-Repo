#include "pch.h" // pre-compile header -> not super important (can delete just have to turn off)
#include "CppUnitTest.h" // absolutely need this one
#include "Hero.h" // we need Hero.cpp ==> hero.obj as well

// Two important notes -> under properties for this project (projects compose the total solution)
// you are going to go to C++ and the Linkers general tabs to add in additional include
// directories as well as library directories

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int AddTwo(int a, int b)
{
	return a + b;
}

namespace Testing
{
	TEST_CLASS(Testing)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// AAA Approach - Arrange, Act, Assert

			// Arrange - set up your test
			int x = 5;
			int y = 10;

			// Act - Code that will be tested
			int result = AddTwo(x, y);

			// Assert - validate results
			Assert::AreEqual(15, result);
		}
		TEST_METHOD(HeroConstructor)
		{
			string name = "Thor";
			Hero hero(name, 50, 125);

			Assert::AreEqual(name, hero.GetName());
		}
	};
}
