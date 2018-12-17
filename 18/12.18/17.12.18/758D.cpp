#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<'\n'; }

using namespace std;

lld power(lld x,lld y){
	lld res = 1;
	for(int i=1;i<=y;i++)res *= x;
	return res;
}

int main(){
	
	lld n;
	cin>>n;
	string k;
	cin>>k;
	reverse(k.begin(),k.end());
	
	lld ans = 0;
	int index = 0;
	lld num = 0;
	while(index<k.length()){
		lld temp = 0;
		lld y=0;
		int last = index;
		while(index<k.length() && y+1<=ceil(log10(n)) && (temp+((lld)power(10,y)*(k[index]-'0'))<n)){
			temp += (lld)power(10,y)*(k[index]-'0');
			if(k[index]!='0')last = index;
			index++;
			y++;
		}
		index = last+1;
		ans += (lld)power(n,num)*temp;
		num++;
		temp = 0;
	}
	cout<<ans<<'\n';
}
