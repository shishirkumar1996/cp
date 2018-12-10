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
	lld ans = 0;
	
	string a;
	lld n;
	cin>>a>>n;
	for(int i=0;i<a.length();i++)
		if(a[i]=='5'||a[i]=='0')
			ans = (ans+power(2,i))%MOD;
	ans = (ans*(power(2,n*a.length())-1))%MOD;
	ans = (ans*(power(power(2,a.length())-1,MOD-2)))%MOD;
	cout<<ans<<'\n';
}
