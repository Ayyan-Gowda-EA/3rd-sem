11. b) Develop a menu driven program to implement Priority Queue with static and dynamic memory allocation mechanisms using array storage representation. (Represent Queue using structure)
//Ascending Priority Queue Static
#include <stdio.h>
#include <stdlib.h>
#define size 5
struct Queue
{
    int a[size]; //Array to store Queue
    int front; //Index Of front element in Queue
    int rear; //Index of rear element in Queue
}Q;
//Function to check Priority
int prioritycheck(int X)
{
    int i=0;
    while(Q.a[i]<X&&i<=Q.rear)
    {
        i++;
    }
    return i;
}
//Function to insert an element to Queue
void insert(int X)
{
    int i,pos;
    //Checking if Queue is Full
    if(Q.rear==size-1)
    printf("Queue is Full\n");
    else if(Q.rear==-1&&Q.front==-1)
    {
        Q.rear=Q.front=0; //Initializing First element
        Q.a[Q.rear]=X;
    }
    else
    {
        pos = prioritycheck(X);
        Q.rear++;
        for(i=Q.rear;i>=pos;i--)
        {
            Q.a[i]=Q.a[i-1];
        } 
        Q.a[pos]=X;
    }
}
//Function to delete the front element of Queue
void delete()
{
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else if(Q.front==Q.rear)
    {
        printf("Deleted Element : %d\n",Q.a[Q.front]);
        Q.front=Q.rear=-1;
    }
    else
    {
        //Deleting Element from front
        printf("Deleted Element : %d\n",Q.a[Q.front]);
        Q.front++;
    }
}
//Function Display all elements of Queue
void display()
{
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else
    {
        for(int i=Q.front;i<=Q.rear;i++)
        printf("%d ",Q.a[i]);
        printf("\n");
    }
}
void main()
{
    int choice,val;
    Q.front=-1;Q.rear=-1; //Initializing Empty Queue
    printf("Main Menu\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the element to be inserted : ");
                     scanf("%d",&val);
                     insert(val);
                     break;
            case 2 : delete();
                     break;
            case 3 : display();
                     break;
            case 4 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\nEnter Again\n");
        }
    }
}
Output:
Main Menu
1.Insert
2.Delete
3.Display
4.Exit
Enter Your choice : 1
Enter the element to be inserted : 10
Enter Your choice : 1
Enter the element to be inserted : 5
Enter Your choice : 1
Enter the element to be inserted : 20
Enter Your choice : 1
Enter the element to be inserted : 15
Enter Your choice : 1
Enter the element to be inserted : 25
Enter Your choice : 1
Enter the element to be inserted : 30
Queue is Full
Enter Your choice : 3
5 10 15 20 25
Enter Your choice : 2
Deleted Element : 5
Enter Your choice : 3
10 15 20 25
Enter Your choice : 4
!! THANK YOU !!
 


















//Ascending Priority Queue Dynamic
#include <stdio.h>
#include <stdlib.h>
int size;
struct Queue
{
    int *a; //Base address of array to store Queue
    int front; //Index Of front element in Queue
    int rear; //Index of rear element in Queue
}Q;
//Function to check Priority
int prioritycheck(int X)
{
    int i=0;
    while(*(Q.a+i)<X&&i<=Q.rear)
    {
        i++;
    }
    return i;
}
//Function to insert an element to Queue
void insert(int X)
{
    int i,pos;
    //Checking if Queue is Full
    if(Q.rear==size-1)
    {
        printf("Queue is Full\n");
        printf("Reallocating Memory\n");
        size++;
        Q.a= (int *)realloc(Q.a,size*sizeof(int));//Reallocating Memory for Queue
    }
    if(Q.rear==-1&&Q.front==-1)
    {
        Q.rear=Q.front=0; //Initializing First element
        *(Q.a+Q.rear)=X;
    }
    else
    {
        pos = prioritycheck(X);
        Q.rear++;
        for(i=Q.rear;i>=pos;i--)
        {
            *(Q.a+i)=*(Q.a+i-1);
        } 
        *(Q.a+pos)=X;
    }
}
//Function to delete the front element of Queue
void delete()
{
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else if(Q.front==Q.rear)
    {
        printf("Deleted Element : %d\n",*(Q.a+Q.front));
        Q.front=Q.rear=-1;
    }
    else
    {
        //Deleting Element from front
        printf("Deleted Element : %d\n",*(Q.a+Q.front));
        Q.front++;
    }
}
//Function Display all elements of Queue
void display()
{
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else
    {
        for(int i=Q.front;i<=Q.rear;i++)
        printf("%d ",*(Q.a+i));
        printf("\n");
    }
}
void main()
{
    int choice,val;
    Q.front=-1;Q.rear=-1; //Initializing Empty Queue
    printf("Enter the Size : ");
    scanf("%d",&size);
    Q.a=(int *)malloc(size*sizeof(int)); //Dynamically Allocating Array for Queue
    printf("Main Menu\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the element to be inserted : ");
                     scanf("%d",&val);
                     insert(val);
                     break;
            case 2 : delete();
                     break;
            case 3 : display();
                     break;
            case 4 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\nEnter Again\n");
        }
    }
}

Output:
Enter the Size : 2
Main Menu
1.Insert
2.Delete
3.Display
4.Exit
Enter Your choice : 1
Enter the element to be inserted : 10
Enter Your choice : 1
Enter the element to be inserted : 5
Enter Your choice : 1
Enter the element to be inserted : 15
Queue is Full
Reallocating Memory
Enter Your choice : 3
5 10 15
Enter Your choice : 2
Deleted Element : 5
Enter Your choice : 3
10 15
Enter Your choice : 4
!! THANK YOU !!















