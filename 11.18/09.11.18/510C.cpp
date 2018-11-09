#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n){ cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

vii graph(26);
int visited[26];
stack< char > output;

void dfs(int v){
  visited[v] = 1;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(visited[child]==1){ cout<<"Impossible\n";exit(0);}
    if(!visited[child])dfs(child);
  }
  output.push(v+'a');
  visited[v] = 2;
}

int main(){
  int n;
  cin>>n;
  
  for(int i=0;i<26;i++)visited[i]  = 0;
  vector< string > input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  int j;
  for(int i=1;i<n;i++){
    for(j=0;j<min(input[i].length(),input[i-1].length());j++){
      if(input[i][j] != input[i-1][j]){ 
        graph[input[i-1][j]-'a'].push_back(input[i][j]-'a');
        break;
      }
    }
    if(j==min(input[i].length(),input[i-1].length()) && input[i].length()<input[i-1].length()){ cout<<"Impossible\n"; return 0; }
  }
  for(int i=0;i<26;i++)if(!visited[i])dfs(i);
  while(output.size()){
    cout<<output.top();output.pop();
  }
  cout<<'\n';
}
