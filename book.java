8.) Write a program to read a list containing Book Title, Book Code, Cost and Quantity 
interactively for min. of 10 books and produce a five-column output as shown below. 
NAME CODE UNIT PRICE QUANTITY TOTAL PRICE 
Define the suitable functions and perform the transactions. 
  
import java.util.*; 
class Book{ 
    String title; 
    int id; 
    float unitprice,totalprice; 
    int quantity; 
    int i; 
    Scanner sc = new Scanner(System.in); 
    Book B[] = new Book[10]; 
    void read(){ 
        for(i=0;i<10;i++){ 
        B[i] = new Book(); 
        System.out.println("Enter book title : "); 
        B[i].title = sc.next(); 
        System.out.println("Enter book ID : "); 
        B[i].id = sc.nextInt(); 
        System.out.println("Enter book Unit price : "); 
        B[i].unitprice = sc.nextFloat(); 
        System.out.println("Enter book Quantity : "); 
        B[i].quantity = sc.nextInt(); 
    } 
} 
    void totalprice(){ 
        totalprice=unitprice*quantity; 
    } 
    void display(){ 
        for(i=0;i<10;i++){ 
            B[i].totalprice(); 
            System.out.println(B[i].title+"\t\t"+B[i].id+"\t"+B[i].unitprice+"\t\t"+B[i].quantity+"\t\t"
 +B[i].totalprice); 
        } 
        }         
} 
public class P8 { 
    public static void main(String args[]){ 
        Scanner sc = new Scanner(System.in); 
        Book book = new Book(); 
        int choice; 
        System.out.println("Enter the book details : "); 
        do{ 
            System.out.println("1.Read\n2.Display\n3.Exit"); 
            System.out.print("Enter your Choice : "); 
            choice = sc.nextInt(); 
            switch(choice){ 
                case 1 : book.read(); 
                         break; 
                case 2 : System.out.println("Title\t\tID\tUnit Price\tQuantity\tTotal Price"); 
                         book.display(); 
                         break; 
                case 3 : System.out.println("!!THANK YOU!!"); 
                         break; 
                default : System.out.println("Invalid Choice"); 
            } 
             
        }while(choice!=3); 
    } 
     
} 
 
 