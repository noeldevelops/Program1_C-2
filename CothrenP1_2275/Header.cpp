// A. Noel Cothren
// acothren1@cnm.edu
// CIS 2275, Spring 2020
// Program 1

// Header.cpp

#include "Header.h"

void WriteHeader()
{
	cout << "\n A. Noel Cothren"
		<< "\n Program 1 - Arrays & Statistics"
		<< "\n Read a file into an array, sort the array, and determine the average, median, mode(s) and high and low values.";
}

bool ReadFile(int arr[], int& rTotal)
{
	ifstream input;
	ofstream output;
	
	// open the file
	input.open(FILE_IN);

	// exit if the file can't be read
	if (!input)
	{
		
		return false;
	}
	//read in numbers
	int i{0};
	while (i < SIZE && !input.eof()) 
	{
		input >> arr[i];
		i++;
	}
	//assign total
	rTotal = i;
	
	//close file
	input.close();
	return true;
}

void Sort(int arr[], int total)
{
	int i, j, temp;
	for (i = 0; i < (total - 1); ++i)
	{
		for (j = 1; j < total; ++j)
		{
			if (arr[j-1] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

void HighLow(int arr[], int total, int* pHigh, int* pLow)
{
	//the array is already sorted so the low is in index 0...
	*pLow = arr[0];
	//...and the high is in the last place, as determined by the total we gathered while reading file
	*pHigh = arr[total-1];
}

double Average(int arr[], int total)
{
	// gotta get the ints to doubles
	double sum = 0.0;
	for (int i = 0; i < total; ++i)
	{
		sum = sum + arr[i];
	}
	return sum/total;
}

double Median(int arr[], int total)
{
	double median = 0.0;
	//is total even or odd?
	if (total % 2 > 0)
	{
		median = arr[total / 2];
	}
	else 
	{
		median = (arr[total / 2] + arr[total / 2 - 1]) / 2.0;
	}
	return median;
}

void Mode(int arr[], int total, vector<int>& rModes, int& rNumModes, int& rNumTimes)
{
	//by now, the array is sorted
	int j{ 0 };
	int current, localFrequency{ 0 };
	int maxFreq = 0;
	rNumModes = 0; //this is also the vector.size, not needed!
	rNumTimes = 0;
	//use a while loop, not for loop, to control incrementing
	while (j < total)
	{
		current = arr[j];
		localFrequency = 0;

		while (current == arr[j])
		{
			localFrequency++;
			j++;
			//compare local to max freq
			if (localFrequency > maxFreq)
			{
				maxFreq = localFrequency;
				rNumTimes = maxFreq;
				//clear vector, push new max freq
				rModes.clear();
				rModes.push_back(current);
			}
			else if (localFrequency == maxFreq)	//if they are same, add current val to vector
			{
				rModes.push_back(current);
			}
		}
		
	}
}

bool WriteFile(int total, double average, vector<int> modes, int high, int low, double median, int& rNumModes, int& rNumTimes, string& rOutputFileName)
{
	ofstream output;

	output.open(rOutputFileName.c_str());
	if (!output) {
		return false;
	}
	else {
		output.setf(ios::fixed);
		output.precision(2);
		output << "\n A. Noel Cothren"
			<< "\n Program 1 - Arrays & Statistics"
			<< "\n Read a file into an array, sort the array, and determine the average, median, mode(s) and high and low values.\n";
		output << "\n "<< FILE_IN << " file successfully read and " << total << " numbers were found.\n";
		output << "\n The highest number is " << high
			<< "\n The lowest number is " << low;
		output << "\n The average is " << average;
		output << "\n The median is " << median;
		output << "\n The modes are ";
		for (int i = 0; i < modes.size(); ++i)
		{
			output << modes[i] << ", ";
		}
		output << "and they each appear " << rNumTimes << " times.";

		cout << "\n Your file was saved as " << rOutputFileName;
	}
	output.close();
	return true;
}
