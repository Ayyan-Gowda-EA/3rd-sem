7.) Develop a menu driven program to implement Circular Double linked list with Header node to perform various operations such as
a.	Insertion and Deletion at front/rear
b.	Insertion and Deletion at the specified position
c.	Delete by Key
d.	Search by key
e.	Create an ordered list
f.	Reverse a list
g.	Creating a copy of the list

#include <stdio.h>
#include<stdlib.h>
//Structure for a single Node
struct node 
{
    int item;
    struct node * next; //Pointer to next Node
    struct node * prev; //Pointer to Previous Node
};
//struct node * type defined as NODE
typedef struct node * NODE;
//Function to create a Node
NODE getnode(int val)
{
    NODE temp; //Pointer to newly created node
    temp = (NODE)malloc(sizeof(struct node));
    temp->item=val;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}
//Function to insert Node at front
NODE insertfront(NODE head,int val)
{
    NODE temp; //Pointer to newly created node
    temp = getnode(val);
    NODE first = head->next;
    if(head->next==NULL)
    {
        head->next = head->prev = temp;
        temp->prev = temp->next = head;
        return head;
    }
    else
    {
        temp -> next = first;
        first->prev = temp;
        temp -> prev = head;
        head->next=temp;
        return head;
    }
}
//Function to insert Node at Rear End
NODE insertrear(NODE head, int val)
{
    NODE temp,last;
    temp = getnode(val); //Pointer to newly created node
    last = head->prev; //Pointer to Current Node
    if(head->next==NULL)
    {
        head->next = head->prev = temp;
        temp->prev = temp->next = head;
        return head;
    }
    else
    {
        last->next=temp;
        temp->next=head;
        head->prev=temp;
        temp->prev=last;
        return head;
    }
}
//Function to delete Node at front
NODE deletefront(NODE head)
{
    NODE first=head->next;
    if(head->next==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        head->next=first->next;
        free(first);
        return head;
    }
}
//Function to delete Node at Rear End
NODE deleterear(NODE head)
{
    NODE last = head->prev; //Pointer to Current Node
    NODE temp=NULL; //Pointer to Previous Node
    if(head->next==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        head->prev=last->prev;
        free(last);
        return head;
    }
}
//Function to insert Node at Specified Position
NODE insertpos(NODE head, int val, int pos)
{
    NODE temp = getnode(val);
    NODE cur = head->next; //Pointer to Current Node
    NODE previous = NULL; //Pointer to Previous Node
    if(pos==1&&head==NULL)
    {
        head = insertfront(head,val);
        return head;
    }
     else if(pos!=1&&head==NULL)
    {
        printf("Invalid Position\n");
        return head;
    }
    else
    {
        while(pos!=1&&cur!=head)
        {
            previous=cur;
            cur = cur->next;
            pos--;
        }
        temp->next = cur;
        temp->prev = previous;
        previous->next = temp;
        cur->prev=temp;
        return head;
    } 
}
//Function to delete a Node at Specified Position
NODE deletepos(NODE head,int pos)
{
    NODE after = head->next; //Pointer to Next Node
    NODE cur = NULL; //Pointer to Current Node
    NODE previous = NULL; // Pointer to Previous Node
    if(head->next==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    while(pos != 0)
    {
        previous=cur;
        cur = after;
        after = after->next;
        pos--;
    }
    previous->next = after;
    after->prev=previous;
    free(cur); //Deleting the Current Node by Deallocating Memory
    cur = NULL;
    return head;
}
//Function to search a Key element in a list
int search(NODE head, int key)
{
    int i=1,flag=0,pos=0;
    NODE cur;
    cur = head->next;
    while(cur->next!=head)
    {
        if(cur->item==key)
        {
            flag = 1;
            pos = i;
            break;
        }
        cur = cur->next;
        i++;
    }
    if(flag==1)
    return pos;
    else
    return 0;
}
//Function to delete a Key element in a list
NODE deletebykey(NODE head,int key)
{
    int pos = search(head,key); //Position of the found Key
    if(pos!=0)
    {
        head = deletepos(head,pos);
        return head;
    }
    else
    {
        printf("Element not found\n");
        return head;
    }
}
//Function to display all elements in a list
NODE display(NODE head)
{
    NODE cur=head->next;
    if(head->next==NULL)
    {
        printf("List is Empty\n");
        return head;
    }
    else
    {
        while (cur!=head)
        {
            printf("%d ",cur->item);
            cur = cur->next;
        }
        return head;
    }
}
//Function to reverse a linked list
NODE reverse(NODE head)
{
    NODE temp,cur;
    cur = head->next;
    temp=NULL;
    do
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }while(cur!= head);
    if(temp!=NULL)
    head = temp->prev;
    display(head);
    return head;
}
//Function to create Ordered List
NODE orderlist(NODE head, int val)
{
    NODE temp = getnode(val);
    NODE previous = NULL;
    NODE cur = head->next;
    while(cur->next!=head)
    {
        if(cur->item>temp->item)
        {
            break;
        }
        previous=cur;
        cur = cur->next;
    }
    temp->next = cur;
    temp->prev = previous;
    previous->next = temp;
    cur->prev=temp;
    return head;
}
//Function to create a Copy List
NODE createcopy(NODE head, NODE copy)
{
    NODE cur=head->next;
    while(cur!=head)
    {
        copy=insertrear(copy,cur->item);
        cur=cur->next;
    }
    return copy;
}
//Main Function
void main()
{
    NODE head = getnode(0); //Pointer to header node of list
    NODE copy = getnode(0); //Poiner to header node of copied list 
    int choice;
    int key,val,pos;
    printf("\nMain Menu\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Insert By Pos\n6.Delete by Pos\n7.Search\n8.Delete By Key\n9.Display\n10.Reverse\n11.Ordered List\n12.Create Copy\n13.Exit\n");
    for(;;)
    {
        printf("\nEnter your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the value : ");
                     scanf("%d",&val);
                     head = insertfront(head,val);
                     break;
            case 2 : printf("Enter the value : ");
                     scanf("%d",&val);
                     head = insertrear(head,val);
                     break;
            case 3 : head = deletefront(head);
                     printf("Deletion Successfull\n");
                     break;
            case 4 : head = deleterear(head);
                     printf("Deletion Successfull\n");
                     break;
            case 5 : printf("Enter the value : ");
                     scanf("%d",&val);
                     printf("Enter the position : ");
                     scanf("%d",&pos);
                     head = insertpos(head,val,pos);
                     printf("Insertion Succesfull\n");
                     break;
            case 6 : printf("Enter the position : ");
                     scanf("%d",&pos);
                     head = deletepos(head,pos);
                     printf("Deletion Succesfull\n");
                     break;
            case 7 : printf("Enter the Key : ");
                     scanf("%d",&key);
                     pos = search(head,key);
                     if(pos!=0)
                     printf("The Key found at %d pos\n",pos);
                     else
                     printf("Element not found\n");
                     break;
            case 8 : printf("Enter the Key : ");
                     scanf("%d",&key);
                     head = deletebykey(head,key);
                     printf("Deletion Successfull\n");
                     break;
            case 9 : display(head);
                     break;
            case 10 : head = reverse(head);
                      break;
            case 11 : printf("Enter the value : ");
                     scanf("%d",&val);
                      head = orderlist(head,val);
                      break;
            case 12 : printf("Copied List : ");
                      copy = createcopy(head,copy);
                      display(copy);
                      break;
            case 13 : printf("!!THANK YOU!!\n");
                     exit(0);
            default : printf("Invalid Choice\n Enter again\n");
        }
    }
}










Output :
Main Menu
1.Insert Front
2.Insert Rear
3.Delete Front
4.Delete Rear
5.Insert By Pos
6.Delete by Pos
7.Search
8.Delete By Key
9.Display
10.Reverse
11.Ordered List
12.Create Copy
13.Exit

Enter your Choice :1
Enter the value : 5

Enter your Choice :2
Enter the value : 15

Enter your Choice :2
Enter the value : 35

Enter your Choice :5
Enter the value : 25
Enter the position : 3

Enter your Choice :9
5 15 25 35

Enter your Choice :3
Deletion Successful

Enter your Choice :4
Deletion Successful

Enter your Choice :1
Enter the value : 5

Enter your Choice :2
Enter the value : 35

Enter your Choice :9
5 15 25 35

Enter your Choice :7
Enter the Key : 15
The Key found at 2 pos
Enter your Choice :11
Enter the value : 10

Enter your Choice :9
5 10 15 25 35

Enter your Choice :12
Copied List : 5 10 15 25 35

Enter your Choice :10
35 25 15 10 5

Enter your Choice :13
!!THANK YOU!!



























