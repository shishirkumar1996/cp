#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int n,k;
  cin>>n>>k;
  
  if(n<3*k){cout<<-1<<endl;return 0;}
  vi output(n+1);
  
  int num = n-3*k;
  for(int i=n;i>n-num;i--){
    output[i] = 1;
  }
  
  int index = k+1;
  for(int i=1;i<=k;i++){
    output[i] = i;output[index++] = i;output[index++] = i;
  }
  for(int i=1;i<=n;i++)cout<<output[i]<<" ";
  cout<<endl;
}
