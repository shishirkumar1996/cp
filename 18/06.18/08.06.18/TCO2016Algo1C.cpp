#include<bits/stdc++.h>
#include<string>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);


using namespace std;

class SumFullSet{

  public:
  
    string isSumFullSet(vector<int> elements){
      
      sort(elements.begin(),elements.end());
      for(int i=0;i<elements.size();i++)
        for(int j= i+1;j<elements.size();j++){
          int index = lower_bound(elements.begin(),elements.end(),elements[i]+elements[j])-elements.begin();
          if(index==elements.size() || elements[index] != elements[i]+elements[j])  return "not closed";
        }
        return "closed";
    }

};


int main(){
  vector<int> elements(1);
  for(int i = 0;i<elements.size();i++)cin>>elements[i];
  
  
  SumFullSet s;
  cout<<s.isSumFullSet(elements)<<endl;

}
