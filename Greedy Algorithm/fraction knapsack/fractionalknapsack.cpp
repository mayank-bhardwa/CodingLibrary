/*
Fractional knapsack problem using greedy approach
funtion cmp returns true if a>b for making comparision
in pre defined sort function
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct item{
    int wt,val;

    item(int weight,int value){           //constructor
        wt=weight;
        val=value;
    }
};

bool cmp(item a,item b){
    double t1=(double)a.val/a.wt;
    double t2=(double)b.val/b.wt;
    return t1>t2;
}

double maxValue(item itms[],int n,int W)
{
    sort(itms,itms+n,cmp);

    int curWt=0;
    double value=0.0;
    for(int i=0;i<n;i++){
        if(itms[i].wt+curWt<=W){
            value+=itms[i].val;
            curWt+=itms[i].wt;
        }
        else{
            value+=((double)(W-curWt)/itms[i].wt)*itms[i].val;
            break;
        }
    }
    return value;
}

int main()
{
    item itms[]={{10, 60}, {20, 100}, {30, 120}};
    int n=sizeof(itms)/sizeof(item);
    int W=50;
    cout<<maxValue(itms,n,W);
    return 0;
}