#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

struct sNode
{
    struct node *t;
    struct sNode *next;
};

void push(struct sNode** top_ref, struct node *t);
struct node *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);
void preOrder(struct node *root) {
    struct node *current = root;
    struct sNode *s = NULL;
    struct node *temp;
    push(&s, current);
    while (isEmpty(s)==false) {
        temp=pop(&s);
        printf("%d ", temp->data);
        if (temp->right)
            push(&s, temp->right);
        if (temp->left)
            push(&s, temp->left);
    }
}

void postOrder(struct node *root) {
    struct node *current = root;
    struct sNode *s1 = NULL;
    struct sNode *s2 = NULL;
    struct node *temp;
    push(&s1, current);

    while (isEmpty(s1)==false) {
        temp=pop(&s1);
        push(&s2,temp);
        if(temp->left)
            push(&s1,temp->left);
        if(temp->right)
            push(&s1,temp->right);
    }
    while(isEmpty(s2)==false){
        temp=pop(&s2);
        printf("%d ",temp->data);
    }
}

void push(struct sNode** top_ref, struct node *t)
{
    struct sNode* new_tNode =
            (struct sNode*) malloc(sizeof(struct sNode));

    if(new_tNode == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }
    new_tNode->t  = t;
    new_tNode->next = (*top_ref);
    (*top_ref)    = new_tNode;
}

bool isEmpty(struct sNode *top)
{
    return (top == NULL)? 1 : 0;
}

struct node *pop(struct sNode** top_ref)
{
    struct node *res;
    struct sNode *top;

    if(isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

node *create()
{
    node *p;
    int x;
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    p->left=create();
    p->right=create();
    return p;
}

int main()
{
    int num;
    scanf("%d",&num);
    node *root;
    root=create();
    preOrder(root);
    printf("\n");
    postOrder(root);
    return 0;
}

