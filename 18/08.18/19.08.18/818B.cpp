#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  faster
  int n,m;
  cin>>n>>m;
  
  vi output(n+1,0),input(m+1);
  for(int i=1;i<=m;i++)cin>>input[i];
  
  map< int,int > process;
  for(int i=2;i<=m;i++){
    int x = input[i]-input[i-1];
    if(x<=0)x += n;
    if(output[input[i-1]] && output[input[i-1]] != x){ cout<<-1<<endl;return 0; }
    if(!output[input[i-1]]){
      output[input[i-1]]=x;
      process[x]++;
    }
  }
  int index = 1;
  for(int i=1;i<=n;i++){ 
    if(output[i] && process[output[i]]>1){cout<<-1<<endl;return 0;}
    if(!output[i]){
      while(process[index])index++;
      output[i] = index;
      process[index]++;
    }
  }
  for(int i=1;i<=n;i++)cout<<output[i]<<" ";
  cout<<endl;
}
