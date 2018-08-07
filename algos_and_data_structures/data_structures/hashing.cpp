#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

struct hasher{
  lld b = 311,m;vi h,p;
  hasher(string s,lld _m) :m(_m),h(s.size()+1),p(s.size()+1) {
    p[0] = 1;h[0] = 0;
    for(int i=0;i<s.size();i++) p[i+1] = p[i]*b%m;
    for(int i=0;i<s.size();i++) h[i+1]  = (h[i]*b+s[i])%m;
  }
  lld hash(int l,int r){
    return (h[r+1]+m-h[l]*p[r-l+1]%m)%m;
  }
};


int main(){

  hasher h("asjkfl",100007);
  cout<<h.hash(0,5)<<endl;

}
