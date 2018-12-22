#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define NUM 200007

using namespace std;

int main(){
	
	faster
	lld ans[2][NUM];
	map< lld,int >process;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		lld a;
		cin>>a;
		process[a]++;
	}
	for(int i=0;i<NUM;i++)ans[0][i] = ans[1][i] =  0;
	map< lld,int >::iterator it;

	lld maxm = 0;
	int turn = 0;
	for(it = process.begin();it!=process.end();it++){
		for(lld i=1;i<=it->second;i++){
			if(i%2==1) ans[turn][i] = max(ans[turn][i],i);
			else ans[turn][i] = max(ans[turn][i],i+ans[turn^1][i/2]);
			maxm = max(maxm,ans[turn][i]);
		}
		turn = turn^1;
	}
	cout<<maxm<<endl;
}
