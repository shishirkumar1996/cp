#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
	lld k,b,n,t;
	
	cin>>k>>b>>n>>t;
	lld num = 1;
	lld index = 0;
	
	while(num<=t){ num = k*num+b; index++; }
	index--;
	cout<<max(0ll,n-index)<<'\n';
}
