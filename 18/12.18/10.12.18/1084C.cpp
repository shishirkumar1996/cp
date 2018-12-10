#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MOD (lld)(1e9+7)

using namespace std;

int main(){

	string input;
	cin>>input;
	
	vi process;
	lld cur = 0;
	for(int i=0;i<input.size();i++){
		if(input[i]=='a')cur++;
		else if(input[i]=='b'){process.push_back(cur);cur  = 0;}
	}
	if(cur)process.push_back(cur);
	
	lld ans = 0;
	for(int i=0;i<process.size();i++)
		ans = (ans+(ans+1)*process[i])%MOD;
	cout<<ans<<'\n';
}
