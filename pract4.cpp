//  Construct a expression tree from given prefix expression ef. +--a*bc/def and traverse it using postorder traversal(non-resursive ) and delete the entire tre
#include <iostream>
#include <stack>
using namespace std;
class node{
    public:
    char data;
    node *left;
    node *right;
    node(char c)
    {
        this->data=c;
        this->left=NULL;
        this->right=NULL;
    }
};
node *createExpressiontree(string newstr)
{
    stack<node*>st;
    for(int i=newstr.length()-1 ;i>=0;i--)
    {
        char ch=newstr[i];
        node *newnode=new node(ch);
        if((ch >=65 && ch <=90) || (ch >=97 && ch<=122))
        {
            st.push(newnode);
        }
        else
        {
            newnode->left=st.top();
            st.pop();
            newnode->right=st.top();
            st.pop();

            st.push(newnode);
        }
    }

    return st.top();
}
void postorderTraversal(node *root)
{
    if(root == NULL)
    {
        return;
    }
    
    if(root->left != NULL)
    {
        postorderTraversal(root->left);
    }
    if(root->right!= NULL)
    {
        postorderTraversal(root->right);
    }
    std :: cout<<root->data<<" ";
}
int main()
{
    string newstr="+--a*bc/def";
    node *root=createExpressiontree(newstr);
    postorderTraversal(root);
    return 0;
}
