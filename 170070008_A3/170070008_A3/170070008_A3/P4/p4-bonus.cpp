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
switch(match(s[n/3], p)){ 
case 0: c++; // p >s[n/3]: g a so c++
	
	if(match(s[2*n/3],p)==0){ i=(2*n/3 +1);  
        	if(match(s[8*n/9], p)==1) { cout<<8*n/9<<endl;} // 1st bad access
        	else if(match(s[8*n/9], p)==0) // g a so c++
		{ c++;
                 i=8*n/9+1;
		while(i<n) {			
		if(s[i]==p) { f=0; cout<<i<<endl;break;} //1st bad access		
                ++i; ++c; // g a 
                } if(i==n && f) {cout<<"-1"<<endl;}
 		}
	 	else if(match(s[7*n/9],p)==1) { cout<<7*n/9<<endl;} //end at (2+1)th bad access 
		else if(match(s[7*n/9],p)==0) // g a so c++
 		{ c++;
		  i=7*n/9 +1;
                 while(i<8*n/9){        
		if(s[i]==p) { f=0; cout<<i<<endl;break;} // end at (2+1)th bad access		
                ++i;++c;}if(i==8*n/9 && f) { cout<<"-1"<<endl; }
		}
 		else { i= 2*n/3+1;
		while(i<7*n/9) {
		if(s[i]==p) {f=0; cout<<i<<endl;break;}	//	end at (2+1)th bad access
                ++i; ++c;} if(i==7*n/9 && f) { cout<<"-1"<<endl;}		
		} 
		}
	else if(match(s[2*n/3],p)==1){ cout<<2*n/3<<endl;}
	else{ //1st b a over
		if(match(s[5*n/9], p)==1) { cout<<5*n/9<<endl; } // 2nd ba..done
        	else if(match(s[5*n/9], p)==0) //s[5*n/9] < p
		{c++;  //ga 
                 i=5*n/9+1;
                 while(i<2*n/3){
		if(s[i]==p) { f=0; cout<<i<<endl;break;} // end at (1+1)th bad access		
                ++i;++c;}if(i==2*n/3 && f) { cout<<"-1"<<endl; }
		} // other case remaining (match(s[2*n/9], p)==2) intuitively done..2nd ba over
 	      else if(match(s[4*n/9],p)==1) { cout<<4*n/9<<endl; } //end at (2+1)th bad access 
		else if(match(s[4*n/9],p)==0) // g a so c++
 		{ c++;
		  i=4*n/9 +1;
                 while(i<5*n/9){        
		if(s[i]==p) { f=0; cout<<i<<endl;break;} // end at (2+1)th bad access		
                ++i;++c;}if(i==5*n/9 && f) { cout<<"-1"<<endl; }
		}
 		else { i= n/3+1;
		while(i<4*n/9) {
		if(s[i]==p) {f=0; cout<<i<<endl;break;}	//	end at (2+1)th bad access
                ++i; ++c;} if(i==4*n/9 && f) { cout<<"-1"<<endl;}		
		}
		}
       break;
   
case 1: cout<<n/3<<endl; //1st bad access
	break;
case 2: //1st bad acess p<s[n/2]: 1 more ba possible but must be found at atmax 3rd ba
	if(match(s[2*n/9], p)==1) { cout<<2*n/9<<endl; break;} // 2nd ba..done
        else if(match(s[2*n/9], p)==0) //s[2*n/9] < p
		{c++;  //ga 
                 i=2*n/9+1;
                 while(i<n/3){
		if(s[i]==p) { f=0; cout<<i<<endl;break;} // end at (1+1)th bad access		
                ++i;++c;}if(i==n/3 && f) { cout<<"-1"<<endl; break;}
		} // other case remaining (match(s[2*n/9], p)==2) intuitively done..2nd ba over
       else if(match(s[n/9],p)==1) { cout<<n/9<<endl; break;} //end at (2+1)th bad access 
	else if(match(s[n/9],p)==0) // g a so c++
 		{ c++;
		  i=n/9 +1;
                 while(i<2*n/9){        
		if(s[i]==p) { f=0; cout<<i<<endl;break;} // end at (2+1)th bad access		
                ++i;++c;}if(i==2*n/9 && f) { cout<<"-1"<<endl; break;}
		}
 	else {while(i<n/9) {
		if(s[i]==p) {f=0; cout<<i<<endl;break;}	//	end at (2+1)th bad access
                ++i; ++c;} if(i==n/9 && f) { cout<<"-1"<<endl; break;}		
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
else if(n==2){ if(match(s[0],p)==1) cout<<"0"<<endl<<"0"; //0 good access
else if(match(s[0],p)==2) cout<<"-1"<<endl<<"0"; //1st bad access
else if(match(s[1],p)==1) cout<<"1"<<endl<<"1"; // 2nd bad access but 1 good with s[0]
else if(match(s[1],p)==0) cout<<"-1"<<endl<<"2";}// 2 bad, 2 good
else {search(s,n,p);
cout<<c;}
return 0;
}

