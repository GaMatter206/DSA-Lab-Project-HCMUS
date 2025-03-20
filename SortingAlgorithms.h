#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

// Sorting function prototypes
void selectionSort(vector<int>& arr, unsigned long long& comparisons);
void insertionSort(vector<int>& arr, unsigned long long& comparisons);
void shellSort(vector<int>& arr, unsigned long long& comparisons);
void bubbleSort(vector<int>& arr, unsigned long long& comparisons);
void heapSort(vector<int>& arr, unsigned long long& comparisons);
void mergeSort(vector<int>& arr, int left, int right, unsigned long long& comparisons);
void quickSort(vector<int>& arr, int low, int high, unsigned long long& comparisons);
void radixSort(vector<int>& arr, unsigned long long& comparisons);
void countingSort(vector<int>& arr, unsigned long long& comparisons);

//---------------BONUS EXPLORATIONS---------------
void binaryInsertionSort(vector<int>& arr, unsigned long long& comparisons);
void shakerSort(vector<int>& arr, unsigned long long& comparisons);
void flashSort(vector<int>& arr, unsigned long long& comparisons);

// Helper functions
void heapify(vector<int>& arr, int n, int i, unsigned long long& comparisons);
void merge(vector<int>& arr, int left, int mid, int right, unsigned long long& comparisons);
int medianOfThree(vector<int>& arr, int low, int high, unsigned long long& comparisons);
int partition(vector<int>& arr, int low, int high, unsigned long long& comparisons);
void countingSortForRadix(vector<int>& arr, int exp, unsigned long long& comparisons);

#endif