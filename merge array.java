5) Given are two one dimensional array A and B which are sorted in ascending order. 
Develop an application to merge them into a single sorted array C that contains every 
item form A and B, in ascending order. 
 
// Java program to merge two sorted arrays 
import java.util.*; 
 
class Main 
{ 
 public static void mergearrays(int[] A, int[] B, int n1, 
        int n2, int[] C) 
 { 
  int i = 0, j = 0, k = 0; 
  while (i<n1 && j <n2) 
  { 
   if (A[i] < B[j]) 
    C[k++] = A[i++]; 
   else 
    C[k++] = B[j++]; 
  } 
  while (i < n1) 
   C[k++] = A[i++]; 
  while (j < n2) 
   C[k++] = B[j++]; 
 } 
  
 public static void main (String args[]) 
 { 
     int i; 
     Scanner in = new Scanner(System.in); 
  int[] A = new int[10]; 
  System.out.println("Enter no. of elements of array - A : "); 
  int n1 = in.nextInt(); 
  System.out.println("Enter "+n1+" elements into array - A : "); 
  for(i=0;i<n1;i++){ 
      A[i] = in.nextInt(); 
  } 
  int[] B = new int[10]; 
  System.out.println("Enter no. of elements of array - B : "); 
  int n2 = in.nextInt(); 
  System.out.println("Enter "+n2+" elements into array - B : "); 
  for(i=0;i<n2;i++){ 
      B[i] = in.nextInt(); 
  } 
  
  int[] C = new int[n1+n2]; 
  mergearrays(A, B, n1, n2, C); 
  
} 
System.out.println("Array after merging"); 
for (i=0; i < n1+n2; i++) 
System.out.print(C[i] + " ");
}
}
