1.) Define a structure called Student with the members: name, reg_no, marks in 3 tests and average_ marks. Develop a menu driven program to perform the following by writing separate function for each operation: a) read information of N students b) display student’s information c) to calculate the average of best two test marks of each student. Note: Illustrate the use of pointer to an array of structure and allocate memory dynamically using malloc () /calloc()/realloc().
#include <stdio.h>
#include <stdlib.h>
//N->Number Of Students
int N,size,i,j;
//Defining a Structure named Student
struct student{
    char name[30];
    int reg_no;
    int marks[3];
    float avg;
};
//Function Prototypes
void read(struct student *);
void disp(struct student *);
void avg(struct student *);
//Main Function
void main()
{
    //Declaring Pointer to Student Structure
    struct student *st;
    printf("Enter the size:");
    scanf("%d",&size);
    //Dynamically Allocating Memory for array of Structures
    st = (struct student *) malloc(size*sizeof(struct student));
    int choice;
    for(;;)
    {
        printf("Enter Your Choice:\n");
        printf("1.Input\n2.Display\n3.Average\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : read(st);
                     break;
            case 2 : disp(st);
                     break;
            case 3 : avg(st);
                     break;
            case 4 : printf("!!THANK YOU!!\n");
                     exit(0);
            default : printf("Invalid Choice\n!!Thank You!!\n");
                      free(st); st=NULL;             
        }
    }
}
//Function to read Student Details
void read(struct student *st)
{
    
    printf("Enter the number of Students:\n");
    scanf("%d",&N);
    if(N>size)
    {
        printf("insufficient Space\n");
        printf("Creating space by reallocating memory\n");
        st = (struct student *) realloc(st,(N-size)*sizeof(struct student));
    }
    for(i=0;i<N;i++)
    {
        printf("Enter the Name and Reg_no of Student %d\n",i+1);
        scanf("%s%d",(st+i)->name,&(st+i)->reg_no);
        printf("Enter the marks Scored in three tests:\n");
        for(j=0;j<3;j++)
        {
            scanf("%d",&(st+i)->marks[j]);
        } 
    }
}
//Function to display Student Details
void disp(struct student *st)
{
    if(N==0)
    {
        printf("List is Empty!");
        return;
    }
    printf("The details of %d students are:\n",N);
    printf("Reg-No\tName\tTest1\tTest2\tTest3\t\n");
    for(i=0;i<N;i++)
    {
        printf("%d\t%s\t",(st+i)->reg_no,(st+i)->name);
        for(j=0;j<3;j++)
        {
            printf("%d\t",(st+i)->marks[j]);
        }
        printf("\n");
    }
} 
//Function to calculate average of Students and display 
void avg(struct student *st)
{
    int k,temp,sum[N]; 
    //temp : variable used for swapping
    //sum[N] : Array to Store Total marks of N students
    for(i=0;i<N;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3-j-1;k++)
            {
                if((st+i)->marks[k]>(st+i)->marks[k+1])
                {
                    temp = (st+i)->marks[k];
                    (st+i)->marks[k] = (st+i)->marks[k+1];
                    (st+i)->marks[k+1] = temp;
                }
            }
        }
    }
    for(i=0;i<N;i++)
    {
        sum[i] = (st+i)->marks[1] + (st+i)->marks[2];
        (st+i)->avg = (float)sum[i]/2;
    }
    printf("The details of %d students are:\n",N);
    printf("Reg-No\tName\t\tTest1\tTest2\tTest3\tAverage\n");
    for(i=0;i<N;i++)
    {
        printf("%d\t%s\t\t",(st+i)->reg_no,(st+i)->name);
        for(j=0;j<3;j++)
        {
            printf("%d\t",(st+i)->marks[j]);
        }
        printf("%.2f",(st+i)->avg);
        printf("\n");
    }
}


Output : 

Enter the size:2
Enter Your Choice:
1.Input
2.Display
3.Average
4.Exit
1
Enter the number of Students:
2
Enter the Name and Reg_no of Student 1
Vinod 
26
Enter the marks Scored in three tests:
20
17
18
Enter the Name and Reg_no of Student 2
Reddy
41
Enter the marks Scored in three tests:
18
19
20
Enter Your Choice:
1.Input
2.Display
3.Average
4.Exit
2
The details of 2 students are:
Reg-No  Name    Test1   Test2   Test3
26      Vinod   20      17      18
41      Reddy   18      19      20
Enter Your Choice:
1.Input
2.Display
3.Average
4.Exit
3
The details of 2 students are:
Reg-No  Name            Test1   Test2   Test3   Average
26      Vinod           17      18      20      19.00
41      Reddy           18      19      20      19.50
Enter Your Choice:
1.Input
2.Display
3.Average
4.Exit
4
!!THANK YOU!!

