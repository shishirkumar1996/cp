#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define pr pair< lld,int >
#define vp vector< pr >
#define vpp vector< vp >

using namespace std;

int main(){

  int n,k;
  cin>>n>>k;
  
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  vi process = input;
  sort(process.begin(),process.end());
  vpp graph(n+1);
  for(int i=0;i<k;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(make_pair(input[b-1],b));
    graph[b].push_back(make_pair(input[a-1],a));
  }
  for(int i=1;i<=n;i++)sort(graph[i].begin(),graph[i].end());
  
  for(int i=0;i<n;i++){
    int x = lower_bound(graph[i+1].begin(),graph[i+1].end(),make_pair(input[i],-1))-graph[i+1].begin();
    int y =lower_bound(process.begin(),process.end(),input[i])-process.begin();
    cout<<y-x<<" ";
  }
  cout<<endl;
}

