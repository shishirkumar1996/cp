#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< int,int >
#define vp vector< pr >
#define vip vector< vp >
#define NUM 107

using namespace std;

vip graph(NUM);
int dp[2][NUM][NUM][26];

int dfs(int turn,int f,int s,int c){
	if( dp[turn][f][s][c] != -1)return (1^dp[turn][f][s][c]);
	
	if(turn==0){
		int x = 0;
		for(int i=0;i<graph[f].size();i++){
			int child  = graph[f][i].first;
			int num = graph[f][i].second;
			if(num>=c)x = x|dfs(turn^1,child,s,num);
		}
		dp[turn][f][s][c] = x;
		return dp[turn][f][s][c]^1;
	} else {
		int x = 0;
		for(int i=0;i<graph[s].size();i++){
			int child = graph[s][i].first;
			int num = graph[s][i].second;
			if(num>=c) x=x|dfs(turn^1,f,child,num);
		}
		dp[turn][f][s][c] = x;
		return dp[turn][f][s][c]^1;
	}
}


int main(){

	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int a,b;char c;
		cin>>a>>b>>c;
		graph[a].push_back(make_pair(b,c-'a'));
	}
	for(int i=0;i<2;i++)for(int j=0;j<NUM;j++)for(int k=0;k<NUM;k++)for(int l=0;l<26;l++)dp[i][j][k][l] = -1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dfs(0,i,j,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<((char)('A'+(1^dp[0][i][j][0])));
		cout<<'\n';
	}
	

}
