#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define NUM 1000007

using namespace std;

int main(){

	faster
	int n;
	cin>>n;
	
	bool present[NUM];
	int ans[NUM];
	int maxm = 1;
	
	
	for(int i=0;i<n;i++){
		lld a;
		cin>>a;
		present[a] = true;
		ans[a] = 1;
	}

	for(lld i=1;i<NUM;i++){
		if(!present[i])continue;
		for(lld j = 2*i;j<NUM;j+=i){
			if(present[j]){
				ans[j] =  max(ans[j],ans[i]+1);
				maxm = max(maxm,ans[j]);
			}
		}
	}
	cout<<maxm<<endl;
}

