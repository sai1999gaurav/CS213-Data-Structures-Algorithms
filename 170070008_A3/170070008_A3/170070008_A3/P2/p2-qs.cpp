#include <iostream>
using namespace std;
int part(int a[], int l, int r){
int k=a[r], i=l-1, temp;
for(int j=l;j<r; j++)
 if(a[j]<=k)
	{ i++;
          temp=a[i];
          a[i]=a[j];
	  a[j]=temp;
	}
temp=a[i+1];
a[i+1]=a[r];
a[r]=temp;
return i+1;
}
void quicksort(int a[], int l, int r){
int p;
if(l<r){
p=part(a,l,r);
quicksort(a,l,p-1);
quicksort(a,p+1,r);
}
}

int main(){
int n;
cin>>n;
int a[n];
for(int i=0; i<n; i++) cin>>a[i];
quicksort(a,0,n-1);
for(int i=0; i<n; i++) cout<<a[i]<<" ";
return 0;
}
