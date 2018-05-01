#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;


lld calc(vi input){


  lld maxm = 0;
  for(int i = 0;i<14;i++){
    lld sum = 0;
    vi process= input;
    lld div = input[i]/14;
    lld mod = input[i]%14;
       
    process[i] = 0;
    for(int j = 1;j<=14;j++)
      process[(i+j)%14] += div;
         
    for(int j = 1;j<=mod;j++)
      process[(i+j)%14] += 1; 
    
    for(int j = 0;j<14;j++)
      if(process[j]%2==0)
        sum+= process[j];
    maxm = max(maxm,sum);
//    cout<<maxm<<" "<<i<<endl;
  }
  return  maxm;

}

int main(){
  
  faster
  vi input(14);
  for(int i =0;i<14;i++)
    cin>>input[i];
  
  cout<<calc(input)<<endl;
}
