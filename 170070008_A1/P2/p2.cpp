#include <iostream>
using namespace std;
int main(){
int n,s,num=0;
cin>>n;
int a[n],b[n];
for(int i=0; i<n; i++) {
cin>>a[i];
b[i]=1;
for(int j=0; j<=i; j++){
 if(a[j]==a[i]){
  ++b[j];
  if(b[j]>num) {num=b[j];
  s=j;}
  break;
}
}
}
if((num-1)>(n/2))
 cout<<a[s];
else
 cout<<"-1";
return 0;
}
