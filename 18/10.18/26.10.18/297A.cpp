#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  string a,b;
  cin>>a>>b;
  
  int x=0,y=0;
  for(int i=0;i<a.length();i++)if(a[i]=='1')x++;
  for(int i=0;i<b.length();i++) if(b[i]=='1')y++;
  x = x+(x%2);
  if(x>=y)cout<<"YES\n"; else cout<<"NO\n";
}
