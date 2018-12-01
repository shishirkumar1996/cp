#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< int,int >
#define vp vector< pr >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;
void print(vi x){

  cout<<x.size()<<'\n';
  for(int i=0;i<x.size();i++)cout<<x[i]<<" ";cout<<'\n';
}

int main(){

  int n;
  cin>>n;
  vp input(n);
  for(int i=1;i<=n;i++){
    cin>>input[i-1].first;
    input[i-1].second = i;
  }
  sort(input.begin(),input.end());
  vi first,second;
  for(int i=0;i<n;i++){
    if(i%2==0)first.push_back(input[i].second);
    else second.push_back(input[i].second);
  }
  print(first);print(second);
}
