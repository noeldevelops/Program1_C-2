// A. Noel Cothren
// acothren1@cnm.edu
// CIS 2275, Spring 2020
// Program 1

// Header.h 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 1000;
const string FILE_IN = "numbers.txt";
void WriteHeader();
bool ReadFile(int number[], int& total);
void Sort(int number[], int total);
void HighLow(int number[], int total, int* pHigh, int* pLow);
double Average(int number[], int total);
double Median(int number[], int total);
void Mode(int number[], int total, vector<int>& rModes, int& rNumModes, int& rNumTimes);
bool WriteFile(int total, double average, vector<int> modeValues, int high, int low, double median, int NumModes, string &rOutputFileName);

#endif FUNCTIONS_H;
