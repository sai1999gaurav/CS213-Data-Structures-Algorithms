#include <iostream>
using namespace std;

int main(){
 int n,s=0,f;
cin>>n;
long int l[n];
int a=n,i=0;
while(cin>>l[i] && n>=0){
f=1;
for(int j=s; j<i; j++)
{if(j>=(i-l[i]) && l[j]>=0)
{--a;
 l[j]=-1;
if (f)
 ++s;
}
else
f=0;
}
++i;
--n;
}
cout<<a;
return 0;	
}
