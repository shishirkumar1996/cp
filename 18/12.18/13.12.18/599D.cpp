#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< lld,lld >
#define vp vector< pr >

using namespace std;

int main(){
	
	lld x;
	cin>>x;
	
	vp output;
	for(lld i=1;i<=min(x,(lld)(2e6));i++){
		lld j = (x-((i*(i+1)*(2*i+1))/6));
		if(j%((i*(i+1))/2)!=0)continue;
		j =  j/((i*(i+1))/2)+i;
		if(j<i)continue;
		output.push_back(make_pair(i,j));
		if(i!=j)output.push_back(make_pair(j,i));
	}
	sort(output.begin(),output.end());
	cout<<output.size()<<'\n';
	for(int i=0;i<output.size();i++)cout<<output[i].first<<" "<<output[i].second<<'\n';
}
