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


