#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    char data;
    node *l,*r;
};
 node* newNode (int data)
{
     node *temp = new  node;
    temp->data = data;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}
node *insert(int *i,char *str)
{
int index = *i; // store the current value of index in pre[]
 
    // Base Case: All nodes are constructed
    if (index <0)
        return NULL;
 
    // Allocate memory for this node and increment index for
    // subsequent recursive calls
    struct node *temp = newNode ( str[index] );
    (*i)--;
 
    // If this is an internal node, construct left and right subtrees and link the subtrees
    if('A'<=str[index]<='Z')
    {
      temp->r = insert(i, str);
      temp->l = insert(i, str);//constructTreeUtil(pre, preLN, index_ptr, n);
    }
 
    return temp;
}


int numleaf(node *ptr)
{
	if(ptr==NULL)  return 0;
    if(ptr->l==NULL&&ptr->r==NULL)
       return 1;
    return (numleaf(ptr->l)+numleaf(ptr->r));
}
int f(node *ptr,string A,int k,int i)
{
if(ptr==NULL) return 0;
if(ptr->data==A[i]&&i==k-1)
 { return numleaf(ptr); }
if(ptr->data==A[i])
{
 return f(ptr->l,A,k,i+1)+f(ptr->r,A,k,i+1);
}
return 0;
}  
void inorder(node *ptr)
{
	if(ptr)
	{
	inorder(ptr->l);
	cout<<ptr->data<<" ";
	inorder(ptr->r);
	}
  }  
int explodePaths(int N, char* S, int K, char* A) {

    node *root;
    int i=N-1;
    root=insert(&i,S);
	inorder(root);
	 cout<<root->data;
     return f(root,A,K,0);;   

}
int main()
{
	char s[]="txyBabABA";
	char A[]="AA";
	
	cout<<explodePaths(9,s,2,A);
return 0;

	
}

