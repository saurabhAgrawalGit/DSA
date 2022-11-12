// reverse the nodes of the list k at a time
#include <iostream>

using namespace std;
class node
{
public:
  int data;
  node *next;
  node(int value)
  {
    data = value;
  }
};
void insert(node *&head, int value)
{
  node *n = new node(value);
  n->next = head;
  head = n;
}
void display(node *head)
{
  if (head == NULL)
  {
    cout << "List is empty " << endl;
    return;
  }
  node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
node *reverse_kGroup(node *head, int k)
{

  node *forward = NULL;
  node *current = head;
  node *pre = NULL;

  int count = 0;

  while (current != NULL && count < k)
  {
    forward = current->next;
    current->next = pre;
    pre = current;
    current = forward;
    count++;
  }

  cout << endl;
  if (forward != NULL)
  {
    head->next = reverse_kGroup(forward, k);
  }
  return pre;
}
int main()
{
  int n;
  node *head = NULL;
  insert(head, 6);
  insert(head, 5);
  insert(head, 4);
  insert(head, 3);
  insert(head, 2);
  insert(head, 1);
  cout << "Display emlement ";
  display(head);
  cout << endl;
  cout << "enter  kgroup \n";
  cin >> n;
  head = reverse_kGroup(head, n);
  cout << " diplay elemnt after kgroup\n";
  display(head);
}