#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

class FindingFriend{
  
  public: 
  int find(int roomsize,vi leaders,int friendplace){
    sort(leaders.begin(),leaders.end());
    reverse(leaders.begin(),leaders.end());
    
    int ans = 0;
    for(int i=  0;i<leaders.size();i++){
      if(leaders[i]>friendplace)continue;
      
      if(leaders[i]==friendplace)return 1;
      ans++;
        if(roomsize*leaders.size()-(i+1)*roomsize+1 == leaders[i])
        return ans;
    }
  }
};


int main(){
  FindingFriend a;
  int roomsize;
  vi leaders(5);
  int friendplace;
  cin>>roomsize;
  for(int i = 0;i<leaders.size();i++) cin>>leaders[i];
  cin>>friendplace;
  
  
  cout<<a.find(roomsize,leaders,friendplace)<<endl;


}
