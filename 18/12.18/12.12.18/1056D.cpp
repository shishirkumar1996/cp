#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define NUM 100007

using namespace std;

vi output;
vii graph(NUM);

int dfs(int v,int p){

	int x = 0;
	for(int i=0;i<graph[v].size();i++){
		int child = graph[v][i];
		if(child==p)continue;
		x += dfs(child,v);
	}
	if(!x)x++;
	output.push_back(x);
	return x;
}


int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		graph[i].push_back(x);
		graph[x].push_back(i);
	}
	dfs(1,-1);
	sort(output.begin(),output.end());
	for(int i=0;i<output.size();i++)cout<<output[i]<<" ";cout<<'\n';
}
