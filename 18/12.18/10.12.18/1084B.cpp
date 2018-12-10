#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e15+7)

using namespace std;

int main(){
	lld n,s;
	cin>>n>>s;
	
	vi input(n);
	lld sum = 0;
	lld minm = MAXM;
	for(int i=0;i<n;i++){ cin>>input[i]; sum+= input[i]; minm = min(minm,input[i]);}
	if(sum<s){ cout<<-1<<endl; return 0; }
	
	lld low = 0,high = minm;
	lld ans;
	while(low<=high){
		lld mid = (low+high)/2;
		lld x = 0;
		for(int i=0;i<input.size();i++){ x+= max(0ll,input[i]-mid); }
		if(x>=s){ans = mid; low = mid+1;} else high = mid-1;
	}
	cout<<ans<<'\n';
}
