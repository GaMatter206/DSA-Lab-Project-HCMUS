#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include "DataGenerator.h"
#include "SortingAlgorithms.h"

using namespace std;
using namespace chrono;

// Function to execute sorting based on algorithm name
void executeSorting(string algorithm, vector<int>& arr, long long& comparisons) {
    if (algorithm == "selection-sort") selectionSort(arr, comparisons);
    else if (algorithm == "insertion-sort") insertionSort(arr, comparisons);
    else if (algorithm == "shell-sort") shellSort(arr, comparisons);
    else if (algorithm == "bubble-sort") bubbleSort(arr, comparisons);
    else if (algorithm == "heap-sort") heapSort(arr, comparisons);
    else if (algorithm == "merge-sort") mergeSort(arr, 0, arr.size() - 1, comparisons);
    else if (algorithm == "quick-sort") quickSort(arr, 0, arr.size() - 1, comparisons);
    else if (algorithm == "radix-sort") radixSort(arr);
    else if (algorithm == "counting-sort") countingSort(arr);

    //Bonus explortions
    else if (algorithm == "binary-insertion-sort") binaryInsertionSort(arr, comparisons);
    else if (algorithm == "shaker-sort") shakerSort(arr, comparisons);
    else if (algorithm == "flash-sort") flashSort(arr, comparisons);
    else {
        cerr << "Invalid sorting algorithm specified." << endl;
        exit(1);
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: <execution file> -a|-c <algorithm1> [algorithm2] <input file/input size> [options]" << endl;
        return 1;
    }
    
    string mode = argv[1];
    string algorithm1 = argv[2];
    vector<int> arr, arrCopy;
    long long comparisons1 = 0, comparisons2 = 0;
    auto start1 = high_resolution_clock::now(), start2 = high_resolution_clock::now();
    auto end1 = high_resolution_clock::now(), end2 = high_resolution_clock::now();
    
    if (mode == "-a") {  // Algorithm mode
        string inputParam = argv[3];
        int size = stoi(inputParam);
        arr.resize(size);
        GenerateData(arr.data(), size, 0);
        
        start1 = high_resolution_clock::now();
        executeSorting(algorithm1, arr, comparisons1);
        end1 = high_resolution_clock::now();
        
        cout << "Time: " << duration_cast<milliseconds>(end1 - start1).count() << " ms\n";
        cout << "Comparisons: " << comparisons1 << "\n";
        
        ofstream outFile("output.txt");
        outFile << arr.size() << "\n";
        for (int num : arr) outFile << num << " ";
        outFile.close();
    }
    else if (mode == "-c") {  // Comparison mode
        if (argc < 5) {
            cerr << "Usage: <execution file> -c <algorithm1> <algorithm2> <input size>" << endl;
            return 1;
        }
        string algorithm2 = argv[3];
        string inputParam = argv[4];
        
        int size = stoi(inputParam);
        arr.resize(size);
        GenerateData(arr.data(), size, 0);
        arrCopy = arr;
        
        start1 = high_resolution_clock::now();
        executeSorting(algorithm1, arr, comparisons1);
        end1 = high_resolution_clock::now();
        
        start2 = high_resolution_clock::now();
        executeSorting(algorithm2, arrCopy, comparisons2);
        end2 = high_resolution_clock::now();
        
        cout << "Algorithm 1 - Time: " << duration_cast<milliseconds>(end1 - start1).count() << " ms, Comparisons: " << comparisons1 << "\n";
        cout << "Algorithm 2 - Time: " << duration_cast<milliseconds>(end2 - start2).count() << " ms, Comparisons: " << comparisons2 << "\n";
    }
    return 0;
}
