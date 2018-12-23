#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define vp vector< pr >

using namespace std;



int main(){
	
	faster
	pr x[3];
	for(int i=0;i<3;i++)cin>>x[i].first>>x[i].second;
	
	bool touched[1002][1002];
	for(int i=0;i<1002;i++)for(int j=0;j<1002;j++)touched[i][j] = false;
	sort(x,x+3);
	
	lld minm_y=INT_MAX,maxm_y=INT_MIN;
	for(int i=0;i<3;i++){
		minm_y = min(minm_y,x[i].second);
		maxm_y = max(maxm_y,x[i].second);
	}
	vp sol;
	for(int i=minm_y;i<=maxm_y;i++) 
		sol.push_back(make_pair(x[1].first,i));
	
	for(int i=x[0].first;i<x[1].first;i++) 
		sol.push_back(make_pair(i,x[0].second));
	
	for(int i=x[2].first;i>x[1].first;i--)
		sol.push_back(make_pair(i,x[2].second));
	
	cout<<sol.size()<<'\n';
	for(int i=0;i<sol.size();i++)cout<<sol[i].first<<" "<<sol[i].second<<'\n';
}
