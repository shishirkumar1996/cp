#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >

using namespace std;

#define MAXN 1025

vii tree(MAXN);
vii centroid_tree(MAXN);
bool centroid_marked[MAXN],visited[MAXN];
vi subtree_size(MAXN);
int n;  // number of vertices of the graph
int num; // number of nodes visited till now

void add_edge(int u,int v){ tree[u].push_back(v);tree[v].push_back(u); }

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
      cout<<cend_tree<<" "<<cend_subtree<<endl;
    }
  }
  return cend_tree;
}

int main(){
  n = 16;
  add_edge(0,3);add_edge(1,3);add_edge(2,3);add_edge(3,4);add_edge(4,5);
  add_edge(5,6);add_edge(6,7);add_edge(6,8);add_edge(5,9);add_edge(9,10);
  add_edge(10,11);add_edge(10,12);
  add_edge(11,13);add_edge(12,14);add_edge(12,15);
  
 decompose_tree(0); 
}
