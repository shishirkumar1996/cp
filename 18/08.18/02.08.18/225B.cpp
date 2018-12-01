#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define NUM (lld)(1e9+7)

using namespace std;

int main(){

  lld s,k;
  cin>>s>>k;
  
  vi process;
  process.push_back(1);
  lld sum = 1;
  while(sum < NUM){
    process.push_back(sum);
    if((lld)process.size()-1-k>=0) sum -= process[process.size()-1-k];
    sum += process[process.size()-1];
  }

  vi output;
  while(s){
    int index = lower_bound(process.begin(),process.end(),s)-process.begin();
    if(process[index]!=s) index--;
    
    output.push_back(process[index]);
    s=s-process[index];
  }
  output.push_back(0);
  cout<<output.size()<<endl;
  for(int i=0;i<output.size();i++)cout<<output[i]<<" ";
  cout<<endl;
}
