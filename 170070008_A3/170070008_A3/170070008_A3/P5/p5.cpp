#include <iostream>
using namespace std;
void force(int q[], int i, int f[]){
if (i==0) {f[i]=0;return;}
f[i]=0; 
force(q, i-1, f); 
for(int j=0; j<i; j++){
f[j]+= q[j]*q[i]/((i-j)*(i-j));
f[i]-= q[j]*q[i]/((i-j)*(i-j));}
}
int main(){
int n;
cin>>n;
int q[n], f[n];
for(int i=0; i<n; i++) cin>>q[i];
force(q,n-1,f);
for(int i=0; i<n; i++) cout<<f[i]<<" ";
return 0;
}
