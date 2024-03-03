6.) Create a class of objects CUBE. Develop an application to read the sides of three cubes 
and print their Volume and Outer Area. 
  
import java.util.*; 
import java.util.Scanner; 
class CUBE{ 
    Scanner in = new Scanner(System.in); 
    int vol, out_ar; 
    int[] a = new int[3]; 
    void read(){ 
        for(int i=0; i<3; i++){ 
            System.out.print("Enter the length of side of cube-"+(i+1)+" : "); 
            a[i] = in.nextInt(); 
        } 
    } 
    void calculate(){ 
        for(int i=0; i<3;i++){ 
            vol = a[i]*a[i]*a[i]; 
            out_ar = 6*a[i]*a[i]; 
            System.out.println("Volume of cube-"+(i+1)+" = "+vol); 
            System.out.println("Outer area of cube-"+(i+1)+" = "+out_ar); 
        } 
    } 
} 
public class Main{ 
    public static void main(String args[]){ 
        CUBE cube = new CUBE(); 
        cube.read(); 
        cube.calculate(); 
    } 
} 
 
 