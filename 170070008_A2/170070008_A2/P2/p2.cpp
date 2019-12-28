#include <iostream>
using namespace std;
 struct q{
int p,d;
q(){
p=d=0;}
};
int main(){
int n;
cin>>n;
q pp[n];
for(int i=0; i<n; i++)
 cin>>pp[i].p>>pp[i].d;
int sum=0;
int j=0;
while(j < n){
sum=0;
for(int i=0; i<n; i++)
{ sum+=pp[(j+i)%n].p;
 if(pp[(j+i)%n].d<=sum)
  sum-=pp[(j+i)%n].d;
 else
  {sum=-1;
  break;}
}   
if(sum>=0) 
 {cout<<j;
 break;}
else if(sum==-1)
{ ++j;}
}
if(j==n)
 cout<<"-1";
return 0;
}
