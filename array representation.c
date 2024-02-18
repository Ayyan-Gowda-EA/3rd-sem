
3.) Develop a menu driven program to implement the following operations on array storage representation with static and dynamic memory allocation. i)Insert by position ii) Delete by position iii)Insert by key iv) Delete by key v) Insert by order vi) Search by key vii) Search by position viii) Reverse the contents.
//Static memory allocation
#include<stdio.h>
#include<stdlib.h>
int size=20; //Initializing Size Of Array
int ne = 0; //Initializing Number of Elements in Array
//Function to read an Array
void read (int x[])
{
    int i,n;
    printf("Enter the number of elements \n");
    scanf("%d", &n);
    printf("Enter the elements into the array \n");
    for (i=0; i<n;i++)
    scanf("%d",&x[i]);
    ne=n;
}
//Function to display an Array
void disp (int x[])
{
    int i;
    if (ne==0)
    {
        printf("Array empty\n");
        return;
        
    }
    printf("The array elements you entered are : ");
    for(i=0;i<ne;i++)
    printf("%d ",x[i]);
    printf("\n");
}
//Function to insert an element into Array at specified position
void insert_by_pos (int x[])
{
    int i, pos, ele;
    if(ne==size)
    {
        printf ("Array is full\n");
        return;
    }
    printf("Enter the element to be inserted : \n");
    scanf("%d", &ele);
    printf("Enter the position where the element should be inserted\n");
    scanf("%d", &pos);
    if(pos>=1&&pos<=ne+1)
    {
        for(i=ne;i>=pos;i--)
        {
            x[i]=x[i-1];
        }
        x[i]=ele;
        ne++;
    }
    else
    printf("Invalid position\n");
}
//Function to insert an element into Array in order
void insert_by_order (int x[])
{
    int i, ele;
    if (ne== size)
    {
        printf("Array is full....:(\n");
        return;
    }
    printf("Enter the element to be inserted...\n");
    scanf("%d",&ele);
    i=ne-1;
    while (i>=0&&x[i]>ele)
    {
        x[i+ 1] = x[i];
        i--;
    }
    x[i+1]=ele;
    ne++;
}
//Function to delete an element into Array at specified position
void delete_by_pos (int x[])
{
    int i, pos;
    if (ne ==0)
    {
        printf("Array is empty\n");
        return;
    }
    printf ("Enter the postion from where element should be deleted\n");
    scanf("%d", & pos);
    if (pos>= 1 && pos<=ne)
    {
    for(i=pos-1;i<ne-1;i++)
    {
        x[i] = x[i+1];
    }
    ne--;
    }
    else
    printf("Invalid position\n");
}
//Function to delete a key element into Array 
void delete_by_ele (int x[size])
{
    int i, ele;
    if (ne ==0)
    {
        printf ("Array is empty\n");
        return;
    }
    printf ("Enter the element that should be deleted\n");
    scanf("%d",&ele);
    for(i=0;i<ne&&x[i]!=ele;i++);
    if (i==ne)
    {
        printf ("Element not found in the array list\n");
        return;
    }
    for (;i<ne-1;i++)
    {
        x[i]=x[i+1];
    }
    ne--;
}
//Function to search an element in Array 
void search_by_key(int x[])
{
    int ele,i;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Enter the element that should be searched\n");
    scanf("%d",&ele);
    for(i=0;i<ne;i++)
    {
        if(x[i]==ele)
        printf("Element found at position %d\n",i+1);
    }
    printf("Element not found\n");
}
//Function to search an element in Array at specified position
void search_by_pos(int x[])
{
    int pos,i;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Enter the position from where element should be searched\n");
    scanf("%d",&pos);
    if(pos>=1&&pos<=ne)
    {
        i=pos-1;
        printf("Element at %d is %d\n",pos,x[i]);
    }
    else
    printf("Invalid position\n");
}
//Function to reverse the elements of Array
void reverse(int x[])
{
     int t,i;
    if(ne==0)
    {
        printf("Array is empty\n");
        return;
    }
    for(i=0;i<ne/2;i++)
    {
        t=x[i];
        x[i]=x[ne-i-1];
        x[ne-i-1]=t;
    }
}
//Main Function
void main()
{
    int a[size];//Array declaration
    int choice;
    printf("Menu\n1.Read\n2.Display\n3.Insert by Position\n4.Insert by Order\n5.Delete by Position\n6.Delete by Element\n7.Search by Key\n8.Search by Position\n9.Reverse\n10.Exit\n");
    for (;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: read(a);
                    disp(a);
                    break;
            case 2: disp(a);
                    break; 
            case 3: insert_by_pos(a);
                    disp(a);
                    break;
            case 4: insert_by_order(a);
                    disp(a);
                    break;
            case 5: delete_by_pos(a);
                    disp(a);
                    break;
            case 6: delete_by_ele(a);
                    disp(a);
                    break;
            case 7: search_by_key(a);
                    break;
            case 8: search_by_pos(a);
                    break;
            case 9: reverse(a);
                    disp(a);
                    break;
            case 10 : printf("!!THANK YOU!!\n");
                      exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}























Output:
Menu
1.Read
2.Display
3.Insert by Position
4.Insert by Order
5.Delete by Position
6.Delete by Element
7.Search by Key
8.Search by Position
9.Reverse
10.Exit
Enter Your Choice : 1
Enter the number of elements
5
Enter the elements into the array
1 2 3 4 5
The array elements you entered are : 1 2 3 4 5
Enter Your Choice : 3
Enter the element to be inserted :
6
Enter the position where the element should be inserted
6
The array elements you entered are : 1 2 3 4 5 6
Enter Your Choice : 5
Enter the postion from where element should be deleted
3
The array elements you entered are : 1 2 4 5 6
Enter Your Choice : 6
Enter the element that should be deleted
6
The array elements you entered are : 1 2 4 5
Enter Your Choice : 7
Enter the element that should be searched : 2
Element found at position 2
Enter Your Choice : 8
Enter the position from where element should be searched : 3
Element at 3 is 4
Enter Your Choice : 9 
The array elements you entered are : 5 4 2 1
Enter Your Choice : 10
!!THANK YOU!!
