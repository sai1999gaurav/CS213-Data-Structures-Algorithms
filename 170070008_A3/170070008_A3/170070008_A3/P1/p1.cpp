#include <iostream>
#include<stack>
class stack{


}
using namespace std;
class sp{
public:
int n;
stack <int> c;
stack <int> p;
sp(){
n=0;
}
friend istream & operator>> ( istream  &inp, sp & poly){
inp>>poly.n;
int coeff, power;
for(int i=0; i<poly.n; i++)
 {inp>>coeff;
 poly.c.push(coeff);
 }
for(int i=0; i<poly.n; i++)
 {inp>>power;
 poly.p.push(power);
 }
} 
friend ostream & operator<< (ostream &op, sp & poly){
while(!poly.c.empty())
{ op<<poly.c.top()<<" ";
  poly.c.pop();
}
cout<<endl;
while(!poly.p.empty())
{ op<<poly.p.top()<<" ";
  poly.p.pop();
}
}
sp add(sp & poly2){
sp poly;
while (!c.empty() && !poly2.c.empty())
{ if(p.top()<poly2.p.top())
	{poly.p.push(poly2.p.top());
         poly2.p.pop();
         poly.c.push(poly2.c.top());
         poly2.c.pop();          
	}
  else if(p.top()>poly2.p.top())
	{poly.p.push(p.top());
         p.pop();
         poly.c.push(c.top());
         c.pop();          
	}
  else
	{ poly.p.push(p.top());
         p.pop(); poly2.p.pop();
         poly.c.push(c.top() + poly2.c.top());
         c.pop(); poly2.c.pop();
	}
}
while (!c.empty())
{ poly.p.push(p.top());
         p.pop();
         poly.c.push(c.top());
         c.pop();
}
while (!poly2.c.empty())
{ poly.p.push(poly2.p.top());
         poly2.p.pop();
         poly.c.push(poly2.c.top());
         poly2.c.pop();
}
return poly;
}
};
int main(){
sp poly1, poly2, poly;
cin>>poly1;
cin>>poly2;
poly = poly1.add(poly2);
cout<<poly;
return 0;
}
