#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std::chrono;
using namespace std;

void Merge(vector<int> &arr, int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    vector<int> L(n1), R(n2);
    copy_n(arr.begin() + l, n1, L.begin());
    copy_n(arr.begin() + m + 1, n2, R.begin());

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int> &arr, int l, int h)
{
    if (l >= h)
        return;

    int mid = l + ((h - l) >> 1);
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, h);
    Merge(arr, l, mid, h);
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

    MergeSort(arr, 0, n - 1);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Duration to complete in microseconds " << duration.count() << endl;

    cout << "Sorted Array is: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}