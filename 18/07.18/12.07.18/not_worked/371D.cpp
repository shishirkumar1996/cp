#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  set< int > process;
  vi input(n+1),cur(n+1);
  for(int i= 1;i<=n;i++){
    cin>>input[i];
    cur[i] = 0;
    process.insert(i);
  }
 
  
  int m;
  cin>>m;
  for(int i=1;i<=m;i++){
    int t;
    cin>>t;
    if(t==2){
      int v;
      cin>>v;
      cout<<cur[v]<<endl;
    }
    else{
      int v; lld left;
      cin>>v>>left;
      set< int >::iterator it =  lower_bound(process.begin(),process.end(),v);
      while(left){
//        cout<<left<<endl;
        if(it==process.end()) break;
        int y = *it;
        lld temp = cur[y];
        cur[y]  = min(cur[y]+left,input[y]);
        left = max(0ll,left-(input[y]-temp));
//        cout<<y<<" "<<cur[y]<<" "<<input[y]<<" "<<left<<endl;
        it++;
        if(cur[y] == input[y]) process.erase(process.find(y));
        
      }
    }
  }
}
