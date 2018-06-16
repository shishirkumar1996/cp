#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >


using namespace std;

string calc(int n,vi input, string swap){
  
  vi process(n);
  process[0] = 0;
  for(int i =1;i<n;i++)
    process[i] = process[i-1]+((swap[i-1]== '1')?1:0);

  for(int i = 0;i<n;i++){
    int num = input[i]-1;
    if(num>i){
      if(process[num]-process[i] != num-i) return "NO";
    }
  }
  return "YES";

}

int main(){
  int n;
  cin>>n;
  vi input(n);
  string swap;
  for(int i = 0;i<n;i++)
    cin>>input[i];
    cin>>swap;
    
  cout<<calc(n,input,swap)<<endl;
}
