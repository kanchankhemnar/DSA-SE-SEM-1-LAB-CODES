#include <iostream>
using namespace std;
class node{
public:
	int data;
	node* lptr;
	node* rptr;
	int lthread;
	int rthread;	
	node(int info)
	{
	this->data=info;
	this->lptr=NULL;
	this->rptr=NULL;
	this->lthread=0;
    this->rthread=0;
	//if child present then 0; 
	//else no child then 1;
	}
};

class TBT{
public:
	
	//creating head node
	node* head;
    node* root;
	//head->data=2;
    TBT(){
    head=new node(2);
	head->lthread=head->rthread=0;
	head->lptr=head->rptr= head;
	node*root=NULL;
    }
	
	
	
	/*node*root =new node(int info);
 	root->lthread =root->rthread=0;
 	root->rptr=root->lptr= head;
 	head->lptr=root;
 	head->lthread= 1;*/
 
public:  
void  insert( int info ){
if(root==NULL){
    root->data=info;
 	root->lthread =root->rthread=0;
 	root->rptr=root->lptr= head;
 	head->lptr=root;
 	head->lthread= 1;
}
node*parent;
parent =root;
cout<<"Root is "<<parent->data<<endl;

if(info<=parent->data){
//insert as a left child
while(parent->lthread!=0)
//if no lchild
{
parent=parent->lptr;
}
node* temp=new node(int info);
temp->lptr=parent->lptr;
temp->rptr=parent;
temp->lthread=temp->rthread=0;
parent->lptr=temp;
parent->lthread=1;

}

else if(info > parent->data){
//insert at right side
while(parent->rthread !=0)
{
parent= parent->rptr;
}
node* temp=new node(int info);
temp->rptr= parent->rptr;
temp->lptr=parent;
temp->lthread=temp->rthread=0;
parent->rptr=temp;
parent->rthread=1;
}

}
};
//void Inorder(head){



/*void preorder(head){
current = head->lptr;
if(current==head){
cout<<"EMPTY TREE\n";
}
while(current!=head){
cout<<current->data<<" ";
if(current->lthrd==1){
current=current->lptr;
cout<<current->data<<" ";
}
else{

}

if(current->rthrd==1){
current=current->rptr;
cout<<current->data<<" ";
}

















/*➢ Non Recursive Preorder Traversal Non_preorder(head)
Step 1: current = head->lptr
Step 2: if current =head
i. THEN WRITE(‘EMPTY TREE’)
ii. Exit
Step 3: while current ! =head
i. display(current->data) //process data in preorder
ii. if(current->lthread =0) //if having leftchiled process left subtree
a. current=current->lptr
iii. else
//if no left subtree , go to right subtree
a. while (current->rthread=1)
i. current=current->rptr
b. current=current->rptr// if left subtree process it first
c. end while
Step 4: end while
Step 5: end of preorder
➢ Non Recursive Inorder Traversal Non_Inroder(head)
Step 1: current =head->lptr
Step 2: if (current->lptr=head)
PICT, SE-IT Data structure and Algorithms Laboratory
23
i. THEN WRITE(‘EMPTY TREE’)
ii. Exit
Step 3: while (current ->lthread=0) //go to leftmost chiled of the left subtree
i. current=current->lptr
ii. while( current !=head)
a. display( current ->data)
b. If current->rthread= 1 current =current->rptr
c. else
i. current= current->rptr
ii. repeat while ( current->lthread =0)
a. current =current->lp
};*/




int main(){
TBT n;
while(1)
{
int choice;
cout<<"enter \n1-insert\n2-inorder\n3-preorder\n";
cin>>choice;
switch(choice){
case 1:
	cout<<"enter data: ";
	int data;
	cin>>data;
	n.insert(data);
	break;
case 2:
	break;
case 3:
	break;	
	
}
}
	
	
	
	
	
	
	
	
	


return 0;
}