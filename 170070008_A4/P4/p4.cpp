#include <iostream>
using namespace std;
struct node{
int ch;
node* next;
int visited;
node(){
visited=0;
next=NULL;
}
};
int check( node*rh[], int v){
node*r=rh[v];
while(r->next!=NULL){
if(r->next->visited==1) {cout<<"1"<<endl; return 1;}
else{
r->next->visited=1;
if(rh[r->ch]->next==NULL) r=r->next;
else return check(rh, r->next->ch);
}
}return 0;
}
int main(){
int n, m, i;
cin>>n>>m;	
node* rh[n];
for(int j=0; j<n; j++) rh[j]=new node;
i=0;
while(i<m){
int p,q; cin>>p>>q;
node*z=new node;
z->ch=q;
if(rh[p]->next==NULL) rh[p]->next=z;
else{
node*r = rh[p];
while(r->next!=NULL) r=r->next;
r->next=z;
}
i++;
}
int v;
cin>>v;
if(rh[v]->next==NULL) cout<<"0";
else{
node*r=rh[v];
while(r->next!=NULL)
{ r=r->next; r->visited=1; if(check(rh,r->ch)) return 0;}
if(r->next==NULL) cout<<"0"<<endl;
}
return 0;
}
