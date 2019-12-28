#include <iostream>
#include <string>
using namespace std;
class stk{
public:
 string str[1000];
 int n;
 int top;
 stk(){
    n=0; top=-1;}
 void push(string s){
    ++top;
   str[top]=s;
  }
 void pop ( )
   {top = top - 1;}
 string peek()
  { if ( top >= 0 )
  return str[top];
  }
  bool isempty ( ) { return top >= 0 ; }
};
string f(string i){
string j;
if(i=="}") j="{";
if(i=="]") j="[";
if(i==")") j="(";
return j;
}
int main(){
string i,k;
stk s;
int num, flag=1;
cin>>num;
s.n=num;
cin>>k;
for(int j=0; j<num; j++)
 { i=k[j];
  if(i=="{" || i=="[" || i=="(" )
   s.push(i);
  if(i=="}" || i=="]" || i==")" )
    {if(s.peek()==f(i))
        s.pop();
    else
       flag=0;
   }
}
if (flag==0 || s.isempty()) cout<<"0";
else cout<<"1";

return 0;	
}
