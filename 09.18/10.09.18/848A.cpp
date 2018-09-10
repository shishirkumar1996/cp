#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int k;
  cin>>k;
  
  string ans = "";
  int index = 0;
  while(k){
    int n = 2;
    while((n*(n+1))/2<=k)n++;
    for(int i=0;i<n;i++) ans += ('a'+index);
    index++;
    k -= (n*(n-1))/2;
  }
  if(ans.size()==0) ans += 'a';
  cout<<ans<<endl;
}
