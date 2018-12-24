#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vs input(n);
	for(int i=0;i<n;i++)cin>>input[i];
	
	int ans = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(int l=i;l<n;l++)
				for(int o = j;o<m;o++){
					int flag = 1;
					for(int x = i;x<=l;x++)
						for(int y = j;y<=o;y++)
							if(input[x][y]=='1') flag = 0;
					if(!flag)continue;
					ans = max(ans,2*((l-i+1)+(o-j+1)));
				}
	cout<<ans<<'\n';
}
