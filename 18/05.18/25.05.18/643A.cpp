#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;


int main(){
  faster
  int n;
  cin>>n;
  vi input(n+1);
  for(int i =1;i<=n;i++) cin>>input[i];
  
  int ans[n+1];
  for(int i =0;i<=n;i++)ans[i] = 0;
  
  for(int i = 1;i<=n;i++){
    int cnt[n+1];
    memset(cnt,0,sizeof(cnt));
    
    int max = -1,max_num;
    for(int j = i;j<=n;j++){
      cnt[input[j]]++;
      if(cnt[input[j]]>max||(cnt[input[j]]==max && input[j]<max_num))
        max = cnt[input[j]],max_num = input[j];
      ans[max_num]++;
    }
  }
  
  for(int i = 1;i<=n;i++)cout<<ans[i]<<" ";
  cout<<endl;

}
