//reverse linked list
#include<iostream>
using namespace std;

class node {
   public:

    int data ;
    node*next;
    node*head=NULL;

    node(int  value  ){
         data=value;
    

    }
     
void insert( int  value  ){
        node*n= new node( value );
        n->next = head;
        head = n;
    
    }
 void display(){
   if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data<< " ";
        temp = temp -> next;
    }
    cout << endl;
}
void reverseLinkList(){
    node*current=head;
    node*pre=NULL;
    node*forward=NULL;
    while(current!=NULL){

        forward = current-> next;
        current->next = pre;
        pre = current;
        current=forward;
    }
    head = pre;

}


};
int main(){
   node ob(1);
   int  value ;

    cin>> value ; 
    ob.insert(  value  );

    cin>> value ;
    ob.insert(  value  );

    cin>> value ;
    ob.insert( value );

    cin>> value ;
    ob.insert( value );

   cout<<"display element before reverse \n";
   ob.display();

   ob.reverseLinkList();
   cout<<"after reverse \n";
   ob.display();

}