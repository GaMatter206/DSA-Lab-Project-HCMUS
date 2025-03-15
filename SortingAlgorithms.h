#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>
#include <algorithm>
using namespace std;

// Sorting function prototypes
void selectionSort(vector<int>& arr, long long& comparisons);
void insertionSort(vector<int>& arr, long long& comparisons);
void binaryInsertionSort(vector<int>& arr, long long& comparisons);
void bubbleSort(vector<int>& arr, long long& comparisons);
void shakerSort(vector<int>& arr, long long& comparisons);
void shellSort(vector<int>& arr, long long& comparisons);
void heapSort(vector<int>& arr, long long& comparisons);
void mergeSort(vector<int>& arr, int left, int right, long long& comparisons);
void quickSort(vector<int>& arr, int low, int high, long long& comparisons);
void radixSort(vector<int>& arr);
void countingSort(vector<int>& arr);
void flashSort(vector<int>& arr, long long& comparisons);

// Helper functions
void merge(vector<int>& arr, int left, int mid, int right, long long& comparisons);
int partition(vector<int>& arr, int low, int high, long long& comparisons);
void heapify(vector<int>& arr, int n, int i, long long& comparisons);

#endif