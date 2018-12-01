#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define fr(i,a,b) for(int i=a;i<b;i++)
#define br(i,a,b) for(int i=(b-1);i>=a;i--)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr << a[_] << ' '; cerr <<'\n'; }
//#define TM

using namespace std;

int main(){

  faster
  string input;
  cin>>input;
  char process[26];
  for(int i=0;i<26;i++)cin>>process[i];
  
  int k;
  cin>>k;
  int n = input.size();
  int sum[n+1];
  sum[0] = 0;
  for(int i=1;i<=n;i++) sum[i] = sum[i-1]+(process[input[i-1]-'a']=='0'?1:0);
  
  int ans = 0;
  for(int l=1;l<=n;l++){
    unordered_set< string > output;
    for(int i=1;i<=n-l+1;i++){
      if(sum[i+l-1]-sum[i-1]<=k)
      output.insert(input.substr(i-1,l));
    }
    ans += output.size();
  }
  cout<<ans<<endl;
  
  #ifdef TM
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
}
