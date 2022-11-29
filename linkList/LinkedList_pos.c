#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addAtPos(struct node **s, int item, int pos)
{
    int i;
    struct node* ptr= (struct node *)malloc(sizeof(struct node));
    if( ptr==NULL)
    {
        printf("linked list full\n");
    }
    else
    {   ptr->data = item;
        if (pos == 1)
        {
            
            ptr->next = *s;
            *s = ptr;
        }
        else
        {
            struct node *temp = *s;
            for (i = 1; i <=pos- 2; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    printf("can't insert \n");
                    return;
                }
            }
            ptr->next = temp->next;
            temp->next = ptr;
        }

    }
}
int delAtPos(struct node **head,int pos )
{
    
    struct node*ptr;
    int del;
    int i ;
    if( *head==NULL)

    {
   
        printf("linked list full\n");
    }
    else
    { 
        if (pos == 1)
        {  
            int i;
            ptr=*head;
            del=ptr->data;
            *head =ptr->next;
            free(ptr);
            return del;
            
            
        }
        else
        {
            printf("hello3 \n");
            struct node *temp = *head;
            struct node * pre = NULL;
            for (i = 1; i <=pos- 1; i++)
            {   //printf(" %d \n",temp->data); 
                pre=temp;
                temp = temp->next;
                if (temp == NULL)
                {
                    printf("can't insert \n");
                    return -1;
                }
            }
            //printf(" %d \n",pre->data);
            ptr = temp;
            pre->next=temp->next;
            del=temp->data;
            return del;
        }

    }

}
void insert(struct node **s, int val)
{
   struct node *ptr = (struct node *) malloc (sizeof(struct node)); 


   
    ptr->data= val;
    ptr->next = *s;
    *s = ptr;

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
int main()
{
    struct node *s = NULL;
    int val;
    
    insert(&s, 5);
    
    insert(&s, 6);
    
    insert(&s, 7);
    
    insert(&s, 8);
    display(s);
    addAtPos(&s,9,3);
    display(s);
    printf("remove %d \n",delAtPos(&s,1));
    display(s);
}
