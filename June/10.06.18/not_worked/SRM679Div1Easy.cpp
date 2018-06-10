#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

class FiringEmployees{
  
  public:
    
    vii graph;
    int dfs(int vertex,vi salary,vi productivity){
      int profit = (vertex==0)?0:(productivity[vertex-1]-salary[vertex-1]);
      for(int i= 0;i<graph[vertex].size();i++){
        int child = graph[vertex][i];
        profit += dfs(child,salary,productivity);
      }
      if(profit<0)return 0;
      return profit;
    }
    
    int fire(vi manager,vi salary,vi productivity){
      faster      
      int n = salary.size();
      graph.resize(n+1);
      for(int i = 0;i<manager.size();i++) graph[manager[i]].push_back(i+1);
    
      return dfs(0,salary,productivity);
    }
};

int main(){
  
  int size = 3;
  int a[] = {0,0,0};
  int b[] = {1,2,3};
  int c[] = {3,2,1};
  
  vi manager(size),salary(size),productivity(size);
  for(int i = 0;i<size;i++) manager[i] = a[i],salary[i] = b[i],productivity[i] = c[i];
  FiringEmployees f;
  cout<<f.fire(manager,salary,productivity)<<endl;
  
}

