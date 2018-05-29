#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;


int main(){

  faster
  map<string,int> process;
  process["purple"] = 0;
  process["green"] = 1;
  process["blue"] = 2;
  process["orange"] = 3;
  process["red"] = 4;
  process["yellow"] = 5;
  int present[6];
  for(int i= 0;i<6;i++) present[i] = 0;
  
  map< int,string > type;
  type[0] = "Power";
  type[1] = "Time";
  type[2] = "Space";
  type[3] = "Soul";
  type[4] = "Reality";
  type[5] = "Mind";
  
  int n;
  cin>>n;
  int count = 6;
  for(int i = 0;i<n;i++){
    string s;
    cin>>s;
    present[process[s]] = 1;
    count--;
  }

  cout<<count<<endl;
  for(int i =0;i<6;i++)
    if(!present[i]) cout<<type[i]<<endl;
  

}
