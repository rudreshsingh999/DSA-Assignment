#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int num;
	struct Node * next;
};

struct Node * head = NULL;

void printList() {
	struct Node * temp = head;
	while (temp != NULL) {
		printf("%d ",temp->num);
		temp = temp->next;
	}
	printf("\n");
}

void add(int n) {
	struct Node * temp = (struct Node *)(malloc(sizeof(struct Node)));
	temp->num = n;
	temp->next = NULL;
	struct Node * t = head;
	if(t == NULL) {
		head = temp;
		return;
	}
	while(t->next != NULL) {
		t = t->next;
	}
	t->next = temp;
}

void insert(int y, int x) {
	struct Node * temp = head;

	for (int i = 1; i < x-1; i++) {
		temp = temp->next;
	}

	struct Node * temp1 = (struct Node *)(malloc(sizeof(struct Node)));
	temp1->num = y;
	temp1->next = temp->next;
	temp->next = temp1;
}

void remove_t (int i) {
	struct Node * temp = head;
	if (i == 1) {
		head = head->next;
		return;
	}
	for (int x = 1; x < i - 1; i++) {
		temp = temp->next;
	}
	temp->next = temp->next->next;
}

void removee (int y) {
	struct Node * temp = head;
	int i = 1;
	int f = 0, index1 = -1, index2 = -1;
	while(temp != NULL) {
		if(temp->num == y && f == 0) {
			index1 = i;
			f = 1;
		}
		else if (temp->num == y) {
			index2 = i;
		}
		i++;
		temp = temp->next;
	} 
	printf("%d\n",index1);
	printf("%d\n",index2);
	if (index1 != -1) {
		remove_t(index1);
	}
	if (index2 != -1) {
		remove_t(index2-1);
	}
}

int fetch (int i) {
	struct Node * temp = head;
	for (int x = 1; x <= i; x++) {
		temp = temp->next;
	}
	return temp->num;
}

void reverse () {
	struct Node * ptr_curr = head;
	struct Node * ptr_prev = NULL;
	struct Node * ptr_next = NULL;
	while(ptr_curr != NULL) {
		ptr_next = ptr_curr->next;
		ptr_curr->next = ptr_prev;
		ptr_prev = ptr_curr;
		ptr_curr = ptr_next;
	}
	head = ptr_prev;
}

int main() {
	int n;
	scanf ("%d",&n);
	for (int x = 0; x < n; x++) {
		char s[20];
		int a;
		scanf("%s",s);
		if (s[0] == 'a') {
			scanf("%d", &a);
			add(a);
		}
		else if (s[0] == 'r' && s[2] == 'v') {
			reverse();
		}
		else if (s[0] == 'i') {
			int b;
			scanf("%d%d",&a, &b);
			insert(a,b);
		}
		else if (s[0] == 'f') {
			scanf("%d", &a);
			int r = fetch(a);
			printf("%d\n", r);
		}
		else {
			scanf("%d", &a);
			removee(a);
		}
		printList();
	}
}