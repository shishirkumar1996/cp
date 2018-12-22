#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){
	int n,m,i,j,a,b;
	cin>>n>>m>>i>>j>>a>>b;
	
	int ans = INT_MAX;
	if((i==1 && j==1)||(i==n && j==1) ||(i==n && j==m)||(i==1 && j==m))ans = 0;
	
	if((i-a>0 || i+a<=n) && (j-b>0 ||j+b<=m)){
		if(!((n-i)%a>0 || (m-j)%b>0 || ((n-i)/a)%2 != ((m-j)/b)%2))
			ans = min(ans,max((n-i)/a,(m-j)/b));
	
		if(!((i-1)%a>0 || (m-j)%b>0 || ((i-1)/a)%2 != ((m-j)/b)%2))
			ans = min(ans,max((i-1)/a,(m-j)/b));
	
		if(!((n-i)%a>0 || (j-1)%b>0 || ((n-i)/a)%2 != ((j-1)/b)%2))
			ans = min(ans,max((n-i)/a,(j-1)/b));
	
		if(!((i-1)%a>0 || (j-1)%b>0 || ((i-1)/a)%2 != ((j-1)/b)%2))
			ans = min(ans,max((i-1)/a,(j-1)/b));
	}
	
	if(ans==INT_MAX) cout<<"Poor Inna and pony!\n";
	else cout<<ans<<endl;
}
