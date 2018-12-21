#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define NUM 100007

using namespace std;

int ans = 0;	
int a,b,m,r;

int visited[NUM];

void dfs(int v){
	visited[v]++;
	if(visited[v]==2)ans++;
	if(visited[v]>2) return;
	dfs((a*v+b)%m);
}

int main(){
	cin>>a>>b>>m>>r;
	dfs(r);
	cout<<ans<<'\n';
}	
