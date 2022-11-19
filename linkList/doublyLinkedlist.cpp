\\doubly Linked list at beginning
#include<iostream>
using namespace std ;
struct node
{
    int data;
    struct node * next;
    struct node * pre;
};
struct node * head = NULL;
struct node * tail = NULL;
void  addAtbeg(int data){
    struct node * ptr;
    ptr= new node() ;
    if(head == NULL ){
        tail=ptr;
        head=ptr;
        ptr->data=data;
        ptr->next=NULL;
        ptr->pre=NULL;

    }
   else{
    ptr->data=data;
    ptr->pre = NULL;
    ptr->next = head;
    head->pre=ptr;
    head= ptr;
   }
} 
void display(){
   if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }

    struct node* temp = head;
    cout<<"print element with start\n";

    while(temp != NULL ) {
        cout << temp -> data<< " ";
        temp = temp -> next;
    }
    
    cout << endl;
    cout<<"print element with end\n";

    struct node* temp1 = tail;

    while(temp1 != NULL ) {
        cout << temp1 -> data<< " ";
        temp1 = temp1 -> pre;
    }

    cout << endl;
}
int main(){
    addAtbeg(7);
    addAtbeg(6);
    addAtbeg(5);
    addAtbeg(4);    
    addAtbeg(3);
    addAtbeg(2);
    display();
    
    
}