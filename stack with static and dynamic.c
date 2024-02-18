8.) Develop a menu driven program to implement Stack with static and dynamic memory allocation mechanisms using array storage representation. (Represent Stack using structure)
 
a) Static Allocation :-
#include <stdio.h>
#include <stdlib.h>
#define size 10
struct Stack{
    int stk[size]; // Array to Implement Stack
    int top; // Index Of Top Of Stack
}S;
//Function to Push an Element into Stack 
void push(int X)
{
    //Checking if Stack is Full
    if(S.top==size-1)
        printf("Stack Overflow\n");
    else
        S.stk[++S.top] = X;
}
//Function to Pop an Element from Stack 
void pop()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
    {
        printf("Deleted Element : %d\n",S.stk[S.top]);
        S.top--;
    }
}
//Function to Display the top Element of Stack 
void peek()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
        printf("%d\n",S.stk[S.top]);
}
//Function to Display all Elements of Stack 
void display()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
    {
        printf("The Stack is :\n");
        for(int i=S.top;i>=0;i--)
            printf("%d\n",S.stk[i]);
    }
}
//Main Function
void main()
{
    int choice,X;
    S.top=-1; //Initailizing Empty Stack
    for(;;)
    {
        printf("Menu\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the value to be pushed : ");
                     scanf("%d",&X);
                     push(X);
                     break;
            case 2 : pop();
                     break;
            case 3 : peek();
                     break;
            case 4 : display();
                     break;
            case 5 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}
Output : 
Menu
1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter Your Choice : 1
Enter the value to be pushed : 10

Enter Your Choice : 1
Enter the value to be pushed : 20

Enter Your Choice : 1
Enter the value to be pushed : 30

Enter Your Choice : 1
Enter the value to be pushed : 40

Enter Your Choice : 1
Enter the value to be pushed : 50

Enter Your Choice : 1
Enter the value to be pushed : 60
Stack Overflow

Enter Your Choice : 3
50

Enter Your Choice : 4
The Stack is :
50
40
30
20
10

Enter Your Choice : 2
Deleted Element : 50

Enter Your Choice : 2
Deleted Element : 40
Enter Your Choice : 5
!! THANK YOU !!

b) Dynamic Allocation :-
#include <stdio.h>
#include <stdlib.h>
int size;
struct Stack{
    int *stk; //Pointer to Array storing Stack
    int top; //Index of Top of Stack
}S;
//Function to Push an Element into Stack 
void push(int X)
{
    //Checking if Stack is Full
    if(S.top==size-1)
    {
        printf("Stack Overflow\n");
        printf("Reallocating Memory\n");
        size++;
        //Reallocating Memory
        S.stk=(int *)realloc(S.stk,size*sizeof(int)); 
    }
    S.top++;
    *(S.stk+S.top)=X;
}
//Function to Pop an Element from Stack 
void pop()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
    {
        printf("Deleted Element : %d\n",*(S.stk+S.top));
        S.top--;
    }
}
//Function to Display the top Element of Stack 
void peek()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
        printf("%d\n",*(S.stk+S.top));
}
//Function to Display all Elements of Stack 
void display()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
    {
        printf("The Stack is :\n");
        for(int i=S.top;i>=0;i--)
            printf("%d\n",*(S.stk+i));
    }
}
void main()
{
    int choice,X;
    printf("Enter the size of Stack : ");
    scanf("%d",&size);
    //Allocating Memory for the Stack Array
    S.stk = (int *)calloc(size,sizeof(int)); 
    S.top=-1; //Initializing Empty Stack
    for(;;)
    {
        printf("Menu\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the value to be pushed : ");
                     scanf("%d",&X);
                     push(X);
                     break;
            case 2 : pop();
                     break;
            case 3 : peek();
                     break;
            case 4 : display();
                     break;
            case 5 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}
Output: 
Enter the size of Stack : 3
Menu
1.Push
2.Pop
3.Peek
4.Display
5.Exit
Enter Your Choice: 1
Enter the value to be pushed: 10
Enter Your Choice: 1
Enter the value to be pushed: 20
Enter Your Choice: 1
Enter the value to be pushed: 30
Enter Your Choice: 1
Enter the value to be pushed: 40
Stack Overflow
Reallocating Memory
Enter Your Choice: 3
40
Enter Your Choice: 4
The Stack is:
40
30
20
10
Enter Your Choice: 2
Deleted Element: 40
Enter Your Choice: 4
The Stack is:
30
20
10
Enter Your Choice: 5
!! THANK YOU!!
