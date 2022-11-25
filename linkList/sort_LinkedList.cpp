// Merge  Two Sort Linked List In Another LinkedList 

#include<iostream>
using  namespace std;
struct  node2 
{
    int data ;
    node2*next;

};
node2*head2=NULL;
void addAtBeg2(int data)
{
    node2*ptr= new node2();
    ptr->data= data;
    ptr->next = head2;
    head2 = ptr;

}
void display2( )
{
    if(head2 == NULL)
    {
        cout << "List is empty "<< endl;
        return ;
    }
        
    node2* temp = head2;

    while(temp != NULL )
    {
        cout << temp -> data<< " ";
        temp = temp -> next;
    }
 
     cout << endl;
}
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

struct  node1 
{
    int data ;
    node1*next;

};
void addAtBeg1(int data,node1**s)
{
    node1*ptr= new node1();
    ptr->data= data;
    ptr->next = *s;
    *s = ptr;

}
void display1(node1*head )
{
    if(head == NULL)
    {
        cout << "List is empty "<< endl;
        return ;
    }
        
    node1* temp = head;

    while(temp != NULL )
    {
        cout << temp -> data<< " ";
        temp = temp -> next;
    }
 
     cout << endl;
}
void merge(node*head,node1*head1)
{   
    node* temp=head;
    node1* temp1=head1;
    while (temp!=NULL&&temp1!=NULL)
    {
        if(temp->data>temp1->data)
        {   
            addAtBeg2(temp1->data);
            temp1=temp1->next;
        }
        else if(temp->data<temp1->data)
        {   
            addAtBeg2(temp->data);
            temp=temp->next;
        }
         else if(temp->data==temp1->data)
        {   
            addAtBeg2(temp1->data);
            temp1=temp1->next;
            temp=temp->next;
        }
    }
    while (temp!=NULL)
    {      addAtBeg2(temp->data);
           temp= temp->next;
    }
    while (temp1!=NULL)
    {      addAtBeg2(temp1->data);
           temp1= temp1->next;
    }
}

int main(){
    node*head=NULL;
    node1*head1=NULL;
    
    addAtBeg(88,&head);
    addAtBeg(77,&head);
    addAtBeg(66,&head);
    addAtBeg(55,&head);
    addAtBeg(44,&head);
    cout<<"Linked List 1 \n";
    display(head);
    addAtBeg1(100,&head1);
    addAtBeg1(88,&head1);
    addAtBeg1(70,&head1);
    addAtBeg1(55,&head1);
    addAtBeg1(58,&head1);
    addAtBeg1(40,&head1);
    cout<<"Linked List 1 \n";
    display1(head1);
    merge(head,head1);
    cout<<"Linked List main \n";
    display2();

}
