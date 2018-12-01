#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';


using namespace std;

int main(){

  int t;
  cin>>t;
  for(int j=0;j<t;j++){
    lld n,k;
    cin>>n>>k;
    vi input(n);
    lld sum = 0;
    for(int i=0;i<n;i++){ cin>>input[i];sum += input[i]; }
    sort(input.begin(),input.end());
    lld diff_sum = 0;
    for(int i=0;i<n-1;i++){
      if(input[i]<=k)continue;
      diff_sum += max(0ll,input[i]-k);
    }
    sum -= diff_sum;
    if(max(0ll,input[n-2]-k)<=diff_sum/2){
      sum -= (diff_sum%2);
    } else {
      lld temp = 2*max(0ll,input[n-2]-k)-diff_sum;
      sum -= temp;
    }
    cout<<sum<<'\n';   
  }
}
