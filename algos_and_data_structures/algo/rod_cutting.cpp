#include<bits/stdc++.h>
#define vi vector< int >
#define NUM 100007

using namespace std;

vi price(NUM);
int n;

int max(int a,int b){return (a>b)?a:b;}

int cutRod(){

  int val[n+1];
  val[0] = 0;
  
  for(int i=1;i<=n;i++){
    int max_val = INT_MIN;
    for(int j=0;j<i;j++) max_val = max(max_val,price[j] +val[i-j-1]);
    val[i] = max_val;
  }  
  return val[n];
}

int main(){
  
  int arr[] = {1,5,8,9,10,17,17,20};
  n =  8;
  for(int i=0;i<n;i++) price[i] = arr[i];
  cout<<cutRod()<<endl;
}
