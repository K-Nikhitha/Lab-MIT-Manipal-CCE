class Mythread implements Runnable{
  String name;
  Thread t;
  Mythread(String threadname){
    name=threadname;
    Thread t=new Thread(this,name);
    System.out.println("New thread: " + t);
    t.start();
  }
  public void run()
  {
    try{
      for(int i=0;i<5;i++)
      {
        System.out.println(name+":"+i);
        Thread.sleep(1000);
      }
    }
    catch (InterruptedException e){
      System.out.println(name + "Interrupted");
    }
    System.out.println(name + " exiting.");
  }
}
public class MultipleThreads{
  public static void main(String args[]){
    new Mythread("One");
    new Mythread("Two");
    new Mythread("Three");
    try
    {
      Thread.sleep(10000);
    }
    catch (InterruptedException e)
    {
      System.out.println("Main thread Interrupted");
    }
    System.out.println("Main thread exiting.");
  }
}
