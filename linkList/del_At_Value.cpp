//write a program to implement singly linked list with deletion based 
// item and insertion a new node to the ascending order.
#include<stdio.h>
#include<stdlib.h>

struct  node 
{
    int data ;
   struct node*next;

};
void addAtBeg(struct node**s,int item)
{
    struct node *ptr = (struct node *) malloc (sizeof(struct node));
    struct node*temp=*s; 
    if(ptr==NULL)
    {
        printf("linkedlist is full ");
    }

    else
    {
        if (*s==NULL||item<temp->data)
        {
            ptr->data=item;
            ptr->next=*s;
            *s=ptr;
        }
        
        else
        { 
            while(temp->next!=NULL)
            {  
                if(temp->next->data<item)
                {
                    temp=temp->next;
                }
            } 
                ptr->data=item;
                ptr->next=temp->next;
                temp->next=ptr;
         }
    }
}
void display(struct node *head)
{
    if (head == NULL)
    {
       printf ( "List is empty \n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL)
    {
        printf(" %d ",temp->data );
        temp = temp->next;
    }

    printf("\n");
}
void delAtVal(int key,struct node **s)
{
      struct node * temp =*s;
      struct node* ptr;
      struct node*pre;

      if( temp==NULL)
      {
            printf("Empty\n");
      }
      else if(temp->data==key)
      { 
            ptr = *s;
            *s  = temp->next;
            printf(" value %d  \n",ptr->data);
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
          printf(" element are not present \n ");
     }      
}
int main ()
{  
     struct  node*head=NULL;
      addAtBeg(&head,4);
      addAtBeg(&head,5);
      addAtBeg(&head,6);
      addAtBeg(&head,7);
      
      display(head);
      delAtVal(7,&head);
      display(head);
     

}
