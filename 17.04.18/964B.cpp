#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);

#define lld long long int
#define vi vector< lld >


using namespace std;


lld calc(int n,int a,int b,int c,int t,vi input){

    
  lld sum = 0;
  for(int i = 0;i<input.size();i++){
    
    lld maxm = -1;
    for(int j = input[i];j<=t;j++){
      lld val = c*(j-input[i]) + (a-(j-input[i])*b);
      maxm = max(val,maxm);
    }
    sum += maxm;
  
  }  
  return sum;

}

int main(){
  
  int n,a,b,c,t;
  cin>>n>>a>>b>>c>>t;
  vi input(n);
  for(int i = 0;i<n;i++)
    cin>>input[i];
    
  cout<<calc(n,a,b,c,t,input)<<endl;

}

