#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<":  ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){

	int n;
	cin>>n;
	vi input(n);
	for(int i=0;i<n;i++)cin>>input[i];
	
	for(int i=0;i<n;i++){
		int index,maxm = 0;
		for(int j=0;j<input.size();j++){
			if(maxm<input[j]){ maxm = input[j];index = j; }
			if(j>0 && abs(input[j]-input[j-1])>=2){ cout<<"NO\n"; return 0; }
			if(j<input.size()-1 && abs(input[j]-input[j+1])>=2){ cout<<"NO\n";return 0; }
		}
		input.erase(input.begin()+index);
	}
	cout<<"YES\n";
}
