#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

template <typename t>
void countingSort(vector<t> &arr, int k)
{
    int mod = pow(10, k);
    int freq[10] = {0};

    for (auto i : arr)
    {
        freq[(i % mod) / (mod / 10)]++;
    }

    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }

    vector<t> res(arr.size());
    int z;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        z = (arr[i] % mod) / (mod / 10);
        res[freq[z] - 1] = arr[i];
        freq[z]--;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = res[i];
    }
}

int main()
{
    vector<int> arr(10);
    for (int i = 0; i < 10; i++)
        arr[i] = rand();
    countingSort(arr, 3);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}