//implement stack using linked list
#include<iostream>
using namespace std;
struct node{
 public:
    int data;
    node*next;
};

node*top=NULL;

void push(int data){

     node*ptr= new node();
     ptr->data=data;
     ptr->next=top;
     top=ptr;    
}
void pop(){
     if(top==NULL){
        cout<<"stack is empty \n";  
     }
     else
     {
        cout<<"The popped element is"<< top->data <<endl;
        node* ptr = top;
        top = top->next;
        delete(ptr);
    }
}
void display(){
      
      if(top==NULL)
      {
        cout<<"stack is empty\n";
      }

      else
      {
        node*temp=top;
        
        while(temp!=NULL)
        {
            cout<< temp->data <<" ";
            temp = temp->next;
        }
           cout<<endl;
      }
}
int main()
{
    int choice = 1, x;
    while (choice < 4 && choice != 0) // while loop
    {
        cout << "\nPress 1: Insert an element";
        cout << "\nPress 2: Delete an element";
        cout << "\nPress 3: Display the element";
        cout << "\nPress 0: Exit";
        cout << "\nEnter your choice ";
        cin >> choice;

        switch (choice)
        {

        case 1:

            cout << "Enter the element which is to be inserted ";
            cin >> x;
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
        }
    }
}
