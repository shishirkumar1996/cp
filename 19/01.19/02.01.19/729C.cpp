#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" "<<;cerr<<'\n'; }

using namespace std;

string fun(string input,int del,int num){
	
	int x = 0;
	for(int i=input.size()-1;i>=0;i--){
		if((input[i]-'0')%3 != del)continue;
		input.erase(i,1);
		x++;
		if(x==num)break;
	}
	while(input.size()>1 && input[0]=='0')input.erase(0,1);
	return input;
}

int main(){
	string input;
	cin>>input;
	
	int n = input.size();
	int sum[3];
	sum[0] = sum[1] = sum[2] = 0;
	
	int total = 0;
	for(int i=0;i<n;i++){
		sum[(input[i]-'0')%3]++;
		total = (total+(input[i]-'0'))%3;
	}
	if(total==0){
		cout<<input<<endl;return 0;
	} else if(total==1){
		string out = "";
		if(n>2 && sum[2]>=2){
			string x = fun(input,2,2);
			if(x.size()>out.size())out = x;
		}
		if(n>1 && sum[1]>=1){
			string x = fun(input,1,1);
			if(x.size()>out.size())out = x;
		}
		if(!out.size())cout<<-1<<endl; else cout<<out<<endl;
	} else if(total==2){
		string out = "";
		if(n>1 && sum[2]>=1){
			string x = fun(input,2,1);
			if(x.size()>out.size())out = x;
		}
		if(n>2 && sum[1]>=2){
			string x = fun(input,1,2);
			if(x.size()>out.size())out = x;
		}
		if(!out.size())cout<<-1<<endl; else cout<<out<<endl;
	}
}
