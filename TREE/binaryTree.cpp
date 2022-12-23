#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *create(int data)
{
    node *ptr = new node();
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
node *buildtree(struct node *root, int val)
{

    if (root == NULL)
    {
        return create(val);
    }

    if (root->data > val)
    {
        cout << " value in left of " << root->data << " val " << val << endl;
        root->left = buildtree(root->left, val);
    }

    else if (root->data < val)
    {
        cout << " value in right of " << root->data << " val " << val << endl;
        root->right = buildtree(root->right, val);
    }
    return root;
}
bool search(node*root,int key )
{
    if(root==NULL)
    {

        return false ;
    }

    else if(root->data==key)
    {
       return true ;
    }
    if(root->data>key)
    {
        search(root->left,key);
    }
    else if(root->data<key)
    {
        search(root->right,key);
    }
}
node *minValueNode(node *root)
{
    node *temp = root;

    /* loop down to find the leftmost leaf */
    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}
node *removeByKey(node *root, int key)
{
    if (root == NULL)
        return root;

    if (root->data == key)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValueNode(root->right)->data;
            root->data = mini;
            root->right = removeByKey(root->right, mini);
            return root;
        }
    }
    else if (root->data > key)
    {
        root->left = removeByKey(root->left, key);
        cout << "\nroot left " << root->data << endl;
        // return root;
    }
    else
    {
        root->right = removeByKey(root->right, key);
        cout << "\nroot left " << root->data << endl;
    }
    return root;
}
int maxDepth(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print(root->left);
    cout << " " << root->data;
    print(root->right);
}
int main()
{
    node *root = NULL;
    int ch;
    int value ;

    do
    {
        cout<<"\n\t---------------------MAIN MENU------------------------\n\n";
        cout<<"\n1-> Insert ";
        cout<<"\n2-> Delete ";
        cout<<"\n3-> Display ";
        cout<<"\n4-> Search";
        cout<<"\n5-> Minimun Value ";
        cout<<"\n6-> height Of Tree";
        cout<<"\n7-> EXIT \n";
        cin>>ch;
        switch(ch)
        {
            case 1 : 
                cout<<"\n Enter  Value for Insert  "<<endl;
                cin>>value;
                root = buildtree(root, value);
                break; 

            case 2:
                cout<<"\n Enter  Value for Remove "<<endl;
                cin>>value;
                root = removeByKey(root, value);
                break;

            case 3:
                print(root);
                break;

            case 4:
                cout<<"\nEnter value for Search";
                cin>>value;
                if(search(root,value))
                {
                    cout<<"\nYES";
                }
                else
                {
                    cout<<"\nNO";
                }
                break;
            case 5:
                cout<<"\n"<<minValueNode(root)->data;
                break;

            case 6:
                cout<<"\n"<<maxDepth(root)-1;
                break;


        }
    }
    while (ch!=7);
    


  
    return 0;
}
