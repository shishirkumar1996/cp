#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

class DisjointSet{
  public:
  vi parent;
  DisjointSet( int n): parent(n) {for(int i=0;i<n;i++) parent[i] = i;}
  void join(int a,int b){ parent[find(b)] = find(a);}
  int find(int a){ return a== parent[a] ? a: parent[a] = find(parent[a]);}
  bool check(int a,int b){return find(a)==find(b);}
};

int main(){
  int n;
  cin>>n;
  vi l(n+1),r(n+1);
  DisjointSet ds(n+1);
  for(int i=1;i<=n;i++){ 
    cin>>l[i]>>r[i];
    if(l[i])ds.join(i,l[i]);
    if(r[i])ds.join(i,r[i]);
    if(l[i] && r[i]) ds.join(l[i],r[i]);    
  }
  
  for(int i=1;i<=n;i++){
    if(l[i] && r[i])continue;
    for(int j=i+1;j<=n;j++){
      if(l[j] && r[j])continue;
      if((!l[i] && !r[j])||(!r[i] && !l[j])){
        if(ds.check(i,j))continue;
        ds.join(i,j);
        if(!l[i] && !r[j]){ l[i] = j;r[j] = i; }
        else if(!r[i] && !l[j]) { r[i] = j; l[j] =i; }
      }
    }
  }
  
  for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<'\n';  

}

