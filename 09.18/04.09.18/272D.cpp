#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  int n;
  cin>>n;
  
  int same=0;
  lld x[n+1];
  map< lld,int > process;
  for(int i=1;i<=n;i++){
    cin>>x[i];
    process[x[i]]++;
  }
  for(int i=1;i<=n;i++){
    lld a;
    cin>>a;
    process[a]++;
    if(x[i]==a)same++;
  }
  lld m;
  cin>>m;

  lld ans = 1;
  map< lld,int >::iterator it;
  for(it = process.begin();it !=process.end();it++)
    for(int i=2;i<=it->second;i++){
      int temp = i;
      while(same && temp%2==0){temp = temp/2;same--;}
      ans = (ans*temp)%m;
    }
  cout<<ans<<endl;
}
