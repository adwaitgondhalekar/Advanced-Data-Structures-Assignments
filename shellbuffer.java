import java.io.*;

public class shellbuffer
{
   public static void main(String[] args)throws IOException
   {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        System.out.println("ENTER THE SIZE OF THE ARRAY");
        String str=br.readLine();
        int size=Integer.parseInt(str);
        
        int num[]=new int[size];
        System.out.println("ENTER THE NUMBERS");
        for(int i=0;i<size;i++)
           {
               num[i]=Integer.parseInt(br.readLine());
           }

        System.out.println("THE SORTED ARRAY IS");
    
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
    for(int i=0;i<size;i++)
       {
           System.out.println(num[i]+"\t");
       }
}
}
                        
  
       
