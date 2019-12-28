#include <iostream>
using namespace std;
int f(int a[], short t[], int i, int k){
int p=0;
for(int j=i; j<=i+k-1; j++)
{if (t[j]==0)
 p+=a[j];
}
return p;
}
int main(){
int n,k,s=0,max=0,r;
cin>>n>>k;
int a[n];
short t[n];
for(int i=0; i<n; i++)
cin>>a[i];
for(int i=0; i<n; i++)
{ cin>>t[i];
if(t[i]==1)
s+=a[i];
}
for(int i=0; i<=n-k; i++)
if(t[i]==0 || i==n-k)
 { r=f(a,t,i,k);
   if(r>=max)
     max=r;
  }
cout<<s+max;
return 0;	
}
