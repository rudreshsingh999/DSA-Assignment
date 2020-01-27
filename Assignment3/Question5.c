#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node {
	int num;
	struct Node * next;
};


void printList(struct Node ** head) {
	struct Node * temp = *head;
	while (temp != NULL) {
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("\n");
}

void insertEnd (int n, struct Node ** head) {
	struct Node * temp = (struct Node *)(malloc(sizeof(struct Node)));
	temp->num = n;
	temp->next = NULL;
	if(*head == NULL) { 
		*head = temp;
		return;
	}
	struct Node * head1 = * head;
	while(head1->next != NULL) 
		head1 = head1->next;
	head1->next = temp;
}

int main() {
	int count = 0;
	struct Node * head = NULL;
	while(1) {
		int a;
		char c;
		scanf("%d%c", &a, &c);
		insertEnd(a, &head);
		count++;
		if(c == '\n')
			break;
	}

	struct Node * ans = NULL;
	int c1 = 1;
	int c2 = count;
	while(c1 <= c2) {
		struct Node * temp1 = head;
		for (int x = 1; x <= c1-1; x++) {
			temp1 = temp1->next;
		}
		insertEnd(temp1->num, &ans);
		struct Node * temp2 = head;
		c1++;

		if(c1 > c2)
			break;

		for (int x = 1; x <= c2-1; x++) {
			temp2 = temp2->next;
		}
		insertEnd(temp2->num, &ans);
		c2--;
	}

	printList(&ans);
	return 0;
}