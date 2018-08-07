#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;
 
int n;//number of vertices
vii graph(NUM),inv_graph(NUM);
bool visited[NUM];
stack< int > st;
 

void dfs(int v){
  visited[v] = true;
  cout<<v<<" ";
  for(int i=0;i<inv_graph[v].size();i++){
    int child = inv_graph[v][i];
    if(!visited[child])dfs(child);
  }
}
 
void addEdge(int v, int w){graph[v].push_back(w);inv_graph[w].push_back(v);}
 
void fillOrder(int v){
  visited[v] = true;
  for(int i = 0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(!visited[child]) fillOrder(child);
  }
  st.push(v);
}
 
void printSCCs(){
  for(int i = 0; i < n; i++)visited[i] = false;
  for(int i = 0; i < n; i++)if(visited[i] == false)fillOrder(i);
  for(int i = 0; i < n; i++) visited[i] = false;
  while (st.size()){
    int v = st.top();
    st.pop();
    if (visited[v] == false){ dfs(v);cout << endl; }
  }
}
 
int main()
{
  n = 5;
  addEdge(1, 0);addEdge(0, 2);addEdge(2, 1);addEdge(0, 3);addEdge(3, 4);

  cout << "Following are strongly connected components in "
          "given graph \n";
  printSCCs();

  return 0;
}


