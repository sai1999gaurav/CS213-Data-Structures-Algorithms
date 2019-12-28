#include <iostream>
#include <string>
using namespace std;
int match(string q,string p){
int i=0;
if(p==q) return 1;
else
while(i<p.length() && i<q.length()){
 if(p[i]!=q[i]) return q[i]<p[i]?0:2;
 i++;
}
}

int c=0;

void search(string s[], int n, string p){
 int i=0, f=1;
switch(match(s[n/2], p)){ 
case 0: c++; // p >s[n/2]: g a so c++
        i=(n/2 +1);  
        if(match(s[3*n/4], p)==1) { cout<<3*n/4<<endl; break;} // 1st bad access
        else if(match(s[3*n/4], p)==0) // g a so c++
		{ c++;
                 i=3*n/4+1;
		while(i<n) {			
		if(s[i]==p) { f=0; cout<<i<<endl;break;} //1st bad access		
                ++i; ++c; // g a 
                } if(i==n && f) {cout<<"-1"<<endl; break;}
 		}
		
         else { // p<s[3n/4]
                while(i<3*n/4){
		if(s[i]==p) { f=0; cout<<i<<endl;break;} //1st bad 	
                ++i; ++c;}
		 if(i==3*n/4 && f) { cout<<"-1"<<endl; break;}		
		}
          break;
   
case 1: cout<<n/2<<endl; //1 bad access
	break;
case 2: //1st bad acess p<s[n/2]
	if(match(s[n/4], p)==1) { cout<<n/4<<endl; break;}
        else if(match(s[n/4], p)==0) 
		{c++;  //ga 
                 i=n/4+1;
                 while(i<n/2){
		if(s[i]==p) { f=0; cout<<i<<endl;break;} // end at (1+1)th bad access		
                ++i;++c;}if(i==n/2 && f) { cout<<"-1"<<endl; break;}
		
		}
         else {while(i<n/4) {
		if(s[i]==p) {f=0; cout<<i<<endl;break;}	//	end at (1+1)th bad access
                ++i; ++c;} if(i==n/4 && f) { cout<<"-1"<<endl; break;}		
		} break;
}
}

int main(){
int n;
cin>>n;
string s[n], p;
for(int i=0; i<n; i++) cin>>s[i];	
cin>>p;
if(n==1) {if(match(s[0],p)==1) cout<<"0"<<endl<<"0";
else if(match(s[0],p)==0) cout<<"-1"<<endl<<"1";
else cout<<"-1"<<endl<<"0";}
else {search(s,n,p);
cout<<c;}
return 0;
}
 
