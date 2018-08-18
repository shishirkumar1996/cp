#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >
#define NUM 200007
#define MAXM (lld)(1e9+7)

using namespace std;

int n;
vii graph(NUM),inv_graph(NUM);
bool visited[NUM];
lld cost[NUM];
stack< int >st,process;

lld ans = 0;

void dfs(int v){
  visited[v]=  true;
  process.push(cost[v]);
  for(int i=0;i<inv_graph[v].size();i++){
    int child = inv_graph[v][i];
    if(!visited[child])dfs(child);
  }
}
void addEdge(int v,int w){graph[v].push_back(w);inv_graph[w].push_back(v);}

void fillOrder(int v){
  visited[v] = true;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(!visited[child])fillOrder(child);
  }
  st.push(v);
}

void scc(){
  for(int i=1;i<=n;i++)visited[i] = false;
  for(int i=1;i<=n;i++)if(visited[i]==false)fillOrder(i);
  for(int i=1;i<=n;i++)visited[i] = false;
  while(st.size()){
    int v= st.top();
    st.pop();
    if(visited[v]==false){dfs(v);}
    lld minm = MAXM;
    if(process.size()==0)continue;
    if(process.size()==1){process.pop();continue;}
    while(process.size()){
      lld top = process.top();
      process.pop();
      minm = min(minm,top); 
    }
//    cout<<minm<<" "<<ans<<endl;
    ans += minm;   
  }
}

int main(){
  cin>>n;  
  for(int i=1;i<=n;i++)cin>>cost[i];
  
  for(int i=1;i<=n;i++){
    int a;
    cin>>a;
    if(a==i)continue;
    addEdge(i,a);
  }
  for(int i=1;i<=n;i++)if(graph[i].size()==0)ans += cost[i];
  scc();
  cout<<ans<<endl;  
}
