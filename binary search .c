12. a) Develop a menu driven program to implement binary search tree and traversal techniques.
 
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE getnode(int X)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node)); //Dynamically Allocating a new Node
    temp->item = X;
    temp->llink=temp->rlink=NULL;
    return temp;
}
NODE insert(NODE root, int X)
{
    NODE temp = getnode(X);
    if(root==NULL)
    return temp;
    if(X<root->item)
    root->llink = insert(root->llink,X);
    else
    root->rlink = insert(root->rlink,X);
    return root;
}
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\n",root->item);
        inorder(root->rlink);
    }
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->item);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n",root->item);
    }
}
void main()
{
    int choice,X;
    NODE root=NULL;
    printf("Menu\n1.Insert\n2.InOrder\n3.PreOrder\n4.PostOrder\n5.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter an Element : ");
                     scanf("%d",&X);
                     root = insert(root,X);
                     break;
            case 2 : inorder(root);
                     break;
            case 3 : preorder(root);
                     break;
            case 4 : postorder(root);
                     break;
            case 5 : printf("!!THANK YOU!!\n");
                     exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}
















Output: 
Menu
1.Insert
2.InOrder
3.PreOrder
4.PostOrder
5.Exit
Enter Your Choice : 1
Enter an Element : 100
Enter Your Choice : 1
Enter an Element : 50
Enter Your Choice : 1
Enter an Element : 75
Enter Your Choice : 1
Enter an Element : 25
Enter Your Choice : 1
Enter an Element : 150
Enter Your Choice : 1
Enter an Element : 125
Enter Your Choice : 1
Enter an Element : 175
Enter Your Choice : 2
25
50
75
100
125
150
175
Enter Your Choice : 3
100
50
25
75
150
125
175
Enter Your Choice : 4
25
75
50
125
175
150
100
Enter Your Choice : 5
!!THANK YOU!!


