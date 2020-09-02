/*
    Heap implementation using stl
*/
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> ipair;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif                                            // for max heap priority_queue<int>
    priority_queue<int,vector<int>,greater<int>> a;  //for min heap
    a.push(10);
    a.push(7);
    a.push(15);
    a.push(65);
    while (!a.empty())
    {
        cout<<a.top()<<" ";
        a.pop();
    }
    cout<<endl;
    priority_queue<ipair, vector<ipair> , greater<ipair> > b;        //by default according to second element of pair
    b.push({2,5});
    b.push({3,8});
    b.push({4,15});
    b.push({3,10});
    b.push({4,20});
    while (!b.empty())
    {
        cout<<b.top().first<<" "<<b.top().second<<endl;
        b.pop();
    }
    
    return 0;
}