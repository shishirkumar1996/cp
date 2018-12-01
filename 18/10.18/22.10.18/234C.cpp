#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  
  ofstream outfile;
  outfile.open("output.txt");
  
  ifstream infile;
  infile.open("input.txt");
  int n;
  infile>>n;  
  int neg[n+1],pos[n+1];
  neg[0] = pos[0] = 0;
  for(int i=1;i<=n;i++){
    neg[i] = neg[i-1];
    pos[i] = pos[i-1];
    lld a;
    infile>>a;
    if(a<0) neg[i]++;
    else if(a>0) pos[i]++;
    else neg[i]++,pos[i]++;
  }
  int ans = INT_MAX;
  for(int i=1;i<n;i++)
    ans=min(ans,pos[i]+(neg[n]-neg[i]));
  outfile<<ans<<endl;
  
  infile.close();
  outfile.close();
}
