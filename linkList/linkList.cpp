//simple linklist insert at end
#include<iostream>
using namespace std;
class node{
    

public:
    int data;
    node* next;
   node*head =NULL;
   node*end =NULL;
    // A constructor is called here
    node(int value)
    {
 
        // It automatic assigns the
        // value to the data
        data = value;
 
        // Next pointer is pointed to NULL
       next = NULL;
    }
    void insert( int val)
{    
    node* n = new node(val);
    if(head==NULL){
    head=n;
    n->next=end;
    end =n;
    //n->next=end;
     }
     else{
        n->next=NULL;
        end->next =n;
        end=n;
     }  
    
    
    
    

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
};


    
   

int main(){
    node s(1);
    int val;
    cin>>val;
    s.insert(val);
    cin>>val;
    s.insert(val);
    cin>>val;
    s.insert(val);
    cin>>val;
    s.insert(val);
    cin>>val;
    s.insert(val);
    s.display();
    

    
  
   
   

}
