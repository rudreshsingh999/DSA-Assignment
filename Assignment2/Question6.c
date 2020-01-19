#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node * next;
    struct Node * prev;
};

// struct Node * head = NULL;
// struct Node * tail = NULL;

void printList (struct Node ** head) {
    struct Node * temp = *head;
    while(temp != NULL) {
        printf("%d ",temp->num);
        temp = temp->next;
    }
    printf("\n");
}

void insertBeg (int n, struct Node ** head) {
    struct Node * temp = (struct Node *)(malloc(sizeof(struct Node)));
    temp->num = n;
    temp->next = *head;
    temp->prev = NULL;
    *head = temp;
}

void insertEnd (int n, struct Node ** head) {
    struct Node * temp = (struct Node *)(malloc(sizeof(struct Node)));
    temp->num = n;
    temp->next = NULL;
    struct Node * tmp1 = *head;
    if(tmp1 == NULL) {
        *head = temp;
        temp->prev = NULL;
        return;
    }
    while (tmp1->next != NULL)
        tmp1 = tmp1->next;
    tmp1->next = temp;
    temp->prev = tmp1;
}

int main() {
    struct Node * head1 = NULL;
    while(1) {
        int n;
        char ch;
        scanf("%d%c", &n,  &ch);
        insertEnd(n, &head1);
        if(ch == '\n')
            break;
    }
    printList(&head1);

    struct Node * head2 = NULL;
    while(1) {
        int n;
        char ch;
        scanf("%d%c", &n,  &ch);
        insertEnd(n, &head2);
        if(ch == '\n')
            break;
    }
    printList(&head2);

    struct Node * tmp1 = head1;
    struct Node * tmp2 = head2;

    struct Node * head3 = NULL;
    while(tmp1 != NULL && tmp2 != NULL) {
        if(tmp1->num < tmp2->num) {
            insertEnd(tmp1->num, &head3);
            tmp1 = tmp1->next;
        }
        else {
            insertEnd(tmp2->num, &head3);
            tmp2 = tmp2->next;
        }
    }


    while(tmp2 != NULL) {
        insertEnd(tmp2->num, &head3);
        tmp2 = tmp2->next;
    }
    while(tmp1 != NULL) {
        insertEnd(tmp2->num, &head3);
        tmp1 = tmp1->next;
    }

    printList(&head3);
}