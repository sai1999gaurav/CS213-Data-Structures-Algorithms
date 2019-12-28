#include <iostream>
using namespace std;

int main(){
int n,i,j=0;
cin>>n;
int a[n];
for(i=0; i<n; i++)
cin>>a[i];
i=0;
while(i<n)
 { 
    if(((a[i]-j)<=0) && (i==(j%n)))
       {cout<<i+1;
       break;}
  ++i;
  ++j;
  if(i==n)
   i=0;
  }

return 0;	
}
