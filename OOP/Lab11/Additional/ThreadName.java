import java.util.Scanner;
class threadx implements Runnable
{

    public void run()
    {
        try
        {
            System.out.println("Name:"+Thread.currentThread().getName());
            Thread.sleep(1000);
        }
        catch(InterruptedException e)
        {
            System.out.println(e);
        }
    }
}

public class ThreadName
{
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter New Thread Name:");
        String x=in.nextLine();
        threadx p=new threadx();
        Thread t=new Thread(p);
        t.setName(x);
        t.start();
    }
}
