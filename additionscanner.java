import java.util.Scanner;

public class additionscanner
{
   public static void main(String[] args)
   {
       Scanner s=new Scanner(System.in);
       System.out.println("ENTER TWO NUMBERS");
       int num1=s.nextInt();
       int num2=s.nextInt();
       int sum=num1+num2;
  
       System.out.println("ADDITION OF TWO INTEGERS IS "+sum);

       float f1,f2;
       System.out.println("ENTER TWO FLOT NUMBERS");
       f1=s.nextFloat();
       f2=s.nextFloat();
       float fsum=f1+f2;
       System.out.println("ADDITION OF TWO FLOATING NUMBERS IS"+fsum);
       
   }
}
