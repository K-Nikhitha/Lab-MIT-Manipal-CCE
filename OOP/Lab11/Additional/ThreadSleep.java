class MyThreadl implements Runnable
{
    public void run()
    {
        System.out.println("Thread "+Thread.currentThread().getName());
        try
        {
            Thread.sleep(5000);
        }
        catch(InterruptedException e)
        {
            System.out.println(e);
        }
        System.out.println("Exit "+Thread.currentThread().getName());
    }
}
public class ThreadSleep
{
    public static void main(String args[])
    {
        MyThreadl p=new MyThreadl();
        Thread x=new Thread(p);
        x.setName("First");
        x.start();
        System.out.println(x.getName()+":"+x.getState());
        MyThreadl px=new MyThreadl();
        Thread xx=new Thread(px);
        xx.setName("Second");
        xx.start();
        System.out.println(xx.getName()+":"+xx.getState());
    }
}
