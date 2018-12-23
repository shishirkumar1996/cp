#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
	string input;
	cin>>input;
	
	string output = "";
	
	int n = input.length();
	int left = 0,right = n-1;
	while(n){
		if(n%2==0) { output += input[right]; right--; }
		else { output += input[left];left++; }
		n--;
	}
	reverse(output.begin(),output.end());
	cout<<output<<'\n';
}
