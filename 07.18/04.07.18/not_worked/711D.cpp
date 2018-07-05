#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)

using namespace std;

bool visited[200007];
int last;
int parent[200007];
stack< int > process;
vii input(200007);

int dfs(int vertex){
    
    cout<<vertex<<endl;
//  cout<<"probe 2"<<" "<<vertex<<endl;
//  cout<<vertex<<" "<<input[vertex].size()<<endl;
  for(int i = 0;i<input[vertex].size();i++){
//    cout<<"probe 0"<<endl;
    int child = input[vertex][i];
    if(child== parent[vertex]) continue;
    cout<<vertex<<" "<<child<<endl;
    if(!visited[child]){
      visited[child] = true;
      process.push(child);
      parent[child] = vertex;
      int x= dfs(child);
      if(x) return x;
    }
    else {last = vertex;return 1;}
  }
  process.pop();
  return 0;
}

int main(){
  
  int n;
  cin>>n;
  for(int i = 1;i<=n;i++){
    int a;
    cin>>a;  
    input[i].push_back(a);
    input[a].push_back(i);
  }
  last = -1;
  for(int i  = 1;i<=n;i++) visited[i] = false,parent[i] = 0;
  
  int a;
  for(int i = 1;i<=n;i++){
    if(!visited[i])
    {
      visited[i] = true;
      process.push(i);
//      cout<<"probe 1"<<endl;
      a = dfs(i);
      if(a)break;
    }
  }
//  cout<<"probe 3"<<endl;
  lld ans = 1;
  for(int i=  1;i<=n;i++) ans = (ans*2)%MOD; 
  
  if(a==0){
    lld temp = 1;
    for(int i=1;i<n;i++) temp = (temp*2)%MOD;
    ans = (ans-temp+MOD)%MOD;
    cout<<ans<<endl;
  } else{
    int num = 0;
    while(true){
      int top = process.top();
//      cout<<top<<endl;
      num++;
      process.pop();
      if(top==last) break;
    }
//    cout<<num<<endl;
    lld temp = 1;
    for(int i= 1;i<=n-num+1;i++)  temp = (temp*2)%MOD;
    ans= (ans-temp+MOD)%MOD;
    cout<<ans<<endl;
  }

}
