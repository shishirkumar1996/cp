#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++) cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;


lld sum(string s){
	int ans = 0;
	for(int i=0;i<s.length();i++)ans += (s[i]-'0');
	return ans;
}

string num(string input,int ind){
	int n = input.length();
	if(input[ind]=='0' || ind==n-1)return input;
	string output = "";
	for(int i=0;i<ind;i++)output += input[i];
	output += (input[ind]-1);
	for(int i=ind+1;i<n;i++) output += '9'; 
	
	return output;
}

int main(){
	string input;
	cin>>input;
	
	int n=input.length();
	
	lld output;
	int maxm = 0;
	for(int i=0;i<n;i++){
		string x = num(input,i); 
		lld s = sum(x);
		if(s>=maxm){ maxm = s; output = stoll(x); }
	}
	cout<<output<<endl;	
}
