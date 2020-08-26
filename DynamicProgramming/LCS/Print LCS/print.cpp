/*

*/
#include<bits/stdc++.h>
using namespace std;

string print(char *s1,char *s2)
{
    int n1=sizeof(s1)/sizeof(s1[0]);
    int n2=sizeof(s2)/sizeof(s2[0]);
    int t[n1+1][n2+1];
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                    t[i][j]=t[i-1][j-1]+1;
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }



    string res="";
    int j=n2,i=n1;
    while(j>0 && i>0){
        if(s1[i-1]==s2[j-1]){
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j]<t[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    char *s1="goodpersonhello";
    char *s2="goodhello";
    cout<<print(s1,s2);
    return 0;
}