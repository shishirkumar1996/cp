#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){

	int n,k;
	cin>>n>>k;
	string input;
	cin>>input;
	
	vi process(n+1);
	for(int i=0;i<=n;i++)process[i] = 0;
	vi temp;
	
	for(int i=1;i<=n;i++){
		process[i] = process[i-1];
		if(input[i-1]=='0'){
			temp.push_back(i);
			process[i]++;
		}
	}
	
	lld ans = INT_MAX;
	for(int i=1;i<=n;i++){
		if(input[i-1]=='1')continue;
		int index = lower_bound(process.begin(),process.end(),process[i-1]+k+1)-process.begin();
		if(index==n+1)continue;
		int dist = (index-i);
		int x = lower_bound(temp.begin(),temp.end(),i+(dist+1)/2)-temp.begin();
		ans = min(ans,max(abs(temp[x]-i),abs(index-temp[x])));
		ans = min(ans,max(abs(temp[x-1]-i),abs(index-temp[x-1])));
	}
	cout<<ans<<'\n';
}
