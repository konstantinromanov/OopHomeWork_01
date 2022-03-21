// OopHomeWork_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
#include <iomanip> 
#include <sstream>
using namespace std;

void exercise_1(vector<int> collection);
void exercise_2(vector<string> collection);
int exercise_3();
void bonus_exercise_1(char c);
//void printEndOfTaskLine(int taskNumber);
void printLine(int lenght);
void printStartOfTaskLine(int taskNumber);
void printIntSqrCubTable(int lowerLimit, int upperLimit);


int main()
{
	string inputString = "";

	// -------------------------------------------------Mandatory exercise 1-------------------------------------------------

	vector<int> collection1;

	printStartOfTaskLine(1);

	cout << "Please enter a set of integers, separated by comma\n";

	cin >> inputString;
	stringstream ss(inputString);	

	for (int i; ss >> i;)
	{
		collection1.push_back(i);
		if (ss.peek() == ',');
		{
			ss.ignore();
		}
	}
		
	//exercise_1(collection1);

	//printEndOfTaskLine(1);

	// -------------------------------------------------Mandatory exercise 2-------------------------------------------------

	vector<string> collection2;
	string delimiter = ",";

	printStartOfTaskLine(2);

	cout << "Please enter a set of strings, separated by comma\n";

	//cin >> inputString;

	int pos = 0;

	/*string token;
	while ((pos = inputString.find(delimiter)) != std::string::npos) // by mutating original string
	{
		token = inputString.substr(0, pos);
		collection2.push_back(token);
		inputString.erase(0, pos + delimiter.length());
	}

	collection2.push_back(inputString);*/

	auto start = 0U;
	auto end = inputString.find(delimiter);
	while (end != std::string::npos)
	{
		collection2.push_back(inputString.substr(start, end - start));
		start = end + delimiter.length();
		end = inputString.find(delimiter, start);
	}

	collection2.push_back(inputString.substr(start, end));

	//stringstream ss(inputString);
	/*stringstream ss2(inputString);

	for (int i; ss2 >> i;)
	{
		collection2.push_back(i);
		if (ss2.peek() == ',');
		{
			ss2.ignore();
		}
	}*/


	//vector<string> collection2{ "str1", "str2", "test3", "rambo", "rimi", "dodge", "retro", "ambitions", "str1", "str2", "test3", "rambo", "rimi", "dodge", "retro", "ambitions" };
	//exercise_2(collection2);
	//printEndOfTaskLine(2);

	// -------------------------------------------------Mandatory exercise 3-------------------------------------------------

	printStartOfTaskLine(3);

	//int result = exercise_3();
	//printEndOfTaskLine(3);

	// bonus_exercise_1('Z');


	printIntSqrCubTable(10, 25);
}

void printIntSqrCubTable(int lowerLimit, int upperLimit) {

	printLine(30);
	cout << right << /*setfill('.') << */setw(10) << "Integer" << setw(10) << "Square" << setw(10) << "Cube" << "\n";
	printLine(30);
	for (size_t i = lowerLimit; i <= upperLimit; i++)
	{
		
		cout << right << /*setfill('.') <<*/ setw(10) << i << setw(10) << pow(i, 2) << setw(10) << pow(i, 3) << "\n";
		printLine(30);

	}

}

void printLine(int lenght) {

	cout << string(lenght, '-') << endl;
	//cout << "\n-----------------------------------------------------------------------------------\n";
}

void printStartOfTaskLine(int taskNumber) {
	cout << "\n-----------------------------------Start of task " << taskNumber << "----------------------------------------------\n";
}

void bonus_exercise_1(char c) {

	int counter = c - 'A';

	for (size_t i = 0; i <= counter; i++)
	{
		/*auto printSpaces = [](int counter, int i) {
			for (size_t j = 0; j < counter - i; j++)
			{
				cout << ' ';
			}
		};*/

		//printSpaces(counter, i);

		for (size_t j = 0; j < counter - i; j++)
		{
			cout << ' ';
		}

		for (size_t j = 0; j < i; j++)
		{
			char curC = 'A' + j;
			cout << curC;
		}

		char curMC = 'A' + i;
		cout << curMC;

		for (size_t j = i; j > 0; j--)
		{
			char curC = 'A' + j - 1;
			cout << curC;
		}

		/*for (size_t j = 0; j < i; j++)
		{
			char curC = c - (counter - i + j + 1);
			cout << curC;
		}*/

		//printSpaces(counter, i);

		cout << endl;
	}
}

void exercise_2(vector<string> collection) {

	for (int i = 0; i < collection.size(); i++)
	{
		string str = collection[i];
		transform(str.begin(), str.end(), str.begin(), ::toupper);
		collection[i] = str;
	}

	for (int i = 0; i < collection.size(); i++)
	{
		cout << (i % 8 == 0 && i != 0 ? "\n" : "") << collection[i] << "  ";
	}
}

int exercise_3() {

	int number = 50;
	int sum{ 0 };

	while (number <= 100)
	{
		if (number % 2 == 0)
		{
			sum += number;
		}

		number++;
	}

	cout << "\nThe sum of the even numers from 50 to 100 is " << sum << "\n";

	return sum;
}

void exercise_1(vector<int> collection) {

	int colLenght = collection.size();
	// sum of adjacent elements.
	/*for (int i = 0; i < colLenght - 1; i++)
	{
		int sum = collection[i] + collection[i + 1];
		cout << "i = " << i << "  sum = " << sum << endl;
	}*/

	// sum of first and last, second first and second last etc.
	for (int i = 0; i < colLenght / 2; i++)
	{
		int sum = collection[i] + collection[colLenght - 1 - i];
		cout << "i = " << i << "  sum = " << sum << endl;
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file