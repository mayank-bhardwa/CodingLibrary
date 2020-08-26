/*
    CPP program to get the maximum element 
    which is less or equal to X in sorted
    array arr using binary search in log(n)
    time complexity
*/
#include<iostream>
using namespace std;

template<typename T>
int array_floor(T arr,int low,int high,int x)
{
    if(low > high) return -1;

    if(x>=arr[high]) return high;

    int mid = (low + high)/2;
    if(x==arr[mid])
    {
        return mid;
    }
    if(mid>0 && x < arr[mid] && x >= arr[mid-1])return mid-1;

    if(x>arr[mid])
    {
        return array_floor(arr,mid+1,high,x);
    }

    return array_floor(arr,low,mid-1,x);
}

int main()
{
    int arr[]={1, 2, 8, 10, 10, 12, 19};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x;
    cin>>x;
    cout<<"Floor of "<<x<<" is "<<array_floor(arr,0,n-1,x);
    return 0;
}