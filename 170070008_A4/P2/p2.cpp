#include <iostream>
using namespace std;
int med(int a[], int n, int countc){
int m=countc/2;
if(countc%2) return a[n-m-1];
else return (a[n-m]+a[n-m-1])/2;
}
int bs(int a[], int key, int low, int high) 
{  if (high <= low) return (key > a[low])?  (low + 1): low; 
   int mid = (low + high)/2; 
   if(key == a[mid]) return mid+1; 
   if(key > a[mid]) return bs(a, key, mid+1, high); 
   return bs(a, key, low, mid-1); 
} 
  
void inssort(int a[], int n, int countc) 
{ 
    int i, j, k, key; 
  
    for (i = n-countc; i < n; ++i) 
    { 
        j = i - 1; 
        key = a[i];
        k = bs(a, key, n-countc-1, j);
        while (j >= k) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = key; 
    } 
} 
int main(){
int n, countc=0;
cin>>n;
char s[n];
int a[n];
for (int i=0; i<n; i++)
{ cin>>s[i];
if(s[i]=='c'){ int val; cin>>val;
a[n-countc-1]=val;
inssort(a,n,countc);
countc++;
}
else {
cout<<med(a,n,countc)<<endl;
}
}
return 0;
}
