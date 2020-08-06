#include <iostream>
using namespace std;

void quickSort(int arr[], int len)
{
    if (len <= 1)
        return;
    int low = 0, high = len - 1;
    int key = 0;
    while (low < high)
    {
        while (high > low)
        {
            if (arr[key] > arr[high])
            {
                swap(arr[key], arr[high]);
                key = high;
                break;
            }
            high--;
        }
        while (low < high)
        {
            if (arr[key] < arr[low])
            {
                swap(arr[key], arr[low]);
                key = low;
                break;
            }
            low++;
        }
    }
    quickSort(arr, key);
    quickSort(arr + key + 1, len - key - 1);
}

int main()
{
    int arr[8] = {1, 8, 5, 9, 7, 4, 2, 6};
    quickSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << '\t';
    }
    return 0;
}