#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct Node
{
	int num;
	struct Node* next;
};

void printList(struct Node** head)
{
	struct Node* temp = *head;
	while(temp!=NULL)
	{
		printf("%d ",temp->num);
		temp = temp->next;
	}
	printf("\n");
}

void insertBeg(int n,struct Node** head)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->num = n;
	temp->next = *head;
	*head = temp;
}

void insertEnd(int n,struct Node** head)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->num = n;
	temp->next = NULL;
	struct Node* r = *head;
	if(r == NULL)
	{
		r = temp;
	}
	else 
	{
		while(r->next != NULL)
		{
			r = r->next;
		}
		r->next = temp;
	}
}

int main()
{
	char s1[1000000];
	char s2[1000000];
	fgets(s1,1000000,stdin);
	fgets(s2,1000000,stdin);

	// printf("%d ",(int)strlen(s1));
	struct Node * head1 = NULL;
	for (int x=0;x<strlen(s1)-1;x++)
	{
		int r = (int)(s1[x]-48);
		insertBeg(r,&head1);
	}
	printList(&head1);
	struct Node * head2 = NULL;
	for (int x=0;x<strlen(s2)-1;x++)
	{
		int r = (int)(s2[x]-48);
		insertBeg(r,&head2);
	}
	printList(&head2);
	struct Node * head3 = NULL;
	int c=0;
	struct Node* tmp1 = head1;
	struct Node* tmp2 = head2;
	while(tmp1 != NULL && tmp2 != NULL)
	{
		if(tmp2->num == 0 && tmp1->num == 0)
		{
			if(c==0)
				insertBeg(0,&head3);
			else
				insertBeg(1,&head3);

			c = 0;
		}
		else if(tmp2->num == 0 && tmp1->num == 1)
		{
			if(c==0)
			{
				insertBeg(1,&head3);
				c=0;
			}
			else
			{
				insertBeg(0,&head3);
				c=1;
			}
		}
		else if(tmp2->num == 1 && tmp1->num == 0)
		{
			if(c==0)
			{
				insertBeg(1,&head3);
				c=0;
			}
			else
			{
				insertBeg(0,&head3);
				c=1;
			}
		}
		else
		{
			if(c==0)
			{
				insertBeg(0,&head3);
				c=1;
			}
			else
			{
				insertBeg(1,&head3);
				c=1;
			}

		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}


	if(c==1)
		insertBeg(1,&head3);

	printList(&head3);

	return 0;
}