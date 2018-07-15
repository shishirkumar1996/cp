#include<bits/stdc++.h>
#define NUM 100007
#define vi vector< int >
#define vii vector< vi >


using namespace std;

const int M=6,N=6;
vii graph(NUM);
int ans;
bool seen[NUM];
int match[NUM];

bool bpm(int u){
  
  for(int i= 0;i<graph[u].size();i++){
    int c= graph[u][i];
    if(!seen[c]){
      seen[c] = true;
      if(match[c] < 0 || bpm(match[c])){
        match[c] = u;return true;
      }
    }
  }
  return false;
}

void initialize(bool bpGraph[M][N]){

  for(int i=0;i<NUM;i++) match[i] = -1;
  
  for(int i=0;i<M;i++)
    for(int j=0;j<N;j++) if(bpGraph[i][j]) graph[i].push_back(j);
  
  ans =0;
  for(int i=0;i<M;i++){
    memset(seen,0,sizeof(seen));
    ans += bpm(i);
  }
  cout<<ans<<endl;
}

int main(){
  
  bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0},
                          {1, 0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1}};
  
  initialize(bpGraph); 
}
