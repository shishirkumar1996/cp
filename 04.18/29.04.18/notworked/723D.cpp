#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vc vector< char >
#define vcc vector< vc >
#define pr pair< int,int >
#define ppr pair< int, pr >

using namespace std;

int row[4] = {-1,0,1,0};
int col[4] = {0,1,0,-1};
int main(){

  faster
  int n,m,k;
  cin>>n>>m>>k;
  vcc input(n);
  for(int i = 0;i<n;i++){
    input[i].resize(m);
    for(int j = 0;j<m;j++)
      cin>>input[i][j];
  }
  vector< ppr > process;
  
  bool visited[n][m];
  for(int i = 0;i<n;i++)
    for(int j = 0;j<m;j++)
      visited[i][j] = false;
      
  stack< pr > dfs;
  
  for(int i =0;i<n;i++)
    for(int j =0;j<m;j++){

      if(input[i][j] == '*')
        continue;
      int flag = 0;
      if(!visited[i][j]){
        
        dfs.push(make_pair(i,j));
        int size = 0;
        while(dfs.size()){
          
          size++;
          pr top = dfs.top();
          dfs.pop();
          int r = top.first,c = top.second;
          if(r==0||r==n-1||c==0||c==m-1)
            flag = 1;
          visited[r][c] = true;
          for(int l = 0;l<4;l++){
            if(r+row[l]>=0 && r+row[l]<n && c+col[l]>=0 && c+col[l]<m && input[r+row[l]][c+col[l]]=='.' && !visited[r+row[l]][c+col[l]])
              dfs.push(make_pair(r+row[l],c+col[l]));
          
          }
              
        
        }
        if(!flag)
          process.push_back(make_pair(size,(make_pair(i,j))));
      }
    
    }
    
    sort(process.begin(),process.end());
    int total = 0;
    for(int i = 0;i<n;i++)
     for(int j = 0;j<m;j++)
      visited[i][j] = false;
    
    for(int i = 0;i<process.size()-k;i++)
    {
      stack<pr>dfs;
      total += process[i].first;      
      dfs.push(process[i].second);
      while(dfs.size()){
        pr top = dfs.top();
        dfs.pop();
        int r = top.first,c = top.second;
        input[r][c] = '*';
        visited[r][c] = true;
        for(int l = 0;l<4;l++){
          if(r+row[l]>=0 && r+row[l]<n && c+col[l]>=0 && c+col[l]<m && input[r+row[l]][c+col[l]]=='.' && !visited[r+row[l]][c+col[l]])
            dfs.push(make_pair(r+row[l],c+col[l]));
        
        }       
      }     
    }
    
    cout<<total<<endl;    
    for(int i =  0;i<n;i++){
      for(int j = 0;j<m;j++)
        cout<<input[i][j];
      cout<<endl;
    } 

}

