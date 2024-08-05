#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr!= NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//case 1--insert at start
int insertATstart(struct Node* head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;

}
//case 2 ---insert at end
void insertAtend(struct Node * head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    ptr->data=data;
    ptr->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
}
void insertAtindex(struct Node *head,int data ,int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    int i=1 ;
    while( i<index-1){
        i++;
        p=p->next;

    }
    ptr->next=p->next;
    p->next=ptr;

}
void insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
}

void deleteAtindex(struct Node *head,int index){
    int i=1;
    struct Node *p=head;
    struct Node *q=head->next;
    while(i<index){
        i++;
        p=p->next;
        q=p->next;
    }
    p->next=q->next;
    free(q);
}
void deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}
void * deleteAtIn(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(p->data!=value )
    {
        p = p->next;
        q = q->next;
    }

    p->next=q->next;
    free(q);

}



int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    linkedListTraversal(head);
    printf("-----\n");

    head=insertATstart(head,20);
    linkedListTraversal(head);
    printf("-----\n");

    insertAtend(head,90);
    linkedListTraversal(head);
    printf("-----\n");

    insertAtindex(head,40,3);
    linkedListTraversal(head);
    printf("-----\n");

    insertAfterNode(head,second,67);
    linkedListTraversal(head);
    printf("-----\n");

    deleteAtindex(head,3);
    linkedListTraversal(head);
    printf("-----\n");

    deleteAtIn(head,67);
    linkedListTraversal(head);



    return 0;
}
