#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld, lld >
#define vp vector< pr >

using namespace std;

int main(){

  lld n;
  cin>>n;
  
  vp input(n);
  for(int i = 0;i<n;i++){
    lld a;
    cin>>a;
    input[i] = make_pair(a,i+1);
  }
 
  sort(input.begin(),input.end());
  
  string process;
  cin>>process;
  
  set< pr > output;
  
  int intr_index=0;
  for(int i = 0;i<2*n;i++){
    if(process[i] == '0'){
      cout<<input[intr_index].second<<" ";
      output.insert(make_pair(-input[intr_index].first,input[intr_index].second));
      intr_index++;

    }
    else{
      lld top = (*output.begin()).second;
      output.erase(output.begin());
      cout<<top<<" ";
    }
  }
  cout<<endl;

}
