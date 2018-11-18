#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  int n = input.length();
  int row = (n+19)/20;
  int col = (n+row-1)/row;
  int common = (row*col-n)/row;
  int extra = (row*col-n)%row;
  
  cout<<row<<" "<<col<<'\n';
  int index = 0;
  for(int i=0;i<row;i++){
    int j;
    for(j=0;j<common;j++)cout<<'*';
    if(extra){ cout<<'*'; extra--; j++; }
    for(;j<col;j++){
      cout<<input[index];index++;
    }
    cout<<'\n';
  }

}
