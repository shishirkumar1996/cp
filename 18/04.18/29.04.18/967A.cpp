#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false); cin.tie(0);
#define pr pair< int, int >
#define vi vector< int >

using namespace std;


int calc(int n,int s,vi input){

  if(input[0] >= s+1)
    return 0;
    
  for(int i = 0;i<n-1;i++)
    if(input[i+1]-input[i]>= 2*s+2)
      return input[i]+1+s;  
  
  return input[n-1]+1+s;

}

int main(){

  int n,s;
  cin>>n>>s;
  vi input(n);
  for(int i = 0;i<n;i++){
    int a,b;
    cin>>a>>b;
    input[i] = a*60+b;
  }
  
  int ans = calc(n,s,input);
  cout<<ans/60<<" "<<ans%60<<endl;
}
