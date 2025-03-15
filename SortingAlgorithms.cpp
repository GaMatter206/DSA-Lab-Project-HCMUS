#include "SortingAlgorithms.h"

// Selection Sort
void selectionSort(vector<int>& arr, long long& comparisons) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr, long long& comparisons) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Shell Sort
void shellSort(vector<int>& arr, long long& comparisons) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Bubble Sort
void bubbleSort(vector<int>& arr, long long& comparisons) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i, long long& comparisons) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    comparisons += 2;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, comparisons);
    }
}
void heapSort(vector<int>& arr, long long& comparisons) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, comparisons);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right, long long& comparisons) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(vector<int>& arr, int left, int right, long long& comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high, long long& comparisons) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high, long long& comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}

// Radix Sort
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}
void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

// Counting Sort
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    for (int num : arr) count[num]++;
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) arr[index++] = i;
    }
}

//---------------BONUS EXPLORATIONS---------------
// Binary Insertion Sort
void binaryInsertionSort(vector<int>& arr, long long& comparisons) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            comparisons++;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

// Shaker Sort
void shakerSort(vector<int>& arr, long long& comparisons) {
    int left = 0, right = arr.size() - 1;
    bool swapped;
    do {
        swapped = false;
        for (int i = left; i < right; i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            comparisons++;
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++;
    } while (swapped);
}


// Flash Sort
void flashSort(vector<int>& arr, long long& comparisons) {
    int n = arr.size();
    if (n <= 1) return;
    int minVal = arr[0], maxIdx = 0;
    for (int i = 1; i < n; i++) {
        comparisons++;
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }
    if (minVal == arr[maxIdx]) return;
    int m = int(0.45 * n);
    vector<int> L(m, 0);
    double c1 = (double)(m - 1) / (arr[maxIdx] - minVal);
    for (int i = 0; i < n; i++) {
        int k = int(c1 * (arr[i] - minVal));
        L[k]++;
    }
    for (int i = 1; i < m; i++) {
        L[i] += L[i - 1];
    }
    int count = 0, i = 0, k = m - 1, hold;
    while (count < n - 1) {
        while (i > L[k] - 1) {
            i++;
            k = int(c1 * (arr[i] - minVal));
        }
        hold = arr[i];
        while (i != L[k]) {
            k = int(c1 * (hold - minVal));
            swap(hold, arr[L[k] - 1]);
            L[k]--;
            count++;
        }
    }
    insertionSort(arr, comparisons);
}
