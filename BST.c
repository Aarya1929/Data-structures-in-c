#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root= NULL;

struct node* createNode(int x)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data= x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *Insert(int x)
{
    struct node *r;
    r = createNode(x);

    if(root == NULL){
        root = r;
        return 0;
      }
    else {
        struct node *q = root, *p = NULL;

        while(1) {
            p = q;

            if(x < q->data) {
                q = q->left;
                if(q == NULL) {
                    p->left = r;
                    return 0;
                }
            }
            else {
                q = q->right;
                if(q == NULL) {
                    p->right = r;
                    return 0;
                }
            }
        }
    }
}

struct node* minNode(struct node *root) {
    if (root->left != NULL)
        return minNode(root->left);
    else
        return root;
}

struct node* Delete(struct node *root, int x) {
    if(root == NULL){
        return NULL;
    }
    else {
        if(x < root->data)
            root->left = Delete(root->left, x);
        else if(x > root->data)
            root->right = Delete(root->right, x);

        else {
            if(root->left == NULL && root->right == NULL)
                root = NULL;
            else if(root->left == NULL) {
                root = root->right;
            }
            else if(root->right == NULL) {
                root = root->left;
            }

            else {
                struct node *temp = minNode(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void Display(struct node* root, int level)
{
    if (root == NULL)
        return;
    else if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        Display(root->left, level - 1);
        Display(root->right, level - 1);
    }
}

void DisplayLvl(struct node* root)
{
     int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        Display(root, i);
}

void inOrder(struct node* root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void mirror(struct node* node)
{
    if (node == NULL)
        return;
    else {
        struct node* temp;

        mirror(node->left);
        mirror(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

int main()
{
    int ch, element;

    printf("\nMENU:");
    printf("\n1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display tree Levelwise \n");
    printf("4.Display Mirror Image \n");
    printf("5.Display Height \n");
    printf("6.Exit\n");

    do{
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter node to insert : ");
            scanf("%d", &element);
            Insert(element);
            break;
        case 2:
            printf("\nEnter node to Delete : ");
            scanf("%d", &element);
            Delete(root, element);
            break;
        case 3:
            DisplayLvl(root);
            break;
         case 4:
             printf("\nInorder:");
             inOrder(root);
             mirror(root);
             printf("\nMirror image of the tree:");
             inOrder(root);
            break;
         case 5:
            printf("Height: %d", height(root));
            break;
        case 6:
            exit(0);
        default :
            printf("\nWrong choice");
            break;
        }
    }while(ch<6);
}
