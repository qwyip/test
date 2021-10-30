#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

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
void swapTree(struct node*node)
{
    if(node==NULL) return;
    struct node*temp=node->left;
    node->left=node->right;
    node->right=temp;
    swapTree(node->left);
    swapTree(node->right);
}
void preorder(node *t) //address of root node is passed in t
{
    if(t!=NULL)
    {
        printf("%d ",t->data); //visit the root
        preorder(t->left); //preorder traversal on left subtree
        preorder(t->right); //preorder traversal om right subtree
    }
      while(t!=NULL){
          t=t->left;
      }

}

void inorder(node *t) //address of root node is passed in t
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
    }
}

int main()
{
    int num;
    scanf("%d",&num);
    node *root;
    root=create();
    swapTree(root);
    preorder(root);
    printf("\n");
    inorder(root);
    return 0;
}

