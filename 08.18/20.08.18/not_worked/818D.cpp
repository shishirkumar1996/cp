#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >
#define NUM 1000007

using namespace std;

int main(){

  int n,a;
  cin>>n>>a;
  
  set< pr > ans;
  bool smaller[NUM];
  for(int i=0;i<NUM;i++)smaller[i] = false;
  map< int,int > process;
  
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    ans.erase(make_pair(process[x],x));
    process[x]++;
    if(x==a){
      set< pr >::iterator it;
      for( it = ans.begin();it !=ans.end();it++)
        if((*it).first>=process[a])break;
        else{ smaller[(*it).second] = true;ans.erase(it);}
    } else {
      if(process[x]<=process[a]) smaller[x] = true;
      if(!smaller[x]) ans.insert(make_pair(process[x],x));
    }
  }
  if(!ans.size()){ cout<<-1<<endl;return 0;}
  else cout<<(*(ans.begin())).second<<endl;

}
