\\doubly Linked list at beginning
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *pre;
	struct node *next;
};
struct node *end;
void addatbeg(struct node **s, int val)
{

	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));

	if (ptr == NULL)
	{
		printf(" full");
	}

	else
	{
		if (*s == NULL)
		{
			end = ptr;
			ptr->data = val;
			ptr->pre = NULL;
			ptr->next = *s;
			//(*s)->pre = ptr;
			*s = ptr;
		}
		else
		{
			ptr->data = val;
			ptr->pre = NULL;
			ptr->next = *s;
			(*s)->pre = ptr;
			*s = ptr;
		}
	}
}
void addatend(struct node **s, int val)
{
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));

	if (ptr == NULL)
	{
		printf(" full");
	}
	else
	{
		end = ptr;
		if (*s == NULL)
		{
			ptr->data = val;
			ptr->pre = NULL;
			ptr->next = NULL;
			*s = ptr;
		}
		else
		{
			struct node *temp = *s;

			while (temp->next != NULL)
			{

				temp = temp->next;
			}

			ptr->data = val;
			ptr->next = NULL;
			ptr->pre = temp;
			temp->next = ptr;
		}
	}
}

void addatpos(struct node **s, int val, int pos)
{
	struct node *ptr;
	int i;
	int c = 1;
	ptr = (struct node *)malloc(sizeof(struct node));
	if (ptr == NULL)
	{
		printf(" full \n ");
	}
	else
	{
		if (pos == 1)
		{
			ptr->data = val;
			ptr->pre = NULL;
			ptr->next = *s;
			(*s)->pre = ptr;
			*s = ptr;
		}

		else
		{
			struct node *temp = *s;
			for (i = 1; i <= pos - 2; i++)
			{
				if (temp->next == NULL)
				{
					printf(" position   is greater then linked list \n");
					return;
				}
				temp = temp->next;
			}

			ptr->data = val;
			ptr->pre = temp;
			temp->next->pre = ptr;
			ptr->next = temp->next;
			temp->next = ptr;
		}
	}
}

int delatbeg(struct node **s)
{
	struct node *ptr;
	if (*s == NULL)
	{
		printf("empty\n");
	}
	else
	{
		ptr = *s;
		*s = ptr->next;
		(*s)->pre = NULL;
	}
	return ptr->data;
}

int delatend(struct node **s)
{
	struct node *ptr = *s;
	if (*s == NULL)
	{
		printf("empty\n");
	}
	else if (ptr->next == NULL)
	{

		*s = NULL;

		return ptr->data;
	}
	else
	{
		struct node *temp = *s;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		ptr = temp->next;
		temp->next = NULL;
	}
	return ptr->data;
}

int delatpos(struct node **s, int pos)
{
	printf("heloo");
	struct node *ptr;
	int i;

	if (*s == NULL)
	{
		printf(" empty \n ");
	}
	else
	{
		if (pos == 1)
		{
			ptr = *s;
			*s = ptr->next;
			(*s)->pre = NULL;
			i = ptr->data;
			free(ptr);
			return i;
		}

		else
		{
			struct node *temp = *s;
			struct node *pev;
			for (i = 1; i <= pos - 1; i++)
			{
				if (temp->next == NULL)
				{
					printf(" position   is greater then linked list \n");
					exit(0);
				}
				pev = temp;
				temp = temp->next;
			}
			if (temp->next == NULL)
			{

				delatend(&pev);
			}
			else
			{
				ptr = temp;
				pev->next = temp->next;
				temp->next->pre = ptr->pre;
				i = temp->data;
			}
			free(ptr);
		}
	}
	return i;
}

void display(struct node *s)
{
	if (s == NULL)
	{
		printf("empty\n");
	}
	else
	{
		struct node *temp = s;
		while (temp->next != NULL)
		{
			printf("  %d  <-> ", temp->data);
			temp = temp->next;
		}
		printf("  %d   \n", temp->data);
		printf(" reveres\n");
		while (temp->pre != NULL)
		{
			printf("  %d  <-> ", temp->data);
			temp = temp->pre;
		}
		printf("  %d   ", temp->data);
	}
}

void main()
{
	struct node *start = NULL;

	int cho, item, pos;
	do
	{

		display(start);
		printf("\nChoose from the Options :-");
		printf("\n1. Insert at Beginning\n2. Insert at Last \n3. Insert Specific Position");
		printf("\n4. Delet from Beginning\n5. Delete from Last \n6. Delete Specific Position");
		printf("\nEnter Option: ");
		scanf("%d", &cho);
		switch (cho)
		{
		case 1:
			printf("\nEnter Item : ");
			scanf("%d", &item);
			addatbeg(&start, item);
			break;
		case 2:
			printf("\nEnter Item : ");
			scanf("%d", &item);
			addatend(&start, item);
			break;
		case 3:
			printf("\nEnter Item and Position : ");
			scanf("%d %d", &item, &pos);
			addatpos(&start, item, pos);
			break;
		case 4:
			delatbeg(&start);
			break;
		case 5:
			delatend(&start);
			break;
		case 6:
			printf("\nEnter Position : ");
			scanf("%d", &pos);
			delatpos(&start, pos);
			break;
		}
	} while (cho != 0);
}
