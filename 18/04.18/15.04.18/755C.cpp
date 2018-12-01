#include<bits/stdc++.h>
#define vi vector < int >
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vii vector< vi >

using namespace std;


int calc(int n,vii input){

  int counter = 0;
  bool visited[n+1];
  memset(visited,false,n+1);
  
  
  for(int i =1;i<=n;i++){
    if(visited[i])
      continue;
    
    counter++;
    stack< int > dfs;
    dfs.push(i);
    while(dfs.size()){
      int top = dfs.top();
      dfs.pop();
      if(!visited[top])
        visited[top] = true;
      else
        continue;
      for(int j =0;j<input[top].size();j++)
        if(!visited[input[top][j]])
          dfs.push(input[top][j]);
    
    }    
  
  }
  return counter;

}

int main(){
  
  faster
  int n;
  cin>>n;
  vii input(n+1);
  for(int i =1;i<=n;i++){
    int num;
    cin>>num;
    input[i].push_back(num);
    input[num].push_back(i);
  }
  cout<<calc(n,input)<<endl;  

}
