#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  char process[26];
  for(int i=0;i<26;i++)cin>>process[i];
  
  int k;
  cin>>k;
  int n = input.size();
  set< string > output;
  for(int i=0;i<n;i++){
    int num = 0;
    for(int j=i;j<n;j++){
      string temp = input.substr(i,j-i+1);
      if(process[input[j]-'a']=='0') num++;
      if(num>k)break;
      output.insert(temp);
    }
  }
  cout<<(int)(output.size())<<endl;
}
