#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define NUM 200007

using namespace std;

int main(){
	
	faster
	int n;
	cin>>n;
	
	vi input(n);
	bool present[NUM];
	for(int i=0;i<NUM;i++)present[i] = false;
	
	lld ans = 0;
	for(int i=0;i<n;i++){ cin>>input[i];present[input[i]] = true; }
	sort(input.begin(),input.end());
	
	for(lld i=1;i<NUM;i++){
		if(!present[i])continue;
		lld temp = 0;
		for(lld j=i;j<NUM;j+=i){
			int index1 = lower_bound(input.begin(),input.end(),j)-input.begin();
			int index2 = lower_bound(input.begin(),input.end(),j+i)-input.begin();
			temp += j*(index2-index1);
		}
		ans = max(ans,temp);
	}
	cout<<ans<<'\n';
}
