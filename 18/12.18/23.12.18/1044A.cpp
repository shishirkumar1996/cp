#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define NUM (lld)(1e9)

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vi vertical,horizontal;
	for(int i=0;i<n;i++){
		lld a;
		cin>>a;
		vertical.push_back(a);
	}
	vertical.push_back(NUM);
	
	for(int i=0;i<m;i++){
		lld x1,x2,y;
		cin>>x1>>x2>>y;
		if(x1 >1)continue;
		horizontal.push_back(x2);
	}
	
	int ans = NUM;
	sort(horizontal.begin(),horizontal.end());
	sort(vertical.begin(),vertical.end());
	for(int i=0;i<=n;i++){
		int index = lower_bound(horizontal.begin(),horizontal.end(),vertical[i])-horizontal.begin();
		index = horizontal.size()-index;
		ans = min(ans,i+index);
	}
	cout<<ans<<endl;
}
