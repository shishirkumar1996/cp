#include<bits/stdc++.h>
#define cd complex< double >
#define vcd vector< cd >

using namespace std;

vcd fft(vcd a){

  int n= a.size();
  if(n==1)return vcd(1,a[0]);
  
  vcd w(n); // for storing n complex nth roots of unity
  for(int i=0;i<n;i++){
    double alpha = 2*M_PI*i/n;
    w[i] = cd(cos(alpha),sin(alpha));
  }
  
  vcd A0(n/2),A1(n/2);
  for(int i=0;i<n/2;i++){A0[i] = a[i*2];A1[i] = a[i*2+1];}
  
  vcd y0 = fft(A0); //even indexed coefficients
  vcd y1 = fft(A1); //odd indexed coefficients
  
  vcd y(n);
  for(int k=0;k<n/2;k++){
    y[k] = y0[k]+w[k]*y1[k];
    y[k+n/2] = y0[k]-w[k]*y1[k];
  }
  return y;
}

vcd inv_fft(vcd a){
  int n= a.size();
  if(n==1)return vcd(1,a[0]);
  
  vcd w(n); // for storing n complex nth roots of unity
  for(int i=0;i<n;i++){
    double alpha = 2*M_PI*i/n;
    w[i] = conj(cd(cos(alpha),sin(alpha)));
  }
  
  vcd A0(n/2),A1(n/2);
  for(int i=0;i<n/2;i++){A0[i] = a[i*2];A1[i] = a[i*2+1];}
  
  vcd y0 = inv_fft(A0); //even indexed coefficients
  vcd y1 = inv_fft(A1); //odd indexed coefficients
  
  vcd y(n);
  for(int k=0;k<n/2;k++){
    y[k] = (y0[k]+w[k]*y1[k])*(1.0/n);
    y[k+n/2] = (y0[k]-w[k]*y1[k])*(1.0/n);
  }
  return y;
  
}


int main(){
  
  vcd a{1,2,3,4};// 4*x^4+3*x^2+2*x+1
  vcd b = fft(a);
  for(int i=0;i<4;i++) cout<<b[i]<<endl;  
  vcd c = inv_fft(b);
  for(int i=0;i<4;i++)cout<<c[i]<<endl;
  return 0;
}
