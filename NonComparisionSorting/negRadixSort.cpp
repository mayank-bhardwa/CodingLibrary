#include <iostream>
#include <vector>
#include <math.h>
#define deb(x) cout << #x << " " << x << endl
using namespace std;

int AbsMax(vector<int> arr)
{
    int mx = 0;
    for (auto i : arr)
    {
        if (abs(i) > mx)
            mx = abs(i);
    }

    return mx;
}

void CountingSort(vector<int> &arr, int k)
{
    vector<int> temp(arr.size(), 0);
    vector<int> freq(19, 0);
    int ele, t;

    int mod = pow(10, k);
    int modPre = mod / 10;

    for (int i = 0; i < arr.size(); i++)
    {
        t = (arr[i] % mod) / modPre;
        if (i < 0)
        {
            t *= -1;
        }
        ele = t + 9;
        freq[ele]++;
    }

    for (int i = 1; i < 19; i++)
    {
        freq[i] += freq[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        t = (arr[i] % mod) / modPre;
        if (i < 0)
        {
            t *= -1;
        }
        ele = t + 9;

        temp[freq[ele] - 1] = arr[i];
        freq[ele]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = temp[i];
}

void RadixSort(vector<int> &arr)
{
    int len = AbsMax(arr);

    for (int i = 1; len > 0; i++, len /= 10)
        CountingSort(arr, i);
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
            arr[i] = rand() % 1000;
        else
            arr[i] = -1 * (rand() % 1000);
    }

    cout << "Array before Sorting is: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    RadixSort(arr);

    cout << "Sorted Array is: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}