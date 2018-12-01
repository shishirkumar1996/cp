#include<bits/stdc++.h>
#define lld  long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector<int >
#define vii vector< vi >

using namespace std;

int main(){

  int n;
  cin>>n;
  
  vi input(n);
  int add = 0;
  for(int i=0;i<n;i++){cin>>input[i];add+=input[i];}
  
  int ans[2000][add];
  for(int i=0;i<200;i++)for(int j=0;j<add;j++) ans[i][j] = 0;
  
  int cur_row = 1000,cur_col =0;
  int max_ind = cur_row,min_ind = cur_row;
  
  for(int i=0;i<n;i++){
    if(i%2==0){
      
      ans[cur_row][cur_col] = 1;
      max_ind = max(cur_row,max_ind);
      cur_col++;
      for(int j=1;j<input[i];j++){
        cur_row++;
        max_ind = max(cur_row,max_ind);
        ans[cur_row][cur_col] = 1;
        cur_col++;
      }
    } else{
      ans[cur_row][cur_col] = -1;
      min_ind = min(cur_row,min_ind);
      cur_col++;
      for(int j=1;j<input[i];j++){
        cur_row--;
        min_ind = min(cur_row,min_ind);
        ans[cur_row][cur_col] = -1;
        cur_col++;
      }
    }
  }
  
  for(int i=max_ind;i>=min_ind;i--){
    for(int j=0;j<add;j++){
      if(ans[i][j] == 1) cout<<"/";
      else if(ans[i][j]==-1) cout<<"\\";
      else cout<<" ";
    }
    cout<<endl;
  }


}
