7.) The annual examination results of 20 students are to be tabulated as follows: 
Roll No. Subject-1 Subject-2 Subject 3 
Develop an application to read the data and determine the following: 
a) Total marks obtained by each student. 
b) The highest marks in each subject and the Roll No. of the student. 
c) The student who obtained the highest total marks. 
import java.util.*; 
class Student{ 
    Scanner sc = new Scanner(System.in); 
    String name; 
    int m[] = new int[3]; 
    int total; 
    int i,N,choice,high1,high2,high3,hight; 
    Student S [] = new Student[2]; 
    void read(){ 
        System.out.println("Enter the number of Sudents : "); 
        N = sc.nextInt(); 
        for(int i=0;i<N;i++){ 
            S[i] = new Student(); 
            System.out.println("Enter the student name : "); 
            S[i].name = sc.next(); 
            System.out.println("Enter the marks scored in three subjects : "); 
            S[i].m[0] = sc.nextInt(); 
            S[i].m[1]= sc.nextInt(); 
            S[i].m[2] = sc.nextInt(); 
         }   
    } 
    void display(){  
        for(int i=0;i<N;i++){ 
            System.out.println(S[i].name+"\t"+S[i].m[0]+"\t"+S[i].m[1]+"\t"+S[i].m[2]); 
         } 
    } 
    void total(){ 
            total = m[0]+m[1]+m[2];     
    } 
    void totaldisplay(){  
        for(int i=0;i<N;i++){ 
            S[i].total(); 
            System.out.println(S[i].name+"\t"+S[i].m[0]+"\t"+S[i].m[1]+"\t"+S[i].m[2]+"\t"+S[i].to
 tal); 
         }  
    } 
    void subhigh(int j){ 
        int sh=0; 
        high1 = S[0].m[j]; 
        for(int i=1;i<N;i++){ 
            if(S[i].m[j]>high1){ 
                high1=S[i].m[j]; 
                sh=i; 
            } 
        } 
        System.out.println("The student with highest marks in Subject-"+(j+1)+" is 
"+S[sh].name); 
    } 
    void hightotal(){ 
        int ht=0; 
        hight = S[0].total; 
        for(int i=1;i<N;i++){ 
            if(S[i].total>hight){ 
                hight=S[i].total; 
                ht=i; 
            } 
        } 
        System.out.println("The student with highest marks in Total is "+S[ht].name); 
    }     
} 
public class P7 { 
    public static void main(String args[]){ 
        Scanner sc = new Scanner(System.in); 
        int choice; 
        Student student = new Student(); 
        System.out.println("Main Menu\n1.Read\n2.Display\n3.Total\n4.Subject
Highest\n5.Highest\n6.Exit"); 
        do{ 
            System.out.print("Enter your choice : "); 
            choice = sc.nextInt(); 
            switch(choice){ 
                case 1 : System.out.println("Enter the details of "+student.N+" Students"); 
                         student.read(); 
                         break; 
                case 2 : System.out.println("The Entered details are"); 
                         System.out.println("Name\tSub1\tSub-2\tSub-3"); 
                         student.display(); 
                         break; 
                case 3 : System.out.println("Name\tSub-1\tSub2\tSub-3\tTotal"); 
                         student.totaldisplay(); 
                         break; 
                case 4 : student.subhigh(0); 
                         student.subhigh(1); 
                         student.subhigh(2); 
                         break; 
                case 5 : student.hightotal(); 
                         break; 
            } 
        }while(choice!=6); 
    }    } 