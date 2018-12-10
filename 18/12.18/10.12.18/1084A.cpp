#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e9+7)

using namespace std;

int main(){

	int n;
	cin>>n;
	
	vi input(n);
	for(int i=0;i<n;i++)cin>>input[i];
	
	lld minm = MAXM;
	
	for(int i=0;i<n;i++){
		lld temp = 0;
		for(int j=0;j<n;j++)
			temp += 2*input[j]*(abs(i-0)+abs(0-j)+abs(j-i));
		minm = min(minm,temp);
	}
	cout<<minm<<'\n';
}
