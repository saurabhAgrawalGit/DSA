/* Find Middle of Element
 conditions
           if even number of node then = no of node /2
           and odd number of node then = (no of node / 2)+1 */
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *head = NULL;
    node(int value)
    {
        data = value;
    }
    void insert(int value)
    {
        node *n = new node(value);
        n->next = head;
        head = n;
    }
    void display()
    {

        if (head == NULL)
        {

            cout << "List is empty " << endl;
            return;
        }
        node *temp = head;

        cout << " DISPLAY \n\n";

        while (temp != NULL)
        {

            cout << temp->data;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    void middle()
    {

        node *fast = head;
        node *slow = head;

        if (head != NULL)
        {
            while (fast != NULL && fast->next != NULL)
            {

                fast = fast->next->next;
                if (fast != NULL)
                {
                    slow = slow->next;
                    cout << "hi\n";
                }
            }

            cout << " middle element " << slow->data << endl;
        }
    }
};
int main()
{
    node s(1);
    cout << "enter the  value \n";
    int value;
    cin >> value;
    s.insert(value);

    cin >> value;
    s.insert(value);
    cin >> value;
    s.insert(value);
    cin >> value;

    s.insert(value);

    s.display();
    s.middle();
}