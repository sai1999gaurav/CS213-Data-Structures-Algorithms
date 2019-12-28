#include <iostream>
using namespace std;
struct Node{
int value;
Node* left;
Node* right;
Node* parent;
Node(){
left=NULL;
right=NULL;
parent=NULL;
}
};

void insert( Node* root, int key){
if(key<root->value) {if(!root->left){ Node*p=new Node;
p->parent=root;
root->left=p;
p->value=key;}
else
insert(root->left, key);}
else {if(!root->right){ Node*p=new Node;
p->parent=root;
root->right=p;
p->value=key;}
else
insert(root->right, key);}
}
Node* search(Node* root,int  key){
if(!root) {Node*p=new Node; p->value=-1; return p;}
if(key==root->value) return root;
else if(key<root->value) return search(root->left, key);
else return search(root->right, key);
}

int main(){
int n;
cin>>n;
int a[n];
for(int i=0; i<n; i++) cin>>a[i];
Node *root = new Node;
root->value=a[0];
for(int i=1; i<n; i++) insert(root, a[i]);
int p;
cin>>p;
Node*q= new Node;
q=search(root,p);
if(q->value==-1 || q==root) cout<<-1;
else while(q!=root){
cout<<q->parent->value<<" ";
q=q->parent;
}
cout<<endl;
return 0;	
}
