#include <iostream>
#include <ctime>
using namespace std;

template <class T>
void BubbleSort(T arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main()
{

    clock_t start = clock();
    int arr[] = {5, 132, 1, 24, 12, 31};
    string arr2[] = {"sidar", "mert", "kemal", "celal"};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (auto i : arr)
        cout << i << " ";

    cout << endl;
    BubbleSort(arr, n);

    for (auto i : arr)
        cout
            << i << " ";
    cout << endl;

    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;
    cout << "gecen sure:\t" << time << endl;

    return 0;
}