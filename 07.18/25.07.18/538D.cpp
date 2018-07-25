#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vc vector< char >
#define vcc vector< vc >
#define pr pair< int,int >

using namespace std;


int main(){


  faster  
  int n;
  cin>>n;
  
  vcc input(n);
  vector< pr > pieces;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      char a;
      cin>>a;
      input[i].push_back(a);
      if(a == 'o') pieces.push_back(make_pair(i,j));
    }
  
  set< pr > moves;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(input[i][j] == 'x'){
        for(int k=0;k<pieces.size();k++){
          int x = i-pieces[k].first;
          int y = j-pieces[k].second;
          moves.insert(make_pair(x,y));
        }
      }
    }
    
  set< pr > del;  
  for(int i=0;i<pieces.size();i++){
    set< pr >::iterator it;
    for(it = moves.begin();it != moves.end();it++){
//        cout<<(*it).first<<" "<<(*it).second<<endl;
        int flag = 1;
        int r = pieces[i].first+((*it).first);
        int c = pieces[i].second+((*it).second);
        if(r>=0 && r<n && c>=0 && c<n && input[r][c] == '.'){
          del.insert(*it);
        }
    }       
  }
  set< pr >::iterator itx;
  for( itx = del.begin();itx!=del.end();itx++)moves.erase(moves.find(*itx));
  
//  set< pr >::iterator itxy;
//  for(itxy = moves.begin();itxy!=moves.end();itxy++)
//    cout<<(*itxy).first<<" "<<(*itxy).second<<endl;


  for(int i=0;i<pieces.size();i++){
    set< pr >::iterator it;
    for(it=moves.begin();it!=moves.end();it++){
      int r = pieces[i].first +((*it).first);
      int c = pieces[i].second +((*it).second);
      if(r>=0 && r<n && c>=0 && c<n && input[r][c] == '.'){
        cout<<r<<" "<<c<<" "<<(*it).first<<" "<<(*it).second<<endl;
        cout<<"NO"<<endl;return 0;
      }
    }
  }
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(input[i][j] == 'x'){
        int flag = 0;
        set< pr >::iterator it;
        for(it = moves.begin();it!=moves.end();it++){
          int r = i -((*it).first);
          int c = j -((*it).second);
          if(r>=0 && r<n && c>=0 && c<n && input[r][c] == 'o'){
            flag = 1;break;
          }
        }
        if(!flag){cout<<"NO"<<endl;return 0;}
      }
    }
  

  vcc output(2*n-1);
  for(int i=0;i<2*n-1;i++)
    for(int j=0;j<2*n-1;j++) output[i].push_back('.'); 
  
  output[n-1][n-1] = 'o';
  
  set< pr >::iterator it;
  for(it=moves.begin();it!=moves.end();it++){
    int r = n-1 + ((*it).first);
    int c = n-1 +((*it).second);
    if(r>=0 && r<2*n && c>=0 && c<2*n){ 
      output[r][c] = 'x';}
  }
  cout<<"YES"<<endl; 
  for(int i=0;i<2*n-1;i++){
    for(int j=0;j<2*n-1;j++)cout<<output[i][j];
    cout<<endl;
  }

}
