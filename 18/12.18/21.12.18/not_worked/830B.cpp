#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define NUM 100007
#define pr pair< lld,lld >

using namespace std;

int main(){
	int n;
	cin>>n;
	lld ans = 0;
	
	multiset< pr > num;
	
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		num.insert(make_pair(a,i));
	}
	
	multiset< pr >::iterator it;
	lld last=0;
	lld x=0;
	for(it = num.begin();it != num.end();it++){
		if(!last || last>(*it).second)x++;
		ans += x;
		last = (*it).second;
		cout<<ans<<" "<<(*it).first<<'\n';
	}
	cout<<ans<<'\n';
}
