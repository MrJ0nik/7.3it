#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3it/7.3it.cpp"  

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_CyclicShiftMatrix)
		{
			const int n = 3;
			int** matrix = new int* [n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[n];
			}

			
			int data[3][3] = {
				{ 1, 2, 3 },
				{ 4, 5, 6 },
				{ 7, 8, 9 }
			};
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = data[i][j];
				}
			}

		
			int expected[3][3] = {
				{ 4, 1, 2 },
				{ 7, 5, 3 },
				{ 8, 9, 6 }
			};

			
			CyclicShiftMatrix(matrix, n, 1);

			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					Assert::AreEqual(expected[i][j], matrix[i][j]);
				}
			}

			
			for (int i = 0; i < n; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		TEST_METHOD(Test_FindLastColumnWithMaxZeros)
		{
			const int n = 3;
			int** matrix = new int* [n];
			for (int i = 0; i < n; i++) {
				matrix[i] = new int[n];
			}

			
			int data[3][3] = {
				{ 1, 0, 0 },
				{ 0, 1, 0 },
				{ 0, 0, 1 }
			};
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = data[i][j];
				}
			}

			
			int expectedColumn = 2;

			
			int result = FindLastColumnWithMaxZeros(matrix, n);

		
			Assert::AreEqual(expectedColumn, result);

			
			for (int i = 0; i < n; i++) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}
