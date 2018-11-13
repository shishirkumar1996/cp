#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) {  cerr<<#a<<": "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){
  faster
  int n;
  cin>>n;
  multiset< int > input;  
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    input.insert(-a);
  }
  vii output(n);
  int sz = 0;
  while(input.size()){
    int a = -(*input.begin());
    input.erase(input.begin());
    multiset< int >::iterator it = upper_bound(input.begin(),input.end(),-a);
    if(it==input.end())break;
    int b = -(*it);
    input.erase(it);
    it = upper_bound(input.begin(),input.end(),-b);
    if(it==input.end())break;
    int c = -(*it); input.erase(it);
    output[sz].push_back(a);output[sz].push_back(b);output[sz].push_back(c);
    sz++;
  }
  cout<<sz<<'\n';
  for(int i=0;i<sz;i++)cout<<output[i][0]<<" "<<output[i][1]<<" "<<output[i][2]<<'\n';
}
