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
		*head = temp;
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
	struct Node * head = NULL;
	// insertEnd(1,&head);
	// insertEnd(2,&head);
	// printList(&head);
	int r=-1;
	int c=0;
	while(feof(stdin)==0)
	{
		int a;
		scanf("%d",&a);
		if(a != r)
		{
			insertEnd(a,&head);
			printf("%d\n", a);
			r=a;
			c++;
		}

	}
	printf("%d\n",c);
	printList(&head);
	return 0;
}