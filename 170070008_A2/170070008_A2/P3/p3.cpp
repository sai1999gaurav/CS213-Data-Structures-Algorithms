#include <iostream>
#include <stack>
using namespace std;
int main(){
int n,i;
cin>>n;
int arr[n], ind[n];
for( i=0; i<n; i++) cin>>arr[i];
for( i=0; i<n; i++) ind[i]=-1;
stack <int> s;
i=0;
while(i<n){
if(s.empty()||arr[s.top()]<=arr[i])
 s.push(i++);
else
 {ind[s.top()]=i;
  s.pop();
 }
}
for( i=0; i<n; i++) cout<<ind[i]<<" ";
return 0;
}
