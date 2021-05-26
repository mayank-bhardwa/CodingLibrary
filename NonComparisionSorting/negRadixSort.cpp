/*
    Counting Sort with handling of negative numbers
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
using namespace std;

template <typename t>
t MaxD(vector<t> arr)
{
    int d = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (d < abs(arr[i]))
            d = arr[i];
    }
    return d;
}

template <typename t>
void CountingSort(vector<t> &arr, int k)
{
    int mod = pow(10, k);
    int freq[10] = {0};

    for (auto i : arr)
    {
        freq[(abs(i) % mod) / (mod / 10)]++;
    }

    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }

    vector<t> res(arr.size());
    int z;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        z = (abs(arr[i]) % mod) / (mod / 10);
        res[freq[z] - 1] = arr[i];
        freq[z]--;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = res[i];
    }
}

template <typename t>
void RadixSort(vector<t> &arr)
{
    int maxD = MaxD(arr);

    for (int i = 1; maxD != 0; i++, maxD /= 10)
    {
        CountingSort(arr, i);
    }

    int temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            temp = arr[i];
            arr.erase(arr.begin() + i);
            arr.insert(arr.begin(), temp);
        }
    }
}

int main()
{
    vector<int> arr(100000);
    int i;
    for (i = 0; i < 5000; i++)
    {
        arr[i] = (rand() >> 1) * -1;
    }

    for (; i < 100000; i++)
    {
        arr[i] = rand() >> 1;
    }

    auto start = chrono::high_resolution_clock::now();

    RadixSort(arr);

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time elapsed in execution " << duration << " milisec";

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}