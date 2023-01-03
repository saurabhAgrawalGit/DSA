#include <iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
    int left, right, pivot_item, temp;
    left = low;
    right = high;
    pivot_item = arr[low];
    while (left < right)
    {
        while (arr[left] <= pivot_item)
            left++;

        while (arr[right] > pivot_item)
            right--;

        if (left < right)
        {
            temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    arr[low] = arr[right];
    arr[right] = pivot_item;
    return right;
}
void quickSort(int arr[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{

    int arr[10] = {2, 4, 1, 6, 9, 7, 44, 9, 14, 88};
    int n = 10;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
