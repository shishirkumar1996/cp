#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e17+9)

using namespace std;

int main(){

	int n,m;
	cin>>n>>m;
	
	vi input(n);
	for(int i=0;i<n;i++)cin>>input[i];
	
	lld l=0,h = MAXM;
	lld ans;
	while(l<=h){
		
		lld mid = (l+h)/2;
		vi temp = input;
		int index = n-1;
		lld tm = mid-n;
		int num = 1;
		while(index>=0 && num<=m){
			lld s = min(temp[index],tm);
			temp[index] -= s;
			tm -= s;
			if(!temp[index]) index--;
			if(!tm) {tm = mid-1-index;num++; }
		}
		if(index<0){ ans = mid; h = mid-1; }
		else l = mid+1;
	}
	cout<<ans<<'\n';
}
