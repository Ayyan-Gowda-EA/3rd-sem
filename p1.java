a) Generate prime numbers for the given range. 
   // Generate prime numbers for the given range. 
   import java.util.*; 
   import java.util.Scanner; 
   public class Main{ 
      public static void main(String args[]){ 
        Scanner in = new Scanner(System.in); 
        int n1, n2, i, j, flag; 
        System.out.print("Enter the lower no. of interval : "); 
        n1 = in.nextInt(); 
        System.out.print("Enter the higher no. of interval : "); 
        n2 = in.nextInt(); 
        System.out.println("Prime no. between "+n1+" and "+n2+" are : "); 
        for(i=n1;i<=n2;i++){ 
            if(i==1 || i==0) 
                continue; 
            flag = 1; 
            for(j=2;j<=i/2;j++){ 
                if(i%j == 0){ 
                    flag = 0; 
                    break; 
                } 
            } 
            if(flag == 1) 
                System.out.print(i+" "); 
        } 
      } 
   } 
    
b) Find all the roots of a quadratic equation. 
   // Find all the roots of a quadratic equation 
   import java.util.*; 
   import java.util.Scanner; 
   public class Main{ 
      public static void main(String args[]){ 
          Scanner in = new Scanner(System.in); 
          double a, b, c, det, r1, r2; 
          System.out.print("Enter non-zero co-effecient value : "); 
          a = in.nextDouble(); 
          b = in.nextDouble(); 
          c = in.nextDouble(); 
          det = b*b - 4*a*c; 
          if(det > 0){ 
              System.out.println("Roots are real and distinct "); 
              r1 = (-b + Math.sqrt(det))/(2*a); 
              r2 = (-b - Math.sqrt(det))/(2*a); 
              System.out.println("Root-1 : "+r1+" and Root-2 : "+r2); 
          } 
          else if(det == 0){ 
              System.out.println("Roots are real and equal "); 
              r1 = r2 = (-b)/(2*a); 
              System.out.println("Root-1 = Root-2 = "+r1); 
          } 
          else{ 
              System.out.println("Roots are complex and imaginary"); 
              double real = (-b)/(2*a); 
              double imaginary = Math.sqrt(-det)/(2*a); 
              System.out.println("Root-1 = "+real+" + "+imaginary+"i"); 
              System.out.println("Root-2 = "+real+" - "+imaginary+"i"); 
          } 
      } 
   } 
c) Print ‘N’ Fibonacci numbers. 
   // Print ‘N’ Fibonacci numbers. 
   import java.util.*; 
   import java.util.Scanner; 
   public class Main{ 
       public static void main(String args[]){ 
           Scanner in = new Scanner(System.in); 
           int N, n1=0, n2=1, n3, i; 
           System.out.println("Enter the value of N : "); 
           N = in.nextInt(); 
           System.out.print("Fibonacci sequence upto "+N+" terms : "+n1+" "+n2); 
           for(i=2;i<N;i++){ 
               n3 = n1+n2; 
               System.out.print(" "+n3); 
               n1 = n2; 
               n2 = n3; 
           } 
       } 
   } 
d) Print pyramid shape using * symbols. 
   // Print pyramid shape using * symbols. 
   import java.util.*; 
   import java.util.Scanner; 
   public class Main{ 
       public static void print(int n){ 
           for(int i=0;i<n;i++){ 
               for(int j=n-i;j>1;j--) 
                   System.out.print(" "); 
               for(int j=0;j<=i;j++) 
                   System.out.print("* "); 
               System.out.println(); 
           } 
       } 
      
       public static void main(String args[]){ 
           Scanner in = new Scanner(System.in); 
           int a; 
           System.out.print("Enter no. of * required at base : "); 
           a = in.nextInt(); 
           print(a); 
       } 
   } 
 
 
 
 
 
 
 
 
 
 
 
 
 
