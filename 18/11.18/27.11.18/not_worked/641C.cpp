#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  faster
  int n,q;
  cin>>n>>q;
  
  int ans[n];
  int one = 0,two = 1;
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a;
    if(a==1){
      cin>>b;
      one = (one+b+n)%n;
      two = (two+b+n)%n;
    } else {
      if(one%2==0) one = (one+1)%n; else one = (one-1+n)%n;
      if(two%2==0)two = (two+1)%n; else two = (two-1+n)%n;
    }
  }
  
  for(int i=0;i<n/2;i++){
    ans[one] = 2*i+1;
    ans[two] = 2*i+2;
    one = (one+2)%n;
    two = (two+2)%n;
  }
  for(int i=0;i<n;i++)cout<<ans[i]<<" ";cout<<'\n';
}
