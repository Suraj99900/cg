/*
Name: Suraj Jaiswal

Roll No. : 69

Lab-5

*/

#include <iostream>
#include <functional>
using namespace std;

template <typename T, typename Compare>
void selectionSort(T arr[], int n, Compare comp) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (comp(arr[j], arr[min_idx]))
                min_idx = j;
        }

        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void input(T arr[], int size) {
    cout << "Enter values: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    while (true) {
        int n;
        cout << "Enter number of elements you want: " << endl;
        cin >> n;

        float *floatArray = new float[n];
        input(floatArray, n);

        selectionSort(floatArray, n, less<float>());
        printArray(floatArray, n);

        delete[] floatArray;
    }

    return 0;
}
