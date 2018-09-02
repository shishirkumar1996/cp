#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  string a,b;
  cin>>n>>a>>b;

  int ans = 0;
  for(int i=0;i<n-1;i++){
    if(a[i]!=b[i]){
      if(a[i+1] != b[i+1] && a[i] != a[i+1]){ ans++; swap(a[i],a[i+1]); }
      else {a[i] = '0'+('1'-a[i]);ans++; }
    }
  }
  if(a[n-1] != b[n-1]) ans++;
  cout<<ans<<endl;
}
