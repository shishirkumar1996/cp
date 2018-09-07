#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int q;
  cin>>q;
  for(int i=1;i<=q;i++){
    lld n,m,k;
    cin>>n>>m>>k;
    if(n>m)swap(n,m); // n is taken to be smaller
    if(n>k||m>k){cout<<-1<<'\n';}
    else {
      lld ans = n;
      m -= n;
      k -= n;
      n = 0;
      if(m==0){ n++,m++,ans--;k++;}

      if(n==0){
        if(m%2==0){
          if(k%2==0) ans += k;
          else ans += (k-2);
        } else ans += (k-1);
      }
      else if(n==1){
       if(k%2==0) ans += (k-2);
       else ans += k;
      }  
      cout<<ans<<'\n';
    }
  }

}
