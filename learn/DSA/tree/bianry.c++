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
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
};

Node* create(int val) {
    Node* nn = new Node;
    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void insert(Node*& root, int val) {
    if (root == NULL) {
        root = create(val);
        return;
    }
    if (val < root->data) {
        insert(root->left, val);
    }
    else if (val > root->data) {
        insert(root->right, val);
    }
}

void removenode(Node*& root, int key) {
    if (root == nullptr) {
        return;
    }

    if (key < root->data) {
        removenode(root->left, key);
    }
    else if (key > root->data) {
        removenode(root->right, key);
    }
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // Case 2: One child (right child)
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            root = temp;
        }
        // Case 3: One child (left child)
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            root = temp;
        }
        // Case 4: Two children
        else {
            Node* temp = findMin(root->right); // Find the minimum in the right subtree
            root->data = temp->data;           // Copy the minimum value to root
            removenode(root->right, temp->data); // Delete the duplicate node
        }
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    int k;
    cin >> k; // Input the number of nodes to be inserted into the tree

    Node* root = nullptr;

    for (int i = 0; i < k; i++) {
        int c;
        cin >> c; // Input the values to insert into the tree
        insert(root, c);
    }

    int l;
    cin >> l; // Input the value to be deleted from the tree
    removenode(root, l); // Call removenode to delete the value

    cout << "AFTER DELETION\n";
    inorder(root); // Output the inorder traversal after deletion
    cout << endl;

    return 0;
}


