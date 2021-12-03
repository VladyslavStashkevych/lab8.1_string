#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1_string/lab8.1_string.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
public:
	TEST_METHOD(TestMethod1) {
		string s = "aaabbbccc";
		string g = "******";
		int* arr = new int[3];
		int t = Count(s, "abc", arr);
		Assert::AreEqual(3, t);
	}
	};
}