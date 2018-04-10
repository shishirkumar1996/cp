#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >

using namespace std;


int calc(int n,vi input,lld sum){

  lld half = 0;
  for(int i = 0;i<n;i++)
  {
    half += input[i];
    if(half >= (sum+1)/2)
      return i+1;
  }

}


int main(){
  
  int n;
  cin>>n;
  vi input;
  lld sum = 0;
  for(int i = 0;i<n;i++){
    int num;
    cin>>num;
    sum += num;
    input.push_back(num);
  }
  
  cout<<calc(n,input,sum)<<endl;

}
