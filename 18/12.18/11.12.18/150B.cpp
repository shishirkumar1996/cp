#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define MOD (lld)(1e9+7)

using namespace std;

lld power(lld x,lld y){
	lld res = 1;
	while(y){
		if(y%2==1) res = (res*x)%MOD;
		x = (x*x)%MOD;
		y = y/2;
	}
	return res;
}

int main(){
	lld n,m,k;
	cin>>n>>m>>k;

	lld ans;
	if(k==1 || k>n) { ans = power(m,n); }
	else if(k==n) { ans = power(m,(n+1)/2); }
	else if(k%2==1) { ans = m*m; }
	else if(k%2==0) { ans = m; }
	
	cout<<ans<<'\n';
}
