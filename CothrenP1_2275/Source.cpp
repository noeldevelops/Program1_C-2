// A. Noel Cothren
// acothren1@cnm.edu
// CIS 2275, Spring 2020
// Program 1

// Source.cpp 

#include "Header.h"

int main()
{
	const int SIZE = 1000;
	int numbers{ 0 };
	int total, high, low, rNumModes, rNumTimes = 0;
	bool fileRead = false;
	int arr[SIZE];
	double avg, median;
	vector<int> modes;
	string fileName;

	WriteHeader();
	fileRead = ReadFile(arr, total); //pass array, total # ints by ref
	if (!fileRead)
	{
		cout << "\n Error! We could not read the file.";
	}
	else
	{

		Sort(arr, total);
		HighLow(arr, total, &high, &low);
		
		avg = Average(arr, total);
		
		median = Median(arr, total);
		
		Mode(arr, total, modes, rNumModes, rNumTimes);

		cout << "\n\n Please enter the name of the output file. It should end in .txt  -->  ";
		getline(cin, fileName);
		WriteFile(total, avg, modes, high, low, median, rNumModes, rNumTimes, fileName);
	}

	cout << "\n Goodbye! Thanks for trying Program 1.";
	return 0;
}