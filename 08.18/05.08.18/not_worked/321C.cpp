#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MAXN 100007

using namespace std;

vii tree(MAXN);
vii centroid_tree(MAXN);
bool centroid_marked[MAXN],visited[MAXN];
vi subtree_size(MAXN);
int n;  // number of vertices of the graph
int num; // number of nodes visited till now

void add_edge(int u,int v){
  tree[u].push_back(v);tree[v].push_back(u);
}

void dfs(int src){
  visited[src] = true;
  num ++;
  subtree_size[src] = 1;
  for(int i=0;i<tree[src].size();i++){
    int child = tree[src][i];
    if(!visited[child] && !centroid_marked[child]){
      dfs(child);
      subtree_size[src] += subtree_size[child];
    }
  }
}

int get_centroid(int src){
  for(int i=0;i<MAXN;i++){ visited[i] =  false; subtree_size[i] = 0;} 
  num = 0;
  dfs(src);
  for(int i=0;i<MAXN;i++) visited[i] = false;
  
  bool is_centroid = true;
  visited[src] = true;
  
  int heaviest_child = -1;
  for(int i=0;i<tree[src].size();i++){
    int child = tree[src][i];
    if(!visited[child] && !centroid_marked[child]){
      if(subtree_size[child]> num/2) is_centroid = false;
      if(heaviest_child == -1|| subtree_size[child] > subtree_size[heaviest_child]) heaviest_child = child;
    }
  }
  if(is_centroid && num-subtree_size[src] <= num/2) return src;
  return get_centroid(heaviest_child);
}

int decompose_tree(int root){
  
  int cend_tree = get_centroid(root);
  centroid_marked[cend_tree] = true;
  
  for(int i=0;i<tree[cend_tree].size();i++){
    int child = tree[cend_tree][i];
    if(!centroid_marked[child]){
      int cend_subtree = decompose_tree(child);
      centroid_tree[cend_tree].push_back(cend_subtree);
      centroid_tree[cend_subtree].push_back(cend_tree);
//      cout<<cend_tree<<" "<<cend_subtree<<endl;
    }
  }
  return cend_tree;
}

int main(){
 
 faster
 cin>>n;
 
 for(int i=1;i<n;i++){
  int a,b;
  cin>>a>>b;
  add_edge(a,b);
 }
 int cent = decompose_tree(1);
 
 for(int i=1;i<=n;i++)visited[i] = false;
 
 char rank[n+1];
 for(int i=1;i<=n;i++)rank[i] = '?';
 stack< int > process;
 process.push(cent);
 rank[cent] = 'A';
 visited[cent] =  true;
 while(process.size()){
  int v = process.top();
  process.pop();
  for(int i=0;i<centroid_tree[v].size();i++){
    int child = centroid_tree[v][i];
    if(visited[child])continue;
    if(rank[v] == 'Z'){printf("Impossible!\n");return 0;}
    rank[child] = rank[v]+1;
    process.push(child);
    visited[child] = true;
  }
 }
 for(int i=1;i<=n;i++)printf("%c ",rank[i]);
 printf("\n");
}
