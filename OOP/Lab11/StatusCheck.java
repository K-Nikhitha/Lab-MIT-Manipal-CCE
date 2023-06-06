class Mythreadx extends Thread{
  public void run(){
    System.out.println("Run1");
    try{
        Thread.sleep(1000);
    }
    catch(InterruptedException e)
    {
        System.out.println(e);
    }
    System.out.println("Exit");
}
}
public class StatusCheck{
    public static void main(String args[]){
        Mythreadx mt= new Mythreadx();
        Thread t=new Thread(mt);
        t.start();
        Mythreadx mt1= new Mythreadx();
        Thread t1=new Thread(mt1);
        Mythreadx mt2= new Mythreadx();
        Thread t2=new Thread(mt2);
        Mythreadx mt3= new Mythreadx();
        Thread t3=new Thread(mt3);
        t1.start();
        System.out.println(t.isAlive());
        System.out.println(t1.isAlive());
        t2.start();
        try
        {
            t2.join();
        }
        catch(InterruptedException e){
            System.out.println("E:"+e);
        }
        t3.start();
    }

}
