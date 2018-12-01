#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){


  string input;
  cin>>input;
  if(input.find("BAC") < input.length() || input.find("CAB")<input.length()||input.find("ABC")<input.length()|| input.find("CBA")<input.length()|| input.find("ACB")<input.length()||input.find("BCA")<input.length())
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
