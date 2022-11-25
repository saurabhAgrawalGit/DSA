// delete node at value 
#include<iostream>
using namespace std;
struct  node 
{
    int data ;
    node*next;

};
void addAtBeg(int data,node**s)
{
    node*ptr= new node();
    ptr->data= data;
    ptr->next = *s;
    *s = ptr;

}
void display(node*head )
{
    if(head == NULL)
    {
        cout << "List is empty "<< endl;
        return ;
    }
        
    node* temp = head;

    while(temp != NULL )
    {
        cout << temp -> data<< " ";
        temp = temp -> next;
    }
 
     cout << endl;
}
void delAtVal(int key,node **s)
{
      node * temp =*s;
      node* ptr;
      node*pre;

      if( temp==NULL)
      {
            cout<<"Empty\n";
      }
      else if(temp->data==key)
      { 
            ptr=*s;
            *s=temp->next;
            cout<<" value "<<ptr->data<<" \n";
            free(ptr);
            return;
      }
      else
      { 
          while (temp->next!=NULL)
          {   
                pre=temp;
                temp=temp->next;

               if(temp->data==key)
               {
                  ptr=temp;
                  pre->next=temp->next;
                  free(ptr);
                  return;
               }
          }
     }      
}
int main ()
{  
      node*head=NULL;
      addAtBeg(7,&head);
      addAtBeg(88,&head);
      // addAtBeg(6,&head);
      // addAtBeg(9,&head);
      // addAtBeg(2,&head);
      display(head);
      delAtVal(7,&head);
      display(head);
     

}
