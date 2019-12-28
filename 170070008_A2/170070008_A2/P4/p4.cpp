#include <iostream>
#include<stack>
using namespace std;

int main(){
int n,i;
cin>>n;
int a[n];
for( i=0; i<n; i++) cin>>a[i];
int sum, prev=a[0], max=0;
stack <int> s;
i=0;
while(i<n){
if(s.empty() || a[s.top()]<=a[i])
  s.push(i++);
else{
 prev=s.top();
 s.pop();
 if(s.empty())
  sum=i*a[prev];
 else
  sum=(i-s.top()-1)*a[prev];
 if(sum>max) max=sum;
}
}
while(!s.empty()){
prev=s.top();
 s.pop();
 if(s.empty())
  sum=i*a[prev];
 else
  sum=(i-s.top()-1)*a[prev];
 if(sum>max) max=sum;
}
cout<<max;
return 0;
}




























