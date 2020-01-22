// A. Noel Cothren
// acothren1@cnm.edu
// CIS 2275, Spring 2020
// Program 1

// Header.cpp

#include "Header.h"

void WriteHeader()
{
}

bool ReadFile(int number[], int& total)
{
	ifstream input;
	input.open(FILE_IN);
	if (!input)
	{
		//cout message
		return false;
	}
	//read in numbers
	int i{0};
	while (i < SIZE && !(input.eof)) 
	{
		input >> number[i];
		i++;
	}
	//assign total
	//close file
	input.close();
	return true;
}

void Sort(int number[], int total)
{
}

void HighLow(int number[], int total, int* pHigh, int* pLow)
{
}

double Average(int number[], int total)
{
	// gotta get the ints to doubles
	return 0.0;
}

double Median(int number[], int total)
{
	//if odd, total numbers divided by 2 as int rounds down
	//if even, n[total/2] + n[total/2-1] / 2.0;
	return 0.0;
}

void Mode(int number[], int total, vector<int>& rModes, int& rNumModes, int& rNumTimes)
{
	//by now, the array is sorted
	int j{ 0 };
	int current, localFrequency{ 0 };
	rNumModes = 0;
	rNumTimes = 0;
	//use a loop, not for loop (to control incrementing)
	while (j < total)
	{
		current = number[j];
		while (current == number[j])
		{
			localFrequency++;
			j++;
		}
		//compare local to max freq
		//if local >= max, max = local;
		//then clear vector, push new max freq
		//if local == max, max = local;
		//if they are same, increment num modes
		//add current val to vector
	}
}

bool WriteFile(int total, double average, vector<int> modeValues, int high, int low, double median, int NumModes, string& rOutputFileName)
{
	return false;
}
