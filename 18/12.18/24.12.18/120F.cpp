#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define NUM 107
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

struct gr{
	vector< int > graph[NUM];
};

struct gr input[NUM];

int maxm,num;
void dfs(int v,int p,int index,int ct){
	if(ct>maxm){ maxm = ct;num = v; }
	for(int i=0;i<input[index].graph[v].size();i++){
		int child = input[index].graph[v][i];
		if(child==p)continue;
		dfs(child,v,index,ct+1);
	}
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ans = 0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		for(int j=0;j<x-1;j++){
			int a,b;
			cin>>a>>b;
			input[i].graph[a].push_back(b);
			input[i].graph[b].push_back(a);
		}
		maxm = -1;
		dfs(1,-1,i,0);
		dfs(num,-1,i,0);
		ans += maxm;
	}
	cout<<ans<<'\n';
}
