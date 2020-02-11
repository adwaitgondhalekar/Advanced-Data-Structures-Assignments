import java.io.*;

public class shell
{

   public static void quicksort(int num[],int low,int high)
   {
     if(low<high)
    {
     int pivotpos=partition(num,low,high);
     quicksort(num,low,pivotpos-1);
     quicksort(num,pivotpos+1,high);
    }
   }

   public static int partition(int num[],int low,int high)
   {
  
     int pivot=num[high];
     int i=low-1;
     for(int j=0;j<high;j++)
       {
          if(num[j]<=pivot)
           {
             i=i+1;
             int temp=num[j];
             num[j]=num[i];
             num[i]=temp;
          }
       }
     int temp=num[i+1];
     num[i+1]=num[high];
     num[high]=temp;
     return i+1;
   }
     
   public static void main(String[] args)throws IOException
   {
 

         BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

         System.out.println("ENTER THE TOTAL NUMBERS");
         String str=br.readLine();
         int n=Integer.parseInt(str);
  
         int num[]=new int[n];
         System.out.println("ENTER THE NUMBERS");
         for(int i=0;i<n;i++)
            {
              String str1=br.readLine();
              num[i]=Integer.parseInt(str1);
            }
        

        System.out.println("SORTED ARRAY IS");
   
         /*for(int gap=n/2;gap>=1;gap=gap/2)
           {
       for(int j=gap;j<n;j++)
             {
             for(int i=j-gap;i>=0;i=i-gap)
               {
                  if(num[i+gap]>num[i])
                   break;
                  else
                   {
                      int temp=num[i];
                      num[i]=num[i+gap];
                     num[i+gap]=temp;
                   }
              }
           }
        }*/
        quicksort(num,0,n);
        for(int i=0;i<n;i++)
         {
            System.out.print(num[i]+"\t");
         }
     }
}

