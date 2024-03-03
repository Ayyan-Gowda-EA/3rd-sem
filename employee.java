9) Given that an EMPLOYEE class contains the following members:                             
Members: Employee ID, Employee Name, Department name &amp; Basic Pay                
Methods: To read each employee details, to calculate Gross Pay and to print the employee 
details. Develop an application to read data of N employees and compute the Gross Pay 
and Net Pay of each employee.         
Gross Pay = Basic Pay + DA + HRA (DA = 58% of Basic Pay, HRA = 16% of Basic Pay)    
Net Pay = Gross – Income Tax                  
Income Tax calculated as follows:          
Gross Pay - Up to 2 lakhs – Nil                    
Above 2 and up to 3 lakhs - 10% of the Gross Pay                 
Above 3 and up to 5 lakhs - 15% of the Gross Pay and                
Above 5 lakhs 30 % of the Gross Pay, an additional charge of 2% of the tax will be added 
to total tax 
import java.util.*; 
class Employee{ 
    int ID; 
    String name,dept; 
    float basicpay,grosspay,netpay; 
    Scanner sc = new Scanner(System.in); 
    void read(){ 
        System.out.println("Enter Employee ID : "); 
        ID = sc.nextInt(); 
        System.out.println("Enter Employee Name : "); 
        name = sc.next(); 
        System.out.println("Enter Employee Department Name : "); 
        dept = sc.next(); 
        System.out.println("Enter Basic Pay of the Employee : "); 
        basicpay = sc.nextFloat(); 
    } 
    void grosspay(){ 
        float da = 0.58F*basicpay; 
        float hra = 0.16F*basicpay; 
        grosspay=basicpay + da + hra; 
    } 
    void netpay(){ 
        Employee emp = new Employee(); 
        emp.grosspay(); 
        float tax; 
        if(grosspay<200000){ 
            tax=0; 
        } 
        else if(grosspay<300000){ 
            tax = 0.10F*grosspay; 
        } 
        else if(grosspay<500000){ 
            tax = 0.15F*grosspay; 
        } 
        else{ 
            tax = .30F*grosspay; 
            float addtax = 0.02F*tax; 
            tax = tax+addtax; 
        } 
        netpay = grosspay - tax; 
    } 
    void display(){ 
        Employee emp = new Employee(); 
        emp.grosspay(); 
        emp.netpay(); 
        System.out.println(ID+"\t"+name+"\t\t"+dept+"\t\t"+basicpay+"\t\t"+grosspay+"\t\t"+netp
 ay); 
    } 
} 
public class P9{ 
    public static void main(String args[]){ 
        Scanner sc = new Scanner(System.in); 
        int i,choice,N; 
        System.out.println("Enter the number of Employee : "); 
        N = sc.nextInt(); 
        Employee E[] = new Employee[10]; 
        do{ 
            System.out.println("Main Menu\n1.Read\n2.Display\n3.Exit"); 
            System.out.print("Enter your choice : "); 
            choice = sc.nextInt(); 
            switch(choice){ 
                case 1 : System.out.println("Enter the details of "+N+" Employee"); 
                         for(i=0;i<N;i++){ 
                            E[i]= new Employee(); 
                            System.out.println("Employee-"+(i+1)); 
                            E[i].read(); 
                         } 
                         break; 
                case 2 : System.out.println("The Entered details are :"); 
                         System.out.println("ID\tName\t\tDepartment\tBasic-Pay\tGross-Pay\tNet-Pay"); 
                         for(i=0;i<N;i++){ 
                            E[i].grosspay(); 
                            E[i].netpay(); 
                            E[i].display(); 
                         } 
                         break; 
                case 3 : System.out.println("!!THANK YOU!!"); 
                         break; 
                default : System.out.println("Invalid Choice\nEnter Again"); 
            } 
        }while(choice!=3); 
    }}