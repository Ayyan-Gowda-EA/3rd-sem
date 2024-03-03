3) The daily maximum temperatures recorded for 5 cities during the first 6 days of 
January month have to be tabulated. Develop an application to read the data and find the 
city and day corresponding to highest temperature and lowest temperature. 
 
// Java program to calculate max temp and min temp in 6days of Jan 
import java.util.*; 
import java.util.Scanner; 
public class Main{ 
    public static void main(String args[]){ 
        Scanner in = new Scanner(System.in); 
        City[] city = new City[6]; 
        for(int i=0;i<6;i++) 
            city[i] = new City(); 
        for(int i=0;i<6;i++){ 
            System.out.print("Enter details of city-"+(i+1)+" : "); 
            city[i].read(); 
            city[i].cal(); 
        } 
        int ch=0; 
        while(ch != 2){ 
            System.out.print("Press 1 to display\nPress 2 to exit"); 
            ch = in.nextInt(); 
            if(ch ==1){ 
                System.out.print("Enter the city no. : "); 
                int ctn = in.nextInt(); 
                if(ctn > 5 || ctn < 1) 
                    System.out.print("Enter valid no. "); 
                else 
                    city[ctn-1].display(); 
            } 
            else if(ch ==2) 
                break; 
            else 
                System.out.print("Enter correct option"); 
        } 
        in.close(); 
    } 
} 
class City{ 
    Scanner in = new Scanner(System.in); 
    int[] t = new int[6]; 
    int high, low, hd, ld; 
    String name; 
    public void read() 
    { 
        System.out.print("Enter the name of city : "); 
        name = in.next(); 
        for(int i=0;i<6;i++){ 
            System.out.print("Enter the temperature on Jan "+(i+1)+" : "); 
            t[i] = in.nextInt(); 
        } 
    } 
    public void cal() 
    { 
        high = t[1]; 
        low = t[1]; 
        for(int i=0; i<6; i++){ 
            if(t[i] > high){ 
                high = t[i]; 
                hd = i+1; 
            } 
            if(t[i] < low){ 
                low = t[i]; 
                ld = i+1; 
            } 
        } 
    } 
    public void display(){ 
        System.out.println("City Name : "+name); 
        System.out.println("Highest temperataure is "+high+" on Jan "+hd); 
        System.out.println("Lowest temperataure is "+low+" on Jan "+ld); 
    } 
} 
 
 
 
