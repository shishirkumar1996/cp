#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){
	
	string s,t;
	int num_s[26],num_t[26];
	vi temp;
	cin>>s>>t;
	int new_s[26];
	for(int i=0;i<26;i++)num_s[i] = num_t[i] = 0;
	
	int unk = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='?')unk++;
		else num_s[s[i]-'a']++;
	}
	for(int i=0;i<t.length();i++)num_t[t[i]-'a']++;
	for(int i=0;i<26;i++)new_s[i] = num_s[i];
	int minm = INT_MAX;
	for(int i=0;i<26;i++)if(num_t[i]){ 
		temp.push_back(i);
		minm = min(minm,num_s[i]/num_t[i]);
	}
	
	while(unk){
		for(int i=0;i<temp.size();i++){
			int x = min(max(0,(minm+1)*num_t[temp[i]]-new_s[temp[i]]),unk);
			new_s[temp[i]] += x;
			unk -= x;
		}
		minm++;
	}
	for(int i=0;i<26;i++) new_s[i] -= num_s[i];	
	
	int index = 0;
	for(int i=0;i<temp.size();i++){
		for(int j=1;j<=new_s[temp[i]];j++){
			while(s[index] != '?')index++;
			s[index] = 'a'+temp[i];	
		}
	}
	cout<<s<<'\n';
}
