#include <iostream>
using namespace std;

template <class T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

template <class T>
void swap(T &lhn, T &rhn)
{
    T temp = lhn;
    lhn = rhn;
    rhn = temp;
}

int main()
{
    string stringArr[] = {"sidar", "celal", "kemal", "mert"};
    int intArr[] = {23, 14, 12, 5, 54, 16, 1, 35};
    int strArrN = sizeof(stringArr) / sizeof(stringArr[0]);
    int intArrN = sizeof(intArr) / sizeof(intArr[0]);

    for (string i : stringArr)
    {
        cout << i << " ";
    }
    cout << endl;
    selectionSort(stringArr, strArrN);
    for (string i : stringArr)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : intArr)
    {
        cout << i << " ";
    }
    cout << endl;
    selectionSort(intArr, intArrN);
    for (int i : intArr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}