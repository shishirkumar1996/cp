#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int, int >
#define vp vector< pr >
#define vi vector< int >
#define vii vector< vi >

using namespace std;

stack< int > process;
vii input(3030);
bool visited[3030];
int last,parent[3030];

int dfs(int v){
  
  for(int i = 0;i<input[v].size();i++){
    int child = input[v][i];
    if(child == parent[v]) continue;
      if(!visited[child]){ 
        process.push(child);visited[child] = true;parent[child] = v;
        int x = dfs(child);
        if(x) return x;
      }
      else {last = child;return 1;}
    }
    process.pop();
    return 0;
}


int main(){
  
  int n;
  cin>>n;
  for(int i = 0;i<n;i++){
    int a,b;
    cin>>a>>b;
    input[a].push_back(b);
    input[b].push_back(a);
  }
  
  
  bool ring[n+1];
  int ans[n+1];
  
  for(int i =0;i<=n;i++) ring[i] = visited[i] = false,ans[i]  = 0,parent[i] = 0;
  process.push(1);
  visited[1] = true;
  
  int x = dfs(1);

  while(true){
    int top = process.top();  
    process.pop();
    ring[top] = true;
    if(top==last) break;
  }
  int num;
  for(int i =0;i<=n;i++) if(ring[i]){num=i;break;} 
  
  for(int i = 0;i<=n;i++)visited[i] = false; 
  ans[num] = 0;
  while(process.size())process.pop();
  visited[num] = true;
  process.push(num);
  
  while(process.size()){
    int top = process.top();
    process.pop();
    for(int i = 0;i<input[top].size();i++){
      int child  = input[top][i];
      if(!visited[child]){
        visited[child] = true;
        process.push(child);
        if(!ring[child]) ans[child] = ans[top]+1;
        else ans[child] = 0;
      }
    }  
  }
  for(int i = 1;i<=n;i++)cout<<ans[i]<<" "; 
  cout<<endl;
}
