#include <iostream>
#include <stack>
using namespace std;
int main(){
int n, i, ele;
cin>>n;
stack <int> a, b;
while(n--){
cin>>i;
if(i==1){cin>>ele;
        a.push(ele);
        }
else    { if(b.empty()) {
         while(!a.empty()){
          b.push(a.top());
          a.pop();}
           }
          if(!b.empty()){
          if(i==2) b.pop();
          if(i==3) cout<<b.top()<<endl;
         }
          
        }
}
return 0;	
}
