#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;


lld calc(int k,int n ,int s,int p){
  
  int paper = k*ceil(n*1.0/s);
  lld ans = ceil(paper*1.0/p);
  
  return ans;
}

int main(){
  int k,n,s,p;
  cin>>k>>n>>s>>p;
  cout<<calc(k,n,s,p)<<endl;
  

}
