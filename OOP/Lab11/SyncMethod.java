class threadp extends Thread{
  public void displayx(String msg){
    System.out.print ("["+msg);
    try
    {
      Thread.sleep(1000);
    }
    catch(InterruptedException e)
    {
      e.printStackTrace();
    }
    System.out.println ("]");
  }
  String msg;
  threadp fobj;
  threadp()
  {

  }
  threadp(threadp p,String str){
      fobj=p;
    msg = str;
    start();
  }
  public void run()
  {
      synchronized(fobj)
      {
          fobj.displayx(msg);
      }
  }
}
public class SyncMethod{
    public static void main(String args[]){
      threadp fnew=new threadp();
      threadp ss = new threadp(fnew, "welcome");
      threadp ss1= new threadp(fnew,"oop");
      threadp ss2 = new threadp(fnew, "programmer");
    }
}
