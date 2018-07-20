#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXM (lld)(1e12+7)

using namespace std;

int main(){

  int n;
  cin>>n;
  for(int i = 0;i<n;i++){
    lld a;
    cin>>a;
    lld ans = 4*a+1;   // for 1st corner
    if((2*a)%4==2) ans = min(ans,2*a+1); // for 2nd corner
    if(a%4==3) ans = min(ans,a+1);  // for 3r corner
    cout<<ans<<endl;
  }
}
