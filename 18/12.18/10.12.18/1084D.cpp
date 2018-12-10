#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define pr pair< lld,lld >
#define vp vector< pr >
#define vpp vector< vp >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define NUM 300007

using namespace std;

vpp graph(NUM);
bool visited[NUM];
lld val[NUM];
lld ans = 0;

lld dfs(int v){

	visited[v] = true;
	lld maxm = 0,second_maxm = 0;
	for(int i=0;i<graph[v].size();i++){
		int child =graph[v][i].first;
		lld cap = graph[v][i].second;
		if(visited[child])continue;
		lld x = dfs(child);
		if(x-cap<0)continue;
		lld y = x-cap;
		if(y>maxm) {second_maxm = maxm; maxm = y; }
		else if(y>second_maxm) second_maxm = y;
	}
	ans = max(ans,maxm+second_maxm+val[v]);
	return maxm+val[v];
}


int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)visited[i] = false;
	for(int i=1;i<=n;i++)cin>>val[i];
	
	for(int i=1;i<n;i++){
		lld a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));
	}
	
	dfs(1);
	cout<<ans<<'\n';
}
