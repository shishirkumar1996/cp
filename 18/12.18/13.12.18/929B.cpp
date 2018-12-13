#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define pr pair< int,int >
#define ppr pair< int, pr >
#define vppr vector< ppr >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){
	
	int n,k;
	cin>>n>>k;
	vppr process;
	vector< string > input(n);
	int ans = 0;
	for(int i=0;i<n;i++){
		cin>>input[i];
		for(int j=0;j<input[i].size();j++){
			if(input[i][j]=='.'){
				int num = 0;
				if(j>0 && input[i][j-1]=='S')num++;
				if(j<input[i].size()-1 && input[i][j+1]=='S')num++;
				process.push_back(make_pair(num,make_pair(i,j)));
			} else if(input[i][j]=='S'){
				if(j>0 && (input[i][j-1]=='P'||input[i][j-1]=='S'))ans++;
				if(j<input[i].size()-1&&(input[i][j+1]=='P'||input[i][j+1]=='S'))ans++;
			}
		}
	}
	sort(process.begin(),process.end());
	for(int i=0;i<k;i++){
		input[process[i].second.first][process[i].second.second] = 'x';
		ans += process[i].first;
	}
	cout<<ans<<'\n';
	for(int i=0;i<n;i++)cout<<input[i]<<'\n';

}
