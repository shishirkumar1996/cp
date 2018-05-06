#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define mod (lld)(1e9+7)
#define vi vector< lld >
#define vii vector< vi >
#define NUM (int)(3e5+7)
#define MAXM 1e10

using namespace std;


lld low[NUM],disc[NUM];

lld timer;
bool stacked[NUM];
stack< lld > scc;
vii input;
lld comps;
lld comp[NUM];

void tarjan(lld n){

  low[n] = disc[n] = ++timer;
  stacked[n] = true;
  scc.push(n);
  for(int i =0;i<input[n].size();i++){
    lld v = input[n][i];
    if(disc[v]==-1){
      tarjan(v);
      low[n] = min(low[n],low[v]);
    }
    else if(stacked[v]==true) low[n] = min(low[n],disc[v]);      
  }
  
  if(low[n]==disc[n]){
    comps++;
    lld top;
    do{
      top = scc.top();
//      cout<<top<<endl;
      scc.pop();
      stacked[top] = false;
      comp[top] = comps;
    }while(top != n);
  }

}

int main(){

  lld n;
  cin>>n;
  vi cost(n+1);
  input.resize(n+1);
  for(int i = 1;i<=n;i++)
    cin>>cost[i];
  
  lld m;
  cin>>m;
  for(int i = 1;i<=m;i++){
    lld a,b;
    cin>>a>>b;
    input[a].push_back(b);
  }
  
  timer = 0;
  comps = 0;
  for(int i = 1;i<=n;i++)
    low[i] = disc[i] = comp[i] = -1,stacked[i]  =false;

  for(int i =1;i<=n;i++)
    if(disc[i]==-1)
      tarjan(i);
  
  lld a=0,b=1;
  lld min[comps+1],ways[comps+1];
  
  for(int i = 0;i<=comps;i++)
    min[i] = MAXM,ways[i] = 0;
  for(int i = 1;i<=n;i++){
    if(min[comp[i]]>cost[i]){
      min[comp[i]] = cost[i],ways[comp[i]]=1;
    }
    else if(min[comp[i]]==cost[i])
      ways[comp[i]]++;
  }
  
  for(int i = 1;i<=comps;i++)
    a = a+min[i],b = (b*ways[i])%mod;
  
//  cout<<comps<<endl; 
//  for(int i = 1;i<=n;i++)
//    cout<<low[i]<<" "<<disc[i]<<" "<<comp[i]<<" "<<min[comp[i]]<<endl;
  
  cout<<a<<" "<<b<<endl;
}
