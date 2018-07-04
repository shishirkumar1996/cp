#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;


vi lps,first_pat,second_pat;

void compute_lps(){

  int len = 0;
  lps[0] = 0;
  
  int i = 1;
  while(i<second_pat.size()){
    if(second_pat[i] == second_pat[len]){len++;lps[i] = len;i++;}
    else {
      if(len){ len = lps[len-1];}
      else { lps[i] = 0;i++;}
    }
  }
}

int main(){

  int n,w;
  cin>>n>>w;
  
  vi first_inp(n),second_inp(w);
  for(int i = 0;i<n;i++) cin>>first_inp[i];
  for(int i=0;i<w;i++) cin>>second_inp[i];
  
  if(w==1){cout<<n<<endl;return 0;}
  
  for(int i =1;i<n;i++){first_pat.push_back(first_inp[i]-first_inp[i-1]);}
  for(int i =1;i<w;i++){second_pat.push_back(second_inp[i]-second_inp[i-1]);}
  
  lps.resize(second_pat.size());
  compute_lps();
  int x = first_pat.size(),y = second_pat.size();
  int i = 0,j=0;
  int ans = 0;
  while(i<x){
    if(second_pat[j] == first_pat[i]) { j++;i++;}
    if(j== y){ans++;j = lps[j-1];}
    else if(i< x &&  second_pat[j] != first_pat[i]){
      if(j != 0) j = lps[j-1];
      else i++;
    }
  }
  cout<<ans<<endl; 

}
