#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;


int main(){

  int n;
  string a,b;
  cin>>n>>a>>b;
  
  lld ans = 0;
  for(int i=0;i<n/2;i++){
    
    map<char, int > mp;
    lld diff = 0;
    int x[4] = {0,0,0,0};
    mp[a[i]]++;mp[a[n-1-i]]++;mp[b[i]]++;mp[b[n-1-i]]++;
    x[0] = mp[a[i]];
    if(a[n-1-i] != a[i]) x[1]= mp[a[n-1-i]];
    if(b[i] != a[n-1-i] && b[i] != a[i]) x[2] = mp[b[i]];
    if(b[n-1-i]!= b[i] && b[n-1-i]!= a[n-1-i] && b[n-1-i]!= a[i]) x[3] = mp[b[n-1-i]];
    
    sort(x,x+4);
    reverse(x,x+4);
//    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<endl;
    if(x[0]==1 && x[1] == 1 && x[2] == 1 && x[3] == 1) diff = 2;
    else if(x[0] == 2 && x[1] == 1 && x[2] == 1){ 
      if(a[i]==a[n-1-i] ) diff = 2; else diff = 1;
    }
    else if(x[0] == 3 && x[1] == 1) diff = 1;
    else if(x[0] == 2 && x[1] == 2) diff = 0;
    else if(x[0] == 4 && x[1] == 0) diff = 0;

    ans += diff;
//    cout<<i<<" "<<ans<<endl;
  }
  if(n%2==1){
    if(a[n/2] != b[n/2]) ans++;
  }
  cout<<ans<<endl;
}
