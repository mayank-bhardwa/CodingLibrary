#include<iostream>
#include<vector>
using namespace std;


int count(vector<int> arr,int n)
{
    int k,res=0;
    for(int i=0;i<n;i++)
    {   
        k=arr[i];
        for(int j=i;j<n;j++)
        {
            if (k<=arr[j])
            {
                res++;
                k=arr[j];
            }
            else
            {
                break;
            }
            
            
        }
    }
    return res;
}

int main()
{
    int t,n;
    vector<int> arr;
    cin>>t;
    while(t--)
    {
        cin>>n;
        arr.resize(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<count(arr,arr.size())<<endl;
    }
    return 0;
}