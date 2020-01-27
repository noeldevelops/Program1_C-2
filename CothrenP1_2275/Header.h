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
#include <iostream>

using namespace std;

const int SIZE = 1000;
const string FILE_IN = "Numbers.txt";
void WriteHeader();
bool ReadFile(int arr[], int& rTotal);
void Sort(int arr[], int total);
void HighLow(int arr[], int total, int* pHigh, int* pLow);
double Average(int arr[], int total);
double Median(int arr[], int total);
void Mode(int arr[], int total, vector<int>& rModes, int& rNumModes, int& rNumTimes);
bool WriteFile(int total, double average, vector<int> modeValues, int high, int low, double median, int &rNumModes, int &rNumTimes, string &rOutputFileName);

#endif FUNCTIONS_H;
