/*
Rod cutting problem recursive solution this is similar to the unboundedknapsack problem
in this problem we have cost of rod for corresponding rod size we have big rod of given 
length we have to cut in smaller pieces so that we could make max money
*/
#include<iostream>
using namespace std;

int cutrod(int Rsize[],int Rcost[],int Tlength,int n){
if(Tlength==0 || n==0){
   return 0;
}

if(Rsize[n-1]>Tlength){
   return cutrod(Rsize,Rcost,Tlength,n-1);
}else
{
   return max(cutrod(Rsize,Rcost,Tlength-Rsize[n-1],n)+Rcost[n-1],cutrod(Rsize,Rcost,Tlength,n-1));
}

}

int main()
{
   int Rsize[]={5,6,8};
   int Rcost[]={10,5,6};
   int n=sizeof(Rsize)/sizeof(Rsize[0]);
   int Tlength=50;
   cout<<cutrod(Rsize,Rcost,Tlength,n);
   return 0;
}