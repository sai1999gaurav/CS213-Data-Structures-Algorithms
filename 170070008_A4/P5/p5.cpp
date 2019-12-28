#include <limits.h> 
#include<iostream>
using namespace std;
 
int minwt(int wt[], bool rem[], int n) 
{ int min = INT_MAX, min_index; 
for (int i = 0; i < n; i++) 
if (rem[i] == false && wt[i] <= min) 
{ min = wt[i]; min_index = i;} 
return min_index; 
} 


void calcsum(int tree[], int n, int* g) 
{ 
int sum=0;
for (int i = 1; i < n; i++) 
	sum+=*((g+i*n) + tree[i]); 
cout<<sum<<endl;
} 

void MST(int *g, int n){
int tree[n]; 
int wt[n];  
bool rem[n]; 
for (int i = 0; i < n; i++) { wt[i] = INT_MAX; rem[i] = false;}
wt[0] = 0;	 
tree[0] = -1; 
for (int count = 0; count < n-1; count++){ 
int i = minwt(wt, rem, n); 
rem[i] = true;
for (int j = 0; j < n; j++) 
if (*((g+i*n) + j) && rem[j] == false && *((g+i*n) + j) < wt[j]) 
tree[j] = i, wt[j] = *((g+i*n) + j); 
} 
calcsum(tree, n,(int*)g); 
} 

int main() 
{ int n;
 cin>>n;
 int g[n][n];
 for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>g[i][j];
MST((int*) g, n); 
return 0; 
} 

