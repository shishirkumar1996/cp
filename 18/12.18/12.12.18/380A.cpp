#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define ppr pair< lld, pr >
#define vppr vector< ppr >
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){

	int n;
	cin>>n;
	
	vppr input;
	lld index = 0;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t==1){
			lld a;
			cin>>a;
			index++;
			input.push_back(make_pair(index,make_pair(a,-1)));
		} else {
			lld b,c;
			cin>>b>>c;
			index += (b*c);
			input.push_back(make_pair(index,make_pair(-1,c)));
		}
	}
	
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		lld x;
		cin>>x;
		while(true){
			int index = lower_bound(input.begin(),input.end(),make_pair(x,make_pair(-1ll,-1ll)))-input.begin();
			if(input[index].second.first != -1){
				cout<<input[index].second.first<<" ";break;
			} else {
				lld c = input[index].second.second;
				lld l = (input[index].first-input[index-1].first)/c;
				x = (x-input[index-1].first)%l;
				if(!x) x += l;
			}
		}
	}
	cout<<'\n';
}
