#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left,*right;
};

struct node *stack[50];
int top=-1;

void push(struct node *item)
{
    if(top==49)
    {
        printf("Stack Overflow.");
        return;
    }
    top=top+1;
    stack[top]=item;
}

struct node * pop()
{
    struct node * item;
    if(top==-1)
    {
        printf("Stack underflow");
        return 0;
    }
    item=stack[top];
    top=top-1;
    return item;
}

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
        return 0;
}

struct node * create()
{
    struct node *newl;
    int x;

    newl=(struct node *)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newl->data=x;
    printf("\nEnter left child:");
    newl->left=create();
    printf("\nEnter right child:");
    newl->right=create();
    return newl;
}

void preorder(struct node * root)
{
    struct node * ptr=root;
    if(ptr==NULL)
    {
        printf("Empty tree");
        return;
    }
    push(ptr);
    while(!isEmpty())
    {
        ptr=pop();
        printf("%d\t",ptr->data);
        if(ptr->right!=NULL)
            push(ptr->right);
        if(ptr->left!=NULL)
            push(ptr->left);
    }
}

void postorder(struct node * root)
{
    struct node *q,*ptr=root;
    if(ptr==NULL)
    {
        printf("Empty tree");
        return;
    }
    q=root;
    while(1)
    {
        while(ptr->left!=NULL)
        {
            push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL || ptr->right==q)
        {
            printf("%d\t",ptr->data);
            q=ptr;
            if(isEmpty())
            {
                return;
            }
            ptr=pop();
        }
        push(ptr);
        ptr=ptr->right;
    }
}

void inorder(struct node * root)
{
    struct node * ptr=root;
    if(ptr==NULL)
    {
        printf("Empty tree");
        return;
    }
    while(1)
    {
        while(ptr->left!=NULL)
        {
            push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL)
        {
            printf("%d\t",ptr->data);
            if(isEmpty())
                return ;
            ptr=pop();
        }
        printf("%d\t",ptr->data);
        ptr=ptr->right;
    }
}

int main()
{
    struct node *root;
    root=0;
    root=create();

    printf("\nPostorder:");
    postorder(root);

    printf("\nPreorder:");
    preorder(root);

    printf("\nInorder:");
    inorder(root);
}
