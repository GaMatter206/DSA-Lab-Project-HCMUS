#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

// Function to execute sorting based on algorithm name
void startSorting(string algorithm, vector<int>& arr, unsigned long long& comparisons);

// Functions to check Command-Line validity
bool isValidAlgorithm(string algorithm);
bool isValidFile(string fileName);
bool isValidInputSize(const string& str);
int isValidInputOrder (string inputOrder);
bool isValidOutputParam (string outputParam);

// File reading and printing functions
void readInputFile(string fileName, vector<int> &arr);
void printArrToFile (vector<int> arr, string fileName);

// Terminal output functions
void convertOrder(string &order); // This is to convert input order to normal words (Ex: -rand -> Randomized)
void printTimeOutputAlgorithm(string &order, int time);
void printComparisonOutputAlgorithm(string &order, unsigned long long comp);
void printBothOutputAlgorithm(string &order, unsigned long long comp, int time);
void printOutputComparison(string &order, int time1 , int time2 ,unsigned long long comp1, unsigned long long comp2);
