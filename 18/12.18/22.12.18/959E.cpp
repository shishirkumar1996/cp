#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
	lld n;
	cin>>n;
	
	lld ans = 0;
	lld upper = (lld)pow(2,ceil(log2(n)));
	for(lld i=2;i<=upper; i = i*2){
		lld grp = n/i;
		if(n%i>i/2) grp++;
		ans += grp*(i/2);
	}	
	cout<<ans<<endl;
}
