#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void min_heapify(vector<int> &arr,int idx)
{
    if(idx==0) return;
    int parent = (idx-1)/2;
    if(arr[idx] < arr[parent]) swap(arr[idx],arr[parent]);
    min_heapify(arr,parent);
}

void build_heap(vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        min_heapify(arr,i);
    }
}

void pop_min_heapify(vector<int> &arr,int idx)
{
    if(idx>=arr.size())return ;

    int l1 =2*idx + 1;
    int l2 =2*idx + 2;
    int smallest = idx;
    if(l1 < arr.size() and arr[l1] < arr[smallest]) smallest = l1;
    if(l2 < arr.size() and arr[l2] < arr[smallest]) smallest = l2;

    if(smallest!=idx)
    {
        swap(arr[idx],arr[smallest]);
        pop_min_heapify(arr,smallest);
    }
}

int pop_min(vector<int> &arr)
{
    int x = arr[0];
    swap(arr[0],arr[arr.size()-1]);
    arr.pop_back();
    pop_min_heapify(arr,0);
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n=10;
    vector<int> arr(n),arr2(n);

    for(int i=0;i<n;i++)
    {
        arr[i] = rand() % 32 + 1;
        arr2[i] = arr[i];
    } 
    build_heap(arr);
    for(auto i:arr)cout<<i<<" ";
    cout<<endl;
    cout<<pop_min(arr)<<endl;
    for(auto i:arr)cout<<i<<" ";

    cout<<endl;

    /*
        Below is the stl implementation of min heap 
        for max heap remove greater
    */
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto i : arr2) pq.push(i);
    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}
