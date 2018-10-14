#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >
#define NUM 200007
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

vii graph(NUM),inv_graph(NUM);
int red[NUM],num[NUM];
int total = 0;

void dfs(int v,int p,int r,int x){
  red[v] = r;
  num[v] = x;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(child==p)continue;
    dfs(child,v,r,x+1);
  }
  for(int i=0;i<inv_graph[v].size();i++){
    int child= inv_graph[v][i];
    if(child==p)continue;
    dfs(child,v,r+1,x+1);
    total++;
  }
}

int main(){

  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int s,t;
    cin>>s>>t;
    graph[s].push_back(t);inv_graph[t].push_back(s);
  }
  dfs(1,-1,0,0);
  vi input;
  int minm = INT_MAX;
  for(int i=1;i<=n;i++){
    int temp = (total-red[i])+(num[i]-red[i]);
    if(temp<minm){
      minm = temp;
      input.clear();
      input.push_back(i);
    }
    else if(temp==minm)input.push_back(i);
  }
  cout<<minm<<endl;
  for(int i=0;i<input.size();i++)cout<<input[i]<<" ";cout<<'\n'; 
}
