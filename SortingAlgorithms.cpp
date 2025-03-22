#include "SortingAlgorithms.h"

// Selection Sort
void selectionSort(vector<int>& arr, unsigned long long& comparisons)
{
    int size = arr.size();

    for (int i = 0; (++comparisons) && (i < size - 1); i++) 
    {
        int minIdx = i;

        for (int j = i + 1; (++comparisons) && (j < size); j++) 
        {
            if ((++comparisons) && (arr[j] < arr[minIdx])) 
            {
                minIdx = j;
            }   
        }
        swap(arr[i], arr[minIdx]);
    }
}


// Insertion Sort
void insertionSort(vector<int>& arr, unsigned long long& comparisons) 
{
    int size = arr.size();

    for (int i = 1; (++comparisons) && (i < size); i++) 
    {
        int key = arr[i];
        int j = i - 1;

        while ((++comparisons && j >= 0) && (++comparisons && arr[j] > key)) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


// Shell Sort
void shellSort(vector<int>& arr, unsigned long long& comparisons) 
{
    int size = arr.size();

    for (int gap = size / 2; (++comparisons) && (gap > 0); gap /= 2) 
    {
        for (int i = gap; (++comparisons) && (i < size); i++) 
        {
            int temp = arr[i];

            int j;
            for (j = i; (++comparisons) && (j >= gap) && (++comparisons) && (arr[j - gap] > temp); j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


// Bubble Sort
void bubbleSort(vector<int>& arr, unsigned long long& comparisons) 
{
    int size = arr.size();

    for (int i = 0; (++comparisons) && (i < size - 1); i++) 
    {
        for (int j = 0; (++comparisons) && (j < size - i - 1); j++) 
        {
            if ((++comparisons) && (arr[j] > arr[j + 1])) 
                swap(arr[j], arr[j + 1]);
        }
    }
}


// Heap Sort
void heapify(vector<int>& arr, int n, int i, unsigned long long& comparisons) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((++comparisons) && (left < n) && (++comparisons) &&  (arr[left] > arr[largest])) 
        largest = left;
    if ((++comparisons) && (right < n) && (++comparisons) && (arr[right] > arr[largest])) 
        largest = right;
    if ((++comparisons) && (largest != i)) 
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest, comparisons);
    }
}

void heapSort(vector<int>& arr, unsigned long long& comparisons)
{
    int size = arr.size();

    for (int i = size / 2 - 1; (++comparisons) && (i >= 0); i--) 
        heapify(arr, size, i, comparisons);
    
    for (int i = size - 1; (i > 0); i--) 
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0, comparisons);
    }
}


// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right, unsigned long long& comparisons) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; (++comparisons) && (i < n1); i++) 
        L[i] = arr[left + i];
    for (int j = 0; (++comparisons) && (j < n2); j++) 
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;

    while ((++comparisons) && (i < n1) && (++comparisons) && (j < n2)) 
    {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while ((++comparisons) && (i < n1)) 
        arr[k++] = L[i++];
    while ((++comparisons) && (j < n2)) 
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right, unsigned long long& comparisons) 
{
    if ((++comparisons) && (left < right)) 
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}


// Quick Sort
int medianOfThree(vector<int>& arr, int low, int high, unsigned long long& comparisons) 
{
    int mid = low + (high - low) / 2;

    if ((++comparisons) && (arr[low] > arr[mid])) 
        swap(arr[low], arr[mid]);
    if ((++comparisons) && (arr[low] > arr[high])) 
        swap(arr[low], arr[high]);
    if ((++comparisons) && (arr[mid] > arr[high])) 
        swap(arr[mid], arr[high]);

    return mid;
}

int partition(vector<int>& arr, int low, int high, unsigned long long& comparisons) 
{
    int pivotIndex = medianOfThree(arr, low, high, comparisons);
    swap(arr[pivotIndex], arr[high]); 
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; (++comparisons) && (j < high); j++) 
    {
        if ((++comparisons) && (arr[j] < pivot))
            swap(arr[++i], arr[j]);
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, unsigned long long& comparisons) 
{
    while ((++comparisons) && (low < high)) 
    {
        int pivot = partition(arr, low, high, comparisons);

        if ((++comparisons) && (pivot - low < high - pivot)) 
        {
            quickSort(arr, low, pivot - 1, comparisons);
            low = pivot + 1; 
        } 
        else 
        {
            quickSort(arr, pivot + 1, high, comparisons);
            high = pivot - 1;
        }
    }
}


// Radix Sort
void countingSortForRadix(vector<int>& arr, int exp, unsigned long long& comparisons) 
{
    int size = arr.size();
    vector<int> output(size);
    int count[10] = {0};

    for (int i = 0; (++comparisons) && i < size; i++) 
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; (++comparisons) && i < 10; i++) 
        count[i] += count[i - 1];

    for (int i = size - 1; (++comparisons) && i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; (++comparisons) && i < size; i++) arr[i] = output[i];
}

