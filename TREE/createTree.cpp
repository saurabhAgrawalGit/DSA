#include <iostream>
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
node *buildtree()
{
  int val;
  cout << "Enter Value" << endl;
  cin >> val;
  node *root;

  if (val == -1)
  {
    return NULL;
  }

  root = create(val);
  cout << "\nenter value in left of " << val << endl;
  root->left = buildtree();
  cout << "\nenter value in right of " << val << endl;
  root->right = buildtree();
  return root;
}

void print(node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  print(root->left);
  print(root->right);
}

int main()
{
  node *root = buildtree();
  print(root);
  return 0;
}
