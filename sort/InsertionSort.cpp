#include <iostream>
using namespace std;

template <class T>
void InsertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{

    int arr[] = {5, 132, 1, 24, 12, 31};
    string arr2[] = {"sidar", "mert", "kemal", "celal"};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (auto i : arr)
        cout << i << " ";

    cout << endl;
    InsertionSort(arr, n);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}