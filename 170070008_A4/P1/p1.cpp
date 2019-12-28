#include <iostream>
#include <stack>
using namespace std;
int main(){
int n;
cin>>n;
int a[n], sum=0, prev=0, count=0;
for(int i=0; i<n; i++)
{cin>>a[i];
 if(a[i]==1) {
	count++;
	sum = (-1>sum-1)? -1: sum-1;
	prev= (prev>sum)? prev:sum;
		}
  else{ sum = (1>sum+1)? 1: sum+1;
	prev= (prev>sum)? prev:sum;
       }
prev = (0>prev)? 0:prev;
}
cout<<count+prev<<endl;
return 0;
}

















