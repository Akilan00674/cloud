********tree*********8  
#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* left,*right;
};
Node* create(int val)
{
    Node* nn = new Node;
    nn->data=val;
    nn->left=NULL;
    nn->right=NULL;
    
    return nn;
}

void insert (Node*& root ,int val)
{
    if(root==NULL)
    {
        root=create(val);
    }
    if(val < root->data)
    {
        insert(root->left,val);
    }
    else if(val>root->data)
    {
        insert(root->right,val);
    }
}

void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int val;

    do {
        cin >> val;
        if (val == -1) break;
        insert(root, val);
    } while (true);
	
	

    return 0;
}
*******preorder*******
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
**********postorder**********
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}


*********max**********
int findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}
*********min**************
int findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}
***********depth***********
int depth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return max(leftDepth, rightDepth) + 1;
}
**********delete****************
 #include <iostream>
using namespace std;


struct node
{
    node* left;
    node* right;
    int data;
};

node* createnode(int val)
{
    node* nn=new node;
    nn->data=val;
    nn->left=nullptr;
    nn->right=nullptr;
    return nn;
}

void insert(node* &root,int val)
{
    if(root==nullptr)
    {
        root=createnode(val);
    }
    else if(val<root->data)
    {
        insert(root->left,val);
    }
    else if(val>root->data)
    {
        insert(root->right,val);
    }
}

node* min(node* root)
{
    if(root->left==nullptr)
    {
        return root;
    }
    int max=root->data;
    if(root->left->data<max)
    {
      min(root->left);
    }
}


void removenode(node* &root,int key)
{
    if(root==nullptr)
    {
        return;
    }
    else if(key<root->data)
    {
        removenode(root->left,key);
    }
    else if(key>root->data)
    {
        removenode(root->right,key);
    }
    else
    {
        if(root->left==nullptr)
        {
            node* temp=root->right;
            delete root;
            root=temp;
        }
        else if(root->right==nullptr)
        {
             node* temp=root->left;
            delete root;
            root=temp;
        }
        else
        {
            node* minn=min(root->right);
            root->data=minn->data;
            removenode(root->right,minn->data);
        }
    }
}

void inor(node* root)
{
    if(root)
    {
        inor(root->left);
        cout<<root->data<<" ";
        inor(root->right);
        
    }
}
int main()
{
 int k;
 cin>>k;
 node* root=nullptr;
 for(int i=0;i<k;i++)
 {
     int c;
     cin>>c;
     insert(root,c);
 }
 int l;
 cin>>l;
 removenode(root,l);
 
 cout<<"AFTER DELETION\n";
 inor(root);
}	


