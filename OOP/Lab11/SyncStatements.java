class threadB extends Thread{
  public void displayx(String msg){
    System.out.print ("["+msg); try
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
  threadB fobj;
  threadB()
  {

  }
  threadB(threadB p,String str)
  {
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
public class SyncStatements{
  public static void main(String args[]){
  threadB fnew=new threadB();
  threadB ss = new threadB(fnew, "welcome");
  threadB ss1= new threadB(fnew,"oop");
  threadB ss2 = new threadB(fnew, "programmer");
  }
}
