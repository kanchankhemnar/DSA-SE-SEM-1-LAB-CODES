#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int info)
    {
        data = info;
        left = right = NULL;
    }
};
class BinarySearchTree
{
public:
    node *root;
    BinarySearchTree()
    {
        root = NULL;
    }
    node *implement_bst(node *root, int key)
    {
        if (root == NULL)
        {
            return new node(key);
        }
        if (key < root->data)
        {
            root->left = implement_bst(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = implement_bst(root->right, key);
        }
        return root;
    }

    void traversal(node *root)
    {

        if (root != NULL)
        {
            traversal(root->left);
            cout << root->data << " ";
            traversal(root->right);
        }
        else
        {
            return;
        }
    }

    void display_leaf(node*root){
        if (root==NULL)
        {
            return;
        }
        if (root->left==NULL && root->right==NULL)
        {
            cout<<root->data<<" ";

        }
        else
        {
            display_leaf(root->left);
            display_leaf(root->right);

        }
        
        
        
    }
    void search(node*root,int key){
        node*curr=root;
        int flag=0;
        while (curr!=NULL)
        {
            if (key==curr->data)
            {
                cout<<"\nnode found in bst";
                flag=1;
                break;
            }
            else if (key<curr->data)
            {
                curr=curr->left;
            }
            else if (key>curr->data)
            {
                curr=curr->right;
            }
            
            
        }
        if (flag==0)
        {
            cout<<"\nnode not found in bst";
        }
        
        
        
    }
};
int main()
{
    BinarySearchTree bst;
    cout << "enter no of elements in tree: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter element " << i + 1 << " :  ";
        int insert;
        cin >> insert;
        bst.root=bst.implement_bst(bst.root, insert);
    }
    cout << "\nTraversal: ";
    bst.traversal(bst.root);
    cout<<"\nLeaf nodes: ";
    bst.display_leaf(bst.root);
    cout<<"\nenter number to search in bst: ";
    int s;
    cin>>s;
    bst.search(bst.root,s);
     cout<<"\nenter number to search in bst: ";
    int s1;
    cin>>s1;
    bst.search(bst.root,s1);

    return 0;
}