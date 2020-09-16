#include <iostream>
#include <numeric>   //for accumulate(),adjacent_difference
#include <algorithm>  //copy(),binary_search()
#include <vector>
using namespace std;

template<typename T>
void print(T a)
{
    for(auto i : a)cout<<i<<" ";
    cout<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int arr[] = {1,3,4,5,46};
    vector<int> result(5);

    adjacent_difference(arr,arr+5,result.begin());
    print(result);

    adjacent_difference(arr,arr+5,result.begin(),[](auto a,auto b){return a+b;});
    print(result);

    cout << accumulate(arr,arr+5,1,[](auto a,auto b){return a*b;}) <<"\n"; 

    auto i = adjacent_find(arr,arr+5); //overloaded ,[](auto a,auto b){return (b-a)==1;});

    cout<<*i<<endl;

    cout << binary_search(arr,arr+5,4)<<endl;

    vector<int> cpy(8);
    copy(arr,arr+5,cpy.begin());
    print(cpy);

    copy_backward(arr,arr+5,cpy.end());
    print(cpy);
    
    //similar copy_n to copy first n elements

    cout<<count_if(cpy.begin(),cpy.end(),[](auto a){return a==3;});
    return 0;    
}