#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define MOD (lld)(1e9+9)

using namespace std;

lld power(lld x,lld y){
	lld res = 1;
	while(y){
		if(y%2==1)res = (res*x)%MOD;
		x = (x*x)%MOD;
		y = y/2;
	}
	return res;
}

lld inverse_modulo(lld a){ return power(a,MOD-2); }

int main(){
	lld n,a,b,k;
	cin>>n>>a>>b>>k;
	
	string input;
	cin>>input;
	lld temp = 0,ans = 0;
	for(lld i=0;i<k;i++){
		lld sign = (input[i]=='+'?1:-1);
		temp = (MOD+temp+sign*power(a,n-i)*power(b,i))%MOD;
		if(temp<0)temp+= MOD;
	}

	lld diff = (power(b,k)*inverse_modulo(power(a,k)))%MOD;
	lld times = (n+1)/k;
	
	if(diff==1){ cout<<(temp*times)%MOD<<'\n';return 0; }
	temp = (temp*(power(diff,times)-1))%MOD;
	temp = (temp*inverse_modulo(diff-1))%MOD;
	cout<<temp<<'\n';
}
