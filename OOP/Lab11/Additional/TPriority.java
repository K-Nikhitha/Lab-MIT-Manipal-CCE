import java.util.Scanner;
public class TPriority extends Thread
{
	public void run()
  {
		System.out.println("Inside the run() method");
	}
  public static void main(String args[])
  {
       TPriority a = new TPriority();
       TPriority b = new TPriority();
       TPriority c = new TPriority();
       System.out.println("Priority of the thread a is : " + a.getPriority());
       System.out.println("Priority of the thread b is : " + b.getPriority());
       System.out.println("Priority of the thread c is : " + c.getPriority());
       a.setPriority(7);
       b.setPriority(4);
       c.setPriority(2);
       System.out.println("Priority of the thread a is : " + a.getPriority());
       System.out.println("Priority of the thread b is : " + b.getPriority());
       System.out.println("Priority of the thread c is : " + c.getPriority());
       System.out.println("Currently Executing The Thread : " + Thread.currentThread().getName());
       System.out.println("Priority of the main thread is : " + Thread.currentThread().getPriority());
       Thread.currentThread().setPriority(10);
       System.out.println("Priority of the main thread is : " + Thread.currentThread().getPriority());
  }
}
