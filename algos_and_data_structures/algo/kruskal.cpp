#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define pr pair< int,int >
#define ppr pair< int,pr >
#define vppr vector< ppr >
#define NUM 100007

using namespace std;



class DisjointSet{

  public:
  
  vi parent;
  
  DisjointSet( int n): parent(n) {for(int i=0;i<n;i++) parent[i] = i;}
  
  void join(int a,int b){ parent[find(b)] = find(a);}
  
  int find(int a){ return a== parent[a] ? a: parent[a] = find(parent[a]);}
  
  bool check(int a,int b){return find(a)==find(b);}

};

vppr edges;
int n,m;
  
void kruskal(){
  
  sort(edges.begin(),edges.end());
  
  DisjointSet ds(n);
  for(int i=0;i<edges.size();i++){
    int u= edges[i].second.first;
    int v=edges[i].second.second;
    
    if(!ds.check(u,v)){
      cout<<u<<" - "<<v<<endl;
      //this vertex is added into mst
      ds.join(u,v);
  }
    }
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges.push_back(make_pair(c,make_pair(a,b)));
  }
  kruskal();
}
