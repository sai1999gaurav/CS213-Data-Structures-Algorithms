#include <iostream>
using namespace std;
void merge(int a[], int l, int m, int r){
int i, j, k=l, lt[m-l+1], rt[r-m];
for(i=0; i<=m-l; i++)
 lt[i]=a[l+i];
for(j=0;j<r-m; j++)
 rt[j]=a[m+j+1];
i=j=0;
while (i<=m-l && j< r-m)
{if(lt[i]<rt[j])
	{ a[k]=lt[i];
          ++i;
 	  ++k;
         }
 else{ a[k]=rt[j];
       ++j;
       ++k;
	}
}
while(i<=m-l)
{a[k]=lt[i];
          ++i;
 	  ++k;
}
while(j<r-m)
{a[k]=rt[j];
       ++j;
       ++k;
}
}
void mergesort(int a[], int l, int r){
int m=(l+r)/2;
if( l < r){
mergesort(a,l,m);
mergesort(a,m+1,r);
merge(a,l,m,r);
}
}

int main(){
int n;
cin>>n;
int a[n];
for(int i=0; i<n; i++) cin>>a[i];
mergesort(a,0,n-1);
for(int i=0; i<n; i++) cout<<a[i]<<" ";
return 0;
}
