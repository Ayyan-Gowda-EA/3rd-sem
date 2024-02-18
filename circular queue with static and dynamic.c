10.b) Develop a menu driven program to implement Circular Queue with static and dynamic memory allocation mechanisms using array storage representation.(Represent Queue using structure)
//Circular Queue Static
#include <stdio.h>
#include <stdlib.h>
#define size 3
struct Queue{
    int front; //Index Of front element in Queue
    int rear; //Index of rear element in Queue
    int queue[size]; //Array to store Queue
}Q;
//Function to insert an element to rear of Queue
void insert()
{
    int val;
    //Checking if Queue is Full
    if(Q.front==0&&Q.rear==size-1)
    {
        printf("Queue is Full\n");
        return;
    }
    if(Q.front==-1&Q.rear==-1)
        Q.front=0; //Initializing First element
    printf("Enter the element to be inserted : ");
    scanf("%d",&val);
    Q.rear=(Q.rear+1)%size;
    Q.queue[Q.rear] = val;
    printf("Insertion Successful\n");
}
//Function to delete the front element of Queue
void delete()
{
    //Checking if Queue is Empty
    if(Q.front==-1)
    {
        printf("Queue is Empty\n");
    }
    else if(Q.front==Q.rear)
    {
        printf("Deleted Element : %d\n",Q.queue[Q.front]);
        Q.front=Q.rear=-1;
    }
    else
    {
        //Deleting Element from front
        printf("Deleted Element : %d\n",Q.queue[Q.front]);
        Q.front=(Q.front+1)%size;
    }
}
//Function Display all elements of Queue
void display()
{
    int i;
    //Checking if Queue is Empty
    if(Q.front==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        if(Q.front<Q.rear)
        for(i=Q.front;i<=Q.rear;i++)
        {
            printf("%d\n",Q.queue[i]);
        }
        else
        {
            for(i=Q.front;i<=size-1;i++)
                printf("%d\n",Q.queue[i]);
            for(i=0;i<=Q.rear;i++)
                printf("%d\n",Q.queue[i]);
        }
    }
}
void main()
{
    int choice,val;
    Q.front=Q.rear=-1; //Initializing Empty Queue
    printf("Main Menu\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert();
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
Insertion Successful
Enter Your choice : 1
Enter the element to be inserted : 20
Insertion Successful
Enter Your choice : 1
Enter the element to be inserted : 30
Insertion Successful
Enter Your choice : 3
10
20
30
Enter Your choice : 1
Queue is Full
Enter Your choice : 2 
Deleted Element : 10
Enter Your choice : 1
Enter the element to be inserted : 40
Insertion Successful
Enter Your choice : 3
20
30
40
Enter Your choice : 4
!! THANK YOU !!










//Circular Queue Dynamic
#include <stdio.h>
#include <stdlib.h>
int size;
struct Queue{
    int front; //Index Of front element in Queue
    int rear; //Index of rear element in Queue
    int *queue; //Base address of array to store Queue
}Q;
//Function to insert an element to rear of Queue
void insert()
{
    int val;
    //Checking if Queue is Full
    if(Q.front==0&&Q.rear==size-1)
    {
        printf("Queue is Full\n");
        printf("Reallocating Memory\n");
        size++;
        Q.queue = (int *)realloc(Q.queue,size*sizeof(int));
    }
    if(Q.front==-1&Q.rear==-1)
        Q.front=0; //Initializing First element
    printf("Enter the element to be inserted : ");
    scanf("%d",&val);
    Q.rear=(Q.rear+1)%size;
    *(Q.queue+Q.rear) = val;
    printf("Insertion Successful\n");
}
//Function to delete the front element of Queue
void delete()
{
    //Checking if Queue is Empty
    if(Q.front==-1)
    {
        printf("Queue is Empty\n");
    }
    else if(Q.front==Q.rear)
    {
        printf("Deleted Element : %d\n",*(Q.queue+Q.front));
        Q.front=Q.rear=-1;
    }
    else
    {
        //Deleting Element from front
        printf("Deleted Element : %d\n",*(Q.queue+Q.front));
        Q.front=(Q.front+1)%size;
    }
}
//Function Display all elements of Queue
void display()
{
    int i;
    //Checking if Queue is Empty
    if(Q.front==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        if(Q.front<Q.rear)
        for(i=Q.front;i<=Q.rear;i++)
        {
            printf("%d\n",*(Q.queue+i));
        }
        else
        {
            for(i=Q.front;i<=size-1;i++)
            {
                printf("%d\n",*(Q.queue+i));
            }
            for(i=0;i<=Q.rear;i++)
            {
                printf("%d\n",*(Q.queue+i));
            }
        }
    }
}
void main()
{
    int choice,val;
    Q.front=Q.rear=-1; //Initializing Empty Queue
    printf("Enter the Size : ");
    scanf("%d",&size);
    Q.queue=(int *)malloc(size*sizeof(int)); //Dynamically Allocating Array for Queue
    printf("Main Menu\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert();
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
Enter the Size : 3
Main Menu
1.Insert
2.Delete
3.Display
4.Exit
Enter Your choice : 1
Enter the element to be inserted : 10
Insertion Successful
Enter Your choice : 1
Enter the element to be inserted : 20
Insertion Successful
Enter Your choice : 1
Enter the element to be inserted : 30
Insertion Successful
Enter Your choice : 3
10
20
30
Enter Your choice : 1
Queue is Full
Reallocating Memory
Enter the element to be inserted : 40
Insertion Successful
Enter Your choice : 3
10
20
30
40
Enter Your choice : 2
Deleted Element : 10
Enter Your choice : 3
20
30
40
Enter Your choice : 4
!! THANK YOU !!


