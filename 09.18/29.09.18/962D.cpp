#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vi input(n);
  map< lld,set< int > > process;
  set< lld > temp;
  
  for(int i=0;i<n;i++){
    cin>>input[i];
    process[input[i]].insert(i);
    temp.insert(input[i]);
  }
  
  map< lld,set< int > >::iterator it;
  vector< pair< int,lld > >output;
  for( it= process.begin();it != process.end();it++){
    lld num = it->first;
    while(process[num].size()>=2){
      process[num].erase(process[num].begin());
      int x = *process[num].begin();
      process[num].erase(process[num].begin());
      process[2*num].insert(x);
      temp.insert(2*num);
    }
    if(!process[num].size())temp.erase(temp.find(num));
    else output.push_back(make_pair(*process[num].begin(),num));
  }
  sort(output.begin(),output.end());
  cout<<output.size()<<endl;
  for(int i=0;i<output.size();i++)cout<<output[i].second<<" ";
  cout<<endl;
}

