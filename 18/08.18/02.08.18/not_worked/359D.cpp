#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >

using namespace std;

int main(){

  int n;
  cin>>n;
  vi input(n);
  int left[n],right[n]; //left and right seems to be interchanged
  
  for(int i=0;i<n;i++){cin>>input[i];left[i]=right[i]=0;}

  int l = 0,r = 1;
  while(l<n && r<n)
    if(input[r]%input[l]==0){r++;left[l]++;} else{l=r;r++;}
  
  l = n-2;r=n-1;
  while(l>=0 && r>=0)
    if(input[l]%input[r]==0){l--;right[r]++;} else { r=l;l--;}
  
  set< int > output;
  int max=0,max_num = 0;
  for(int i=0;i<n;i++){
    if(left[i]+right[i]==max && !output.count(i-right[i]+1)){
      max_num++;
      output.insert(i-right[i]+1);
    }
    else if(left[i]+right[i]>max){
      output.clear();
      output.insert(i-right[i]+1);
      max=left[i]+right[i];max_num = 1;
    }
  }    

  cout<<max_num<<" "<<max<<endl;
  set< int >::iterator it;
  for(it = output.begin(); it!= output.end();it++){
    cout<<*it<<" ";
  }  
  cout<<endl;
}
