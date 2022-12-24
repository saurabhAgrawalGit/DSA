#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int data)
{
    node *ptr = new node();
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }

    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }

    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}
void display(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    cout << " " << root->data;
    display(root->right);
}
int sizeOfTree(struct node *root)
{   
    if (root == NULL)
    {
        return 0;
    }
    else
    {   
        return  (sizeOfTree(root->left) + 1 + sizeOfTree(root->right));    
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 90);

    root = insert(root, 100);
    root = insert(root, 99);
    root = insert(root, 50);
    root = insert(root, 150);
    root = insert(root, 140);
    root = insert(root, 250);
    root = insert(root, 25);
    cout << " Display Element" << endl;
    display(root);
    cout<<"\n Number Of Nodes In tree "<<sizeOfTree(root);
}
