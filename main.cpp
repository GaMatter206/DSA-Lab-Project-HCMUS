#include <iostream>
#include <chrono>
#include "DataGenerator.h"
#include "SortingAlgorithms.h"
#include "Functions.h"

using namespace std;
using namespace chrono;


// Main function
int main(int argc, char* argv[]) 
{
    if (argc < 5 || argc > 6) 
    {
        cerr << "Usage: <execution file> -a|-c <algorithm1> [algorithm2] <input file(.txt)/input size> [options]" << endl;
        return 1;
    }
    
    string mode = argv[1];
    string algorithm1 = argv[2];
    vector<int> arr1, arrCopy1;
    unsigned long long comparisons1 = 0;
    int time1 = 0;
    auto start1 = high_resolution_clock::now(), start2 = high_resolution_clock::now();
    auto end1 = high_resolution_clock::now(), end2 = high_resolution_clock::now();
    
    if (mode == "-a") // Algorithm mode
    {  
        cout << "\n-----ALGORITHM MODE------\n";

        if (!isValidAlgorithm(algorithm1))
        {
            cerr <<  "Invalid Input Algorithm";
            return 1;
        }

        cout << "\nAlgorithm: " << algorithm1;

        string inputParam = argv[3];

        if (isValidFile(inputParam))
        {
            if (isValidOutputParam(argv[4]))
            {
                readInputFile(inputParam, arr1);

                cout << "\nInput File: " << inputParam;
                cout << "\nInput Size: " << arr1.size();

                arrCopy1 = arr1;

                start1 = high_resolution_clock::now();
                startSorting(algorithm1, arrCopy1, comparisons1);
                end1 = high_resolution_clock::now();

                printArrToFile(arrCopy1, "output.txt");
                
                string order1 = "";
                time1 = duration_cast<milliseconds>(end1 - start1).count();

                string outputParam = argv[4];
                    
                if (outputParam == "-time")
                    printTimeOutputAlgorithm(order1, time1);

                else if (outputParam == "-comp")
                    printComparisonOutputAlgorithm(order1, comparisons1);

                else if (outputParam == "-both")
                    printBothOutputAlgorithm(order1, comparisons1, time1);

            }
            
            else 
            {
                cerr << "Invalid Output Parameter!";
                return 1;
            }
        }

        else if (isValidInputSize(inputParam))
        {
            int size = stoi(inputParam);
            arr1.resize(size);
            int order = isValidInputOrder(argv[4]);

            cout << "\nInput Size: " << size << endl;

            if (order != -1)
            {
                if (isValidOutputParam(argv[5]))
                {
                    GenerateData(arr1, size, order);
                    printArrToFile(arr1, "input.txt");

                    arrCopy1 = arr1;

                    start1 = high_resolution_clock::now();
                    startSorting(algorithm1, arrCopy1, comparisons1);
                    end1 = high_resolution_clock::now();
                    
                    printArrToFile(arrCopy1, "output.txt");

                    string order1 = argv[4];
                    time1 = duration_cast<milliseconds>(end1 - start1).count();

                    string outputParam = argv[5];
                    
                    if (outputParam == "-time")
                        printTimeOutputAlgorithm(order1, time1);

                    else if (outputParam == "-comp")
                        printComparisonOutputAlgorithm(order1, comparisons1);

                    else if (outputParam == "-both")
                        printBothOutputAlgorithm(order1, comparisons1, time1);
                }

                else
                {
                    cerr << "Invalid Output Parameter!";
                    return 1;
                }

            }

            else if (isValidOutputParam(argv[4]))
            {
                vector<int> arr2, arrCopy2;
                vector<int> arr3, arrCopy3;
                vector<int> arr4, arrCopy4;
                int time2, time3, time4;
                unsigned long long comparisons2 = 0, comparisons3 = 0, comparisons4 = 0;
                auto start3 = high_resolution_clock::now(), start4 = high_resolution_clock::now();
                auto end3 = high_resolution_clock::now(), end4 = high_resolution_clock::now();
                string order1 = "-rand", order2 = "-nsorted", order3 = "-sorted", order4 = "-rev";


                GenerateData(arr1, size, 0);
                printArrToFile(arr1, "input_1.txt");

                GenerateData(arr2, size, 3);
                printArrToFile(arr2, "input_2.txt");

                GenerateData(arr3, size, 1);
                printArrToFile(arr3, "input_3.txt");

                GenerateData(arr4, size, 2);
                printArrToFile(arr4, "input_4.txt");

                
                arrCopy1 = arr1; 
                arrCopy2 = arr2;
                arrCopy3 = arr3;
                arrCopy4 = arr4;


                start1 = high_resolution_clock::now();
                startSorting(algorithm1, arrCopy1, comparisons1);
                end1 = high_resolution_clock::now();
                printArrToFile(arrCopy1, "output_1.txt");

                start2 = high_resolution_clock::now();
                startSorting(algorithm1, arrCopy2, comparisons2);
                end2 = high_resolution_clock::now();
                printArrToFile(arrCopy2, "output_2.txt");

                start3 = high_resolution_clock::now();
                startSorting(algorithm1, arrCopy3, comparisons3);
                end3 = high_resolution_clock::now();
                printArrToFile(arrCopy3, "output_3.txt");

                start4 = high_resolution_clock::now();
                startSorting(algorithm1, arrCopy4, comparisons4);
                end4 = high_resolution_clock::now();
                printArrToFile(arrCopy4, "output_4.txt");


                time1 = duration_cast<milliseconds>(end1 - start1).count();
                time2 = duration_cast<milliseconds>(end2 - start2).count();
                time3 = duration_cast<milliseconds>(end3 - start3).count();
                time4 = duration_cast<milliseconds>(end4 - start4).count();

                string outputParam = argv[4];
                    
                if (outputParam == "-time")
                {
                    printTimeOutputAlgorithm(order1, time1);
                    printTimeOutputAlgorithm(order2, time2);
                    printTimeOutputAlgorithm(order3, time3);
                    printTimeOutputAlgorithm(order4, time4);
                }

                else if (outputParam == "-comp")
                {
                    printComparisonOutputAlgorithm(order1, comparisons1);
                    printComparisonOutputAlgorithm(order2, comparisons2);
                    printComparisonOutputAlgorithm(order3, comparisons3);
                    printComparisonOutputAlgorithm(order4, comparisons4);
                }

                else if (outputParam == "-both")
                {
                    printBothOutputAlgorithm(order1, comparisons1, time1);
                    printBothOutputAlgorithm(order2, comparisons2, time2);
                    printBothOutputAlgorithm(order3, comparisons3, time3);
                    printBothOutputAlgorithm(order4, comparisons4, time4);
                }
            }
            
            else
            {
                cerr << "Usage: <execution file> -a <algorithm1> <input size> [options]" << endl;
                return 1;
            }
        }

        else
        {
            cerr << "Usage: <execution file> -a <algorithm1> <input file(.txt)/input size> [options]" << endl;
            return 1;
        }
    }


    else if (mode == "-c") // Comparison mode
    {  
        cout << "\n-----COMPARISON MODE------\n";

        string algorithm2 = argv[3];
        string inputParam = argv[4];

        if (!isValidAlgorithm(algorithm1))
        {
            cerr <<  "\nInput Algorithm 1 Invalid\n";
            return 1;
        }

        if (!isValidAlgorithm(algorithm2))
        {
            cerr <<  "\nInput Algorithm 2 Invalid\n";
            return 1;
        }
        
        cout << "\nAlgorithm: " << algorithm1 << " | " << algorithm2;

        if (isValidFile(inputParam))
        {
            readInputFile(inputParam, arr1);

            string order1 = "";
            vector<int> arrCopy2;
            unsigned long long comparisons2 = 0;
            int time2;

            arrCopy1 = arr1;
            arrCopy2 = arr1;

            cout << "\nInput File: " << inputParam;
            cout << "\nInput Size: " << arr1.size();

            
            start1 = high_resolution_clock::now();
            startSorting(algorithm1, arrCopy1, comparisons1);
            end1 = high_resolution_clock::now();
            printArrToFile(arrCopy1, "output_1.txt");

            start2 = high_resolution_clock::now();
            startSorting(algorithm1, arrCopy2, comparisons2);
            end2 = high_resolution_clock::now();
            printArrToFile(arrCopy2, "output_2.txt");
                
            time1 = duration_cast<milliseconds>(end1 - start1).count();
            time2 = duration_cast<milliseconds>(end2 - start2).count();

            printOutputComparison(order1, time1, time2, comparisons1, comparisons2);
        }

        else if (isValidInputSize(inputParam))
        {
            int size = stoi(inputParam);
            arr1.resize(size);
            int order = isValidInputOrder(argv[5]);

            cout << "\nInput Size: " << size << endl;

            if (order != -1)
            {
                string order1 = argv[5];
                vector<int> arrCopy2;
                unsigned long long comparisons2;
                int time2;

                GenerateData(arr1, size, order);
                printArrToFile(arr1, "input.txt");

                arrCopy1 = arr1;
                arrCopy2 = arr1;
                
                start1 = high_resolution_clock::now();
                startSorting(algorithm1, arrCopy1, comparisons1);
                end1 = high_resolution_clock::now();

                start2 = high_resolution_clock::now();
                startSorting(algorithm1, arrCopy2, comparisons2);
                end2 = high_resolution_clock::now();
                
                time1 = duration_cast<milliseconds>(end1 - start1).count();
                time2 = duration_cast<milliseconds>(end2 - start2).count();

                printOutputComparison(order1, time1, time2, comparisons1, comparisons2);
            }

            else 
            {
                cerr << "Invalid Input Order!";
                return 1;
            }
        }

        else
        {
            cerr << "\nUsage: <execution file> -c <algorithm1> <algorithm2> <input file(.txt)/input size> [input order]" << endl;
            return 1;
        }
    }

    else 
        cerr << "Invalid Mode!";
    return 0;
}
