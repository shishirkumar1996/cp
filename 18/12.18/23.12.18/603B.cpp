#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define NUM 1000007
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int num;
bool visited[NUM];
lld p,k;

void dfs(lld v){
	if(visited[v])return;
	visited[v] = true;
	num++;
	dfs((v*k)%p);
}

int main(){
	
	lld x[NUM];
	for(int i=0;i<NUM;i++){ x[i] = 0;visited[i] = false; }
	
	cin>>p>>k;
	if(k<=1){
		lld x =1;
		int index = p;
		if(k==0) index--;
		for(int i=1;i<=index;i++) x = (x*p)%MOD;
		cout<<x<<'\n';
		return 0;
	}
	else if(k==1){
		
	}
	for(int i=1;i<p;i++){
		if(!visited[i]){
			num = 0;
			dfs(i);
			x[num]++;
		}
	}
	lld ans = 0;
	for(int i=2;i<p;i++){
		if(!x[i])continue;
		lld temp = 1;
		for(int j=1;j<=x[i];j++) temp = (temp*(x[i]*i+1))%MOD;
		ans += temp;		
	}
	cout<<ans<<'\n';
}
