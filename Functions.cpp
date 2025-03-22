#include "Functions.h"
#include "SortingAlgorithms.h"

using namespace std;

// Function to execute sorting based on algorithm name
void startSorting(string algorithm, vector<int>& arr, unsigned long long& comparisons) {
    if (algorithm == "selection-sort") selectionSort(arr, comparisons);
    else if (algorithm == "insertion-sort") insertionSort(arr, comparisons);
    else if (algorithm == "shell-sort") shellSort(arr, comparisons);
    else if (algorithm == "bubble-sort") bubbleSort(arr, comparisons);
    else if (algorithm == "heap-sort") heapSort(arr, comparisons);
    else if (algorithm == "merge-sort") mergeSort(arr, 0, arr.size() - 1, comparisons);
    else if (algorithm == "quick-sort") quickSort(arr, 0, arr.size() - 1, comparisons);
    else if (algorithm == "radix-sort") radixSort(arr, comparisons);
    else if (algorithm == "counting-sort") countingSort(arr, comparisons);

    //Bonus explortions
    else if (algorithm == "binary-insertion-sort") binaryInsertionSort(arr, comparisons);
    else if (algorithm == "shaker-sort") shakerSort(arr, comparisons);
    else if (algorithm == "flash-sort") flashSort(arr, comparisons);
    else {
        cerr << "Invalid sorting algorithm specified." << endl;
        exit(1);
    }
}

bool isValidAlgorithm(string algorithm)
{
    vector<string> algorithms(12);
    algorithms[0] = "selection-sort";
    algorithms[1] = "insertion-sort";
    algorithms[2] = "shell-sort";
    algorithms[3] = "bubble-sort";
    algorithms[4] = "heap-sort";
    algorithms[5] = "merge-sort";
    algorithms[6] = "quick-sort";
    algorithms[7] = "radix-sort";
    algorithms[8] = "counting-sort";
    algorithms[9] = "binary-insertion-sort";
    algorithms[10] = "shaker-sort";
    algorithms[11] = "flash-sort";

    bool isValid = false;

    for (int i = 0; i < 12; i++)
    {
        if (algorithm == algorithms[i])
            isValid = true;
    }

    return isValid;
}

bool isValidFile(string fileName)
{
    if (fileName.length() >= 4 && fileName.substr(fileName.length() - 4) == ".txt") 
    {
        return true;
    }

    return false;
}

bool isValidInputSize(const string& str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}

int isValidInputOrder (string inputOrder)
{
    vector<string> orders(4);
    orders[0] = "-rand";
    orders[1] = "-sorted";
    orders[2] = "-rev";
    orders[3] = "-nsorted";

    for (int i = 0; i < orders.size(); i++)
    {
        if (inputOrder == orders[i])
            return i;
    }

    return -1;
}

bool isValidOutputParam (string outputParam)
{
    vector<string> params(3);
    params[0] = "-time";
    params[1] = "-comp";
    params[2] = "-both";

    bool isValid = false;

    for (int i = 0; i < params.size(); i++)
    {
        if (outputParam == params[i])
            isValid = true;
    }

    return isValid;
}

void readInputFile(string fileName, vector<int> &arr)
{
    ifstream fin(fileName);

    if (!fin)
    {
        cerr << "Input File Does Not Exist!";
        return;
    }

    int size;

    fin >> size;
    arr.resize(size);

    for (int i = 0; i < size; i++)
    {
        
        fin >> arr[i];
    }


    fin.close();

}

void printArrToFile (vector<int> arr, string fileName)
{
    ofstream fout(fileName);
    if (!fout)
    {
        cerr << "Can not open output file!";
        return;
    }

    fout << arr.size() << "\n";

    for (int i = 0; i < arr.size(); i++)
    {
        fout << arr[i] << " ";
    }


    fout.close();
}

void convertOrder(string &order)
{
    if (order == "-rand") order = "Randomized";
    else if (order == "-sorted") order = "Sorted";
    else if (order == "-rev") order = "Reversed";
    else if (order == "-nsorted") order = "Nearly Sorted";
}

void printTimeOutputAlgorithm(string &order, int time)
{
    if (order!= "")
    {
    convertOrder(order);

    cout << "\nInput Order: " << order;
    }

    cout << "\n------------------------";
    cout << "\nRunning Time: " << time << "ms\n";
}

void printComparisonOutputAlgorithm(string &order, unsigned long long comp)
{
    if (order!= "")
    {
    convertOrder(order);
    
    cout << "\nInput Order: " << order;
    }
    cout << "\n------------------------";
    cout << "\nComparison: " << comp << "\n";
}

void printBothOutputAlgorithm(string &order, unsigned long long comp, int time)
{
    if (order!= "")
    {
    convertOrder(order);
    
    cout << "\nInput Order: " << order;
    }
    cout << "\n------------------------";
    cout << "\nRunning Time: " << time << "ms";
    cout << "\nComparison: " << comp << "\n";
}

void printOutputComparison(string &order, int time1 , int time2 ,unsigned long long comp1, unsigned long long comp2)
{
    if (order != "")
    {
    convertOrder(order);

    cout << "\nInput Order: " << order;
    }
    cout << "\n------------------------";
    cout << "\nRunning Time: " << time1 << "ms | " << time2 << "ms";
    cout << "\nComparisons: " << comp1 << " | " << comp2 << "\n";
    
}


void printExperimentsOutput(int order, int size, string algorithm, int time, unsigned long long comparisons)
{
    vector<string> orders(4);
    orders[0] = "-rand";
    orders[1] = "-sorted";
    orders[2] = "-rev";
    orders[3] = "-nsorted";



    cout << "\n[DONE] " << orders[order] << " | " << size << " | " << algorithm << " | " << time << " ms | " << comparisons;

}