#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 5007

using namespace std;

int ans[NUM][NUM];
bool pal[NUM][NUM];

int main(){

  faster
  string input;
  cin>>input;
  int n = input.length();
  int l,r;
  input = " "+input;
  
  for(int i=0;i<=n;i++)for(int j=i;j<=n;j++){ 
    ans[i][j] = 0; pal[i][j] = false;
  }
  
  for(int l=1;l<=n;l++){
    for(int i=1;i<=n-l+1;i++){
      int j = i+l-1;
      if(l==1||(l==2 && input[i]==input[j])){ 
        pal[i][j] = true;ans[i][j] = 1;
      } else {
          if(input[i]==input[j] && pal[i+1][j-1]){
            pal[i][j] = true;ans[i][j] = 1;
          }
      }
      if(i+1<=j) ans[i][j] += ans[i+1][j];
      if(i<=j-1) ans[i][j] += ans[i][j-1];
      if(i+1<=j-1) ans[i][j] -= ans[i+1][j-1];
    }
  }
  
  int q;
  cin>>q;
  for(int i=1;i<=q;i++){
    cin>>l>>r;
    cout<<ans[l][r]<<endl;
  }
}
