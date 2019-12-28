#include <iostream>
using namespace std;


int main(){
int n,x, num=0;
cin>>n>>x;
int a[n];
for(int i=0; i<n; i++) {
cin>>a[i];
if(a[i]==x)
   ++num;
}
if(num>(n/2))
 cout<<"1";
else
 cout<<"0";
return 0;
}
