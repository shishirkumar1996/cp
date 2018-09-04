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

  int n,m,q;
  cin>>n>>m>>q;
  map< string,int > process;
  
  for(int i=0;i<n;i++){
    string a;
    cin>>a;
    process[a] = i;
  }
  
  DisjointSet d(2*n);
  for(int i=0;i<m;i++){
    int k;
    string x,y;
    cin>>k>>x>>y;
    int a = process[x],b = process[y];
    if(k==1){
      if(d.check(a,b+n))cout<<"NO"<<endl;
      else { cout<<"YES"<<endl; d.join(a,b); d.join(a+n,b+n); }
    } else{
      if(d.check(a,b))cout<<"NO"<<endl;
      else{ cout<<"YES"<<endl;d.join(a,b+n);d.join(b,a+n);}
    }
  }
  for(int i=1;i<=q;i++){
    string x,y;
    cin>>x>>y;
    int a = process[x],b = process[y];
    if(d.check(a,b))cout<<1<<endl;
    else if(d.check(a,b+n))cout<<2<<endl;
    else cout<<3<<endl;
  }
}
