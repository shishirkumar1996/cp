#include<bits/stdc++.h>
#define vi vector< int >
#define NUM 100007

using namespace std;

vi wt, val;
int n;

int max(int a,int b){return (a>b)?a:b;}

int knapsack(int w){

  int k[n+1][w+1];
  for(int i=0;i<=n;i++){
    for(int j= 0;j<=w;j++){
      if(i==0||j==0) k[i][j] = 0;
      else if(wt[i-1]<=j) k[i][j] = max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
      else k[i][j] = k[i-1][j];
    }
  }
  return k[n][w];
}


int main(){

  int v[] = {60,100,120};
  int x[] = {10,20,30};
  int w=50;
  n = 3;
  for(int i=0;i<n;i++){val.push_back(v[i]);wt.push_back(x[i]);}
  cout<<knapsack(w)<<endl;
}
