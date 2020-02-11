import java.util.Scanner;

public class shellscanner
{

   public static void shellsort(int num[],int size)
   {
      
       for(int gap=size/2;gap>=1;gap=gap/2)
           {
            for(int j=gap;j<size;j++)
             {
               for(int i=j-gap;i>=0;i=i-gap)
                 {
                      if(num[i+gap]>num[i])
                        break;
                      else
                        {
                           int temp=num[i+gap];
                           num[i+gap]=num[i];
                           num[i]=temp;
                        }
                 }
              }
           }
    }
   public static void main(String[] args)
    {
     

      int l=0;
       while(l==0)
       {
        Scanner s=new Scanner(System.in);
  
        System.out.println("ENTER THE TOTAL NUMBERS");
        int size=s.nextInt();

        int num[]=new int[size];
        System.out.println("ENTER THE NUMBERS");
           for(int i=0;i<size;i++)
              {
                 System.out.println("ENTER THE"+i+"ELEMENT");
                 num[i]=s.nextInt();
              }

            System.out.println("MENU");
            System.out.println("1.SHELL SORT");
            System.out.println("2.HEAP SORT");
            System.out.println("3.EXIT");
            System.out.println("ENTER YOUR CHOICE");
            int ch=s.nextInt();
 
         switch(ch)
              {
                   case 1:
                            shellsort(num,size);
                            System.out.println("SORTED ARRAY IS");
                            for(int i=0;i<size;i++)
                               {
                                    System.out.print(num[i]+"\t");
                                }
                               System.out.println();
                             break;
              }
         }
   }
}
        
      
