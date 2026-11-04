
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Partition function
int partition(vector<int>& a, int low, int high, long long& count) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        count++;

        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Deterministic Quick Sort
void quickSort(vector<int>& a, int low, int high, long long& count) {
    if (low < high) {
        int p = partition(a, low, high, count);

        quickSort(a, low, p - 1, count);
        quickSort(a, p + 1, high, count);
    }
}

// Randomized Quick Sort
void randomQuickSort(vector<int>& a, int low, int high, long long& count) {
    if (low < high) {
        int r = low + rand() % (high - low + 1);

        swap(a[r], a[high]);

        int p = partition(a, low, high, count);

        randomQuickSort(a, low, p - 1, count);
        randomQuickSort(a, p + 1, high, count);
    }
}

// Display function
void display(vector<int>& a) {
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size";
        return 0;
    }

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b = a;

    long long count1 = 0, count2 = 0;

    quickSort(a, 0, n - 1, count1);
    randomQuickSort(b, 0, n - 1, count2);

    cout << "\nDeterministic Quick Sort: ";
    display(a);
    cout << "Comparisons: " << count1 << endl;

    cout << "\nRandomized Quick Sort: ";
    display(b);
    cout << "Comparisons: " << count2 << endl;

    return 0;
}
