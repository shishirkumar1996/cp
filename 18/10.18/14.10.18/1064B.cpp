#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define pr pair< lld,lld >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  int t;
  cin>>t;
  while(t--){
    lld input;
    cin>>input;
    lld num = 0;
    while(input){
      if(input%2==1)num++;
      input = input/2;
    }
    cout<<(lld)pow(2,num)<<endl;
  }
  
}
