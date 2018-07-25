#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007


using namespace std;

int n,start;
vii graph(NUM);
int path[NUM];

bool is_safe(int v,int pos){
  if(graph[path[pos-1]][v] == 0) return false;
  
  for(int i=0;i<pos;i++) if(path[i]==v)return false;
  return true;
}

bool ham_cycle(int pos){
  for(int i=0;i<n;i++)
    if(is_safe(i,pos)){
      path[pos] = i;
      if(ham_cycle(pos+1)==true)return true;
      path[pos]=-1;
    }
}

int main(){
  n = 5,start = 3;
  int x[][n] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
  for(int i=0;i<n;i++)for(int j=0;j<n;j++) graph[i].push_back(x[i][j]);
  for(int i=0;i<n;i++) path[i] = -1;
  
  path[0] = start;
  if(ham_cycle(1)==false){
    cout<<" Solution does not exist"<<endl;return 0;
  } else for(int i=0;i<n;i++)cout<<path[i]<<" ";
  cout<<path[0]<<endl;

}

