#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;
    bool isthreded;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
        this->isthreded=false;
    }
};
void convert_queue(node *root , queue<node*>*q)
{
    if(root == NULL){
        return;
    }
    if(root->left != NULL)
    {
        convert_queue(root->left ,q);
    }
    q->push(root);
    if(root->right != NULL)
    {
        convert_queue(root->right ,q);
    }
}
void createThreds(node * root ,queue<node*>*q)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left)
    {
        createThreds(root->left ,q);
    }
    q->pop();
    if(root->right != NULL)
    {
        createThreds(root->right , q);
    }
    else
    {
        root->right=q->front();
        root->isthreded=true;
    }
}
void createTree(node *root )
{
    queue<node*>q;//
    convert_queue(root ,&q);

    createThreds(root ,&q);
}
node *leftmost(node *root)
{
    
    while(root->left != NULL  && root != NULL)
    {
        root=root->left;
    }
    return root;
}
void inorderTraversal(node *root)
{
    if(root == NULL){
        return;
    }
    node *curr=leftmost(root);
    while(curr != NULL)
    {
        cout<<curr->data<<" ";

        if(curr->isthreded)
        {
            curr=curr->right;
        }
        else
        {
            curr=leftmost(curr->right);
        }
    }
}
int main()
{
    node *root=new node(10);
    
    root->left=new node(12);
    root->right=new node(11);
    root->left->left=new node(7);
    root->right->right=new node(6);
    createTree(root);
    inorderTraversal(root);
    return 0;
}