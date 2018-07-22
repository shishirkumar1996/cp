#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >


using namespace std;

int main(){

  int n;
  cin>>n;
  
  multiset< int > input;
  int ans =0;
  for(int i=0;i<2*n-1;i++){
    int a;
    cin>>a;
    input.insert(a);
    ans += a;
  }
  
  while(true){
    cout<<ans<<endl;
    int x[n];
    int temp = 0;
    for(int i=0;i<n;i++){
      x[i] = *input.begin();
      temp += x[i];
      input.erase(input.begin());
    }
    if(temp>=0) break;
    ans -= 2*temp;
    for(int i=0;i<n;i++) input.insert(-x[i]);
  }
  cout<<ans<<endl;
}
