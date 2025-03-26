#include <iostream>
using namespace std;

template <class T>
void RecursiveInsertionSort(T arr[], int n)
{
    if (n <= 1)
        return;

    RecursiveInsertionSort(arr, n - 1);

    T last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{
    int arr[] = {5, 132, 1, 24, 12, 31};
    string arr2[] = {"sidar", "mert", "kemal", "celal"};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (auto i : arr)
        cout << i << " ";

    cout << endl;
    RecursiveInsertionSort(arr, n);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}