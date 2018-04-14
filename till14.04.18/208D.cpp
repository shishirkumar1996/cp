#include<bits/stdc++.h>
#define lld long long int

using namespace std;


void calc(int n,lld bars[],lld prices[]){

  lld num[5] = {0,0,0,0,0};
  
  lld counter = 0;
  for(int i =0;i<n;i++){
    counter += bars[i];
    while(counter >= prices[0]){
      for(int j =4;j>=0;j--)
        if(counter >= prices[j]){
          lld mul = counter/prices[j];
          num[j] += mul;
          counter -= mul*prices[j];
        }
    }
  }
  for(int i =0;i<5;i++)
    cout<<num[i]<<" ";
  cout<<endl;
  
  cout<<counter<<endl;

}

int main(){

  ios::sync_with_stdio(false);  
  int n;
  cin>>n;
  lld bars[n];
  lld prices[5];
  for(int i = 0;i<n;i++)
    cin>>bars[i];
    
  for(int i =0;i<5;i++)
    cin>>prices[i];
  
  calc(n,bars,prices);
}
