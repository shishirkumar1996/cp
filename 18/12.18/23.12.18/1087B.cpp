#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e9+7)

using namespace std;

int main(){

	lld n,k;
	cin>>n>>k;
	
	lld ans = MAXM;
	for(lld x=k-1;x>=1;x--){
		if(n%x != 0) continue;
		lld y = n/x;
		ans = min(ans,y*k+x);
	}
	cout<<ans<<'\n';
}
