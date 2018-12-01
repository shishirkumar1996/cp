#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;


int main(){

  faster
  int n,k;
  cin>>n>>k;
  vi input(n+1);
  for(int i = 1;i<=n;i++) cin>>input[i];
  
  vi process(n+1);
  process[0] = 0;
  for(int i = 1;i<=n;i++) 
    process[i] = process[i-1]+((input[i]==0)?1:0);
  
  int max = 0,max_right=-1,max_left=-1;
  
  for(int i=  1;i<=n;i++){
    int index = upper_bound(process.begin(),process.end(),process[i-1]+k)-process.begin()-1;
    int length = index-i+1;
    if(length>max){ max=length,max_left = i,max_right = index; }
  }
  
  cout<<max<<endl;
  for(int i= 1;i<=n;i++)
  if(i>=max_left && i<=max_right) cout<<1<<" "; else cout<<input[i]<<" ";
  cout<<endl;

}
