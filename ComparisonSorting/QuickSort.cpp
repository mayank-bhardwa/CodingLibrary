#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

int Partition(vector<int> &arr, int l, int h)
{
    int pivot = arr[h];
    int pi = l - 1;

    for (int i = l; i < h; i++)
    {
        if (arr[i] < pivot)
        {
            pi++;
            swap(arr[i], arr[pi]);
        }
    }
    swap(arr[pi + 1], arr[h]);
    return pi + 1;
}

void QuickSort(vector<int> &arr, int l, int h)
{
    if (l >= h)
        return;

    int pivot = Partition(arr, l, h);
    QuickSort(arr, l, pivot - 1);
    QuickSort(arr, pivot + 1, h);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    int i;
    for (i = 0; i < n; i++)
    {
        if (i & 1)
            arr[i] = rand();
        else
            arr[i] = -1 * rand();
    }

    cout << "Array before Sorting is: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    auto start = high_resolution_clock::now();

    QuickSort(arr, 0, n - 1);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Duration to complete in microseconds " << duration.count() << endl;

    cout << "Sorted Array is: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}