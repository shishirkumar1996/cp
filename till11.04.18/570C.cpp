#include<bits/stdc++.h>


using namespace std;


int main(){

  int n,m;
  cin>>n>>m;
  string input;
  cin>>input;
  int answer = 0,counter = 0;
  for(int i = 0;i<input.size();i++)
  {
    if(input[i] != '.'){
      answer+= (counter > 0)?(counter-1):0;
      counter = 0;
    }
    else
    if(input[i] == '.')
      counter++;
  }
  answer+= (counter >0)?(counter-1):0;
//  cout<<counter<<" "<<answer<<endl;  
    
  for(int i = 0;i<m;i++){
    int num;
    char insert;
    cin>>num>>insert;
    num--;
    if(insert == '.' && input[num] != '.'){
      if(num > 0 && input[num-1] == '.')
        answer++;
      if(num < n-1 && input[num+1] == '.')
        answer++;
    }
    else if(insert != '.' && input[num] == '.'){
      if(num > 0 && input[num-1] == '.')
        answer--;
      if(num < n-1 && input[num+1] == '.')
        answer--;
    }
    input[num] = insert;
  
    cout<<answer<<endl;
  }

}
