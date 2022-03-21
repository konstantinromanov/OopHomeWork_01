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
void printStartOfTaskLine(int taskNumber);
void ltrim(string& s);
void rtrim(string& s);
void trim(string& s);

int main()
{
	string inputString = "";

	// -------------------------------------------------Mandatory exercise 1-------------------------------------------------

	vector<int> collection1;

	printStartOfTaskLine(1);

	cout << "Please enter a set of integers, separated by comma\n";

	getline(cin, inputString);

	stringstream ss(inputString);

	for (int i; ss >> i;)
	{
		collection1.push_back(i);
		if (ss.peek() == ',');
		{
			ss.ignore();
		}
	}

	exercise_1(collection1);

	// -------------------------------------------------Mandatory exercise 2-------------------------------------------------

	vector<string> collection2;
	string delimiter = ",";

	printStartOfTaskLine(2);

	cout << "Please enter a set of strings, separated by comma\n";

	getline(cin, inputString);

	int pos = 0;

	auto start = 0U;
	auto end = inputString.find(delimiter);

	while (end != string::npos)
	{
		string str = inputString.substr(start, end - start);
		trim(str);
		collection2.push_back(str);
		start = end + delimiter.length();
		end = inputString.find(delimiter, start);
	}

	string str = inputString.substr(start, start);
	trim(str);
	collection2.push_back(str);

	exercise_2(collection2);

	// -------------------------------------------------Mandatory exercise 3-------------------------------------------------

	printStartOfTaskLine(3);

	int result = exercise_3();	
}

void exercise_1(vector<int> collection) {

	int colLenght = collection.size();
	int left{ 0 };
	int right{ colLenght - 1 };
	int sum{ 0 };
	int count{ 0 };

	// sum of first and last, second first and second last etc.
	while (left <= right)
	{
		sum = collection[left++] + collection[right--];
		cout << "  sum" << (count++) + 1 << " = " << sum << endl;
	}

	//// sum of adjacent elements.
	//for (int i = 0; i < colLenght - 1; i++)
	//{
	//	int sum = collection[i] + collection[i + 1];
	//	cout << "i = " << i << "  sum = " << sum << endl;
	//}
}

void exercise_2(vector<string> collection) {

	int colLength = collection.size();

	for (int i = 0; i < colLength; i++)
	{
		string str = collection[i];
		transform(str.begin(), str.end(), str.begin(), toupper);
		collection[i] = str;
	}

	cout << "Transformed collection: " << endl;

	for (int i = 0; i < colLength; i++)
	{
		cout << (i % 8 == 0 && i != 0 ? "\n" : "") << collection[i] << (i < colLength - 1 ? ", " : "");
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

void ltrim(string& s) {
	s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !isspace(ch);
		}));
}

void rtrim(string& s) {
	s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !isspace(ch);
		}).base(), s.end());
}

void trim(string& s) {
	ltrim(s);
	rtrim(s);
}

void printStartOfTaskLine(int taskNumber) {
	cout << "\n-----------------------------------Start of task " << taskNumber << "----------------------------------------------\n";
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
