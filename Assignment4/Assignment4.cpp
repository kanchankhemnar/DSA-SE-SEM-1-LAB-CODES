#include <iostream>
#include <stack>
using namespace std;

class Node{
    public:
    char data;
    Node* left;
    Node* right;

    Node(char val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

class Tree{
    public:
    stack<Node*> s;
    Node* root;
    Tree(){
       root=NULL;
    }

    bool isOperand(char a){
        return isalnum(a);
    }

    bool isOperator(char a){
        return (a=='/' || a=='+' || a=='-' || a=='*' || a== '^');
    }

    void inOrdertraversalwithRec(Node* root){
       if(root==NULL)
           return; 
       inOrdertraversalwithRec(root->left);
       cout<<root->data<<" ";
       inOrdertraversalwithRec(root->right);
    }


    void preOrdertraversalwithRec(Node* root){
       if(root==NULL)
           return;
       cout<<root->data<<" ";
       preOrdertraversalwithRec(root->left);
       preOrdertraversalwithRec(root->right);
    }


    void postOrdertraversalwithRec(Node* root){
       if(root==NULL)
           return;
       postOrdertraversalwithRec(root->left);
       postOrdertraversalwithRec(root->right);
       cout<<root->data<<" ";
    }


    void inOrdertraversalwithoutRec(Node* root){
        Node* t=root;
        while(t!=NULL || !s.empty()){
            while(t!=NULL){
                s.push(t);
                t=t->left;
            }
            t=s.top();
            s.pop();
            cout<<t->data<<" ";
            t=t->right;
        }
    }


    void preOrdertraversalwithoutRec(Node* root){
        if(root==NULL)
            return;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node* t=st.top();
            st.pop();
            cout<<t->data<<" ";
            if(t->right){
                st.push(t->right);
            }
            if(t->left){
                st.push(t->left);
            }
        }
    }


    void postOrdertraversalwithoutRec(Node* root){
        if (root == NULL)
            return;

        stack<Node *> s1, s2;
        Node *temp = root;
        s1.push(temp);
        while(!s1.empty()){
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left != NULL){
                s1.push(temp->left);
            }
            if(temp->right != NULL){
                s1.push(temp->right);
            }
        }

        while (!s2.empty()){
            cout<<s2.top()->data << " ";
            s2.pop();
        }
        cout << endl;
    }


    void expressionTree(const char postfix[]){
        int i=0;
        stack<Node*>tree;
        while(postfix[i]!='\0'){
            char curr=postfix[i];
            if(isOperand(curr)){
                Node* t=new Node(curr);
                tree.push(t);
            }
            else if(isOperator(curr)){
                Node* op=new Node(curr);
                op->right=tree.top();
                tree.pop();
                op->left=tree.top();
                tree.pop();
                tree.push(op);
            }
            i++;
        }
        root=tree.top();
    }
};

int main() {
    Tree t;
    char postfix[100];

    while (true) {
        cout<<endl;
        cout << "1. Enter postfix expression" << endl;
        cout << "2. Inorder traversal without recursion" << endl;
        cout << "3. Preorder traversal without recursion" << endl;
        cout << "4. Postorder traversal without recursion" << endl;
        cout << "5. Inorder traversal with recursion" << endl;
        cout << "6. Preorder traversal with recursion" << endl;
        cout << "7. Postorder traversal with recursion" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cout<<endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter postfix expression: ";
                cin.getline(postfix, sizeof(postfix));
                t.expressionTree(postfix);
                break;

            case 2:
                t.inOrdertraversalwithoutRec(t.root);
                break;

            case 3:
                t.preOrdertraversalwithoutRec(t.root);
                break;

            case 4:
                t.postOrdertraversalwithoutRec(t.root);
                break;

            case 5:
                t.inOrdertraversalwithRec(t.root);
                break;

            case 6:
                t.preOrdertraversalwithRec(t.root);
                break;

            case 7:
                t.postOrdertraversalwithRec(t.root);
                break;

            case 8:
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