void radixSort(vector<int>& arr, unsigned long long& comparisons) {
    if ((++comparisons) && arr.empty()) 
        return;

    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; (++comparisons) && maxVal / exp > 0; exp *= 10) 
    {
        countingSortForRadix(arr, exp, comparisons);
    }
}

// Counting Sort
void countingSort(vector<int>& arr, unsigned long long& comparisons) 
{
    int size = arr.size();

    if (size == 0) 
        return;

    int maxElement = *max_element(arr.begin(), arr.end());

    vector<int> countArray(maxElement + 1, 0);

    for (auto i = arr.begin(); (++comparisons) && (i != arr.end()); ++i)
        countArray[*i]++;

    for (int i = 1; (++comparisons) && (i <= maxElement); i++)
        countArray[i] += countArray[i - 1];

    vector<int> outputArray(size);

    for (int i = size - 1; (++comparisons) && (i >= 0); i--) 
    {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }

    arr = outputArray;
}


//---------------BONUS EXPLORATIONS---------------
// Binary Insertion Sort
void binaryInsertionSort(vector<int>& arr, unsigned long long& comparisons) 
{
    int size = arr.size();

    for (int i = 1; (++comparisons) && i < size; i++) 
    {
        int key = arr[i];
        int left = 0, right = i - 1;

        while ((++comparisons) && left <= right) 
        {
            int mid = left + (right - left) / 2;

            if ((++comparisons) && arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        for (int j = i - 1; (++comparisons) && j >= left; j--) 
        {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}


// Shaker Sort
void shakerSort(vector<int>& arr, unsigned long long& comparisons) 
{
    int left = 0, right = arr.size() - 1;
    bool swapped;

    do 
    {
        swapped = false;

        for (int i = left; (++comparisons) && i < right; i++) 
        {
            if ((++comparisons) && arr[i] > arr[i + 1]) 
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        right--;
        for (int i = right; (++comparisons) && i > left; i--) 
        {
            if ((++comparisons) && arr[i] < arr[i - 1]) 
            {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++;
    } 
    while ((++comparisons) && swapped);
}


// Flash Sort
void flashSort(vector<int>& arr, unsigned long long& comparisons) 
{
    int size = arr.size();

    if ((++comparisons) && size <= 1) 
        return;

    int minVal = arr[0], maxIdx = 0;

    for (int i = 1; (++comparisons) && i < size; i++) 
    {
        if ((++comparisons) && arr[i] < minVal) 
            minVal = arr[i];

        if ((++comparisons) && arr[i] > arr[maxIdx]) 
            maxIdx = i;
    }

    if ((++comparisons) && minVal == arr[maxIdx]) 
        return;

    int m = int(0.45 * size);
    vector<int> L(m, 0);
    double c1 = (double)(m - 1) / (arr[maxIdx] - minVal);

    for (int i = 0; (++comparisons) && i < size; i++) 
    {
        int k = int(c1 * (arr[i] - minVal));
        L[k]++;
    }

    for (int i = 1; i < m; i++) 
    {
        L[i] += L[i - 1];
    }

    int count = 0, i = 0, k = m - 1, hold;

    while ((++comparisons) && count < size - 1) 
    {
        while ((++comparisons) && i > L[k] - 1) 
        {
            i++;
            k = int(c1 * (arr[i] - minVal));
        }
        hold = arr[i];
        while ((++comparisons) && i != L[k]) 
        {
            k = int(c1 * (hold - minVal));
            swap(hold, arr[L[k] - 1]);
            L[k]--;
            count++;
        }
    }
    insertionSort(arr, comparisons);
}
