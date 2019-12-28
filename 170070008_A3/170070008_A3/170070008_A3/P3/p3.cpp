#include <iostream>
#include <string>
using namespace std;
string comm( string p1, string p2){
string p;
int i=0;
while (i<p1.length() && i<p2.length())
{ if (p1[i]==p2[i]){
   p.push_back(p1[i]); ++i;} 
  else
   break;
}
return p;
}
string pref(string s[], int l, int r){
string p1, p2;
int m = (l+r)/2;
if(l < r){
p1= pref(s, l, m);
p2= pref(s, m+1, r);
return comm(p1, p2);
}
return s[l];
}
int main(){
int n;
cin>>n;
string s[n], p;
for(int i=0; i<n; i++) cin>>s[i];
p=pref(s,0,n-1);
if(p.length()) cout<<p;
else cout<<"-1";
return 0;
}
