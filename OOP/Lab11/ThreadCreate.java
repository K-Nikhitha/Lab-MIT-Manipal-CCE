import java.util.Scanner;
class Mythread1 implements Runnable{
    public void run() {
    System.out.println("Runnable Interface with threads");
   }
}
class Mythread2 extends Thread{
    public void run(){
        System.out.println("Extending thread class");
    }
}
public class ThreadCreate
{
    public static void main(String args[])
    {
        Scanner in= new Scanner(System.in);
        System.out.println("Create Thread using: ");
        System.out.println("1. Runnable Interface:");
        System.out.println("2. Inherited Thread Class:");
        int ch=in.nextInt();
        switch(ch)
        {
          case 1:
          {
            Mythread1 mt= new Mythread1();
            Thread t= new Thread(mt);
            t.start();
            break;
          }
          case 2:
          {
            Mythread2 my= new Mythread2();
            Thread t=new Thread(my);
            t.start();
            break;
          }
          default:
          {
            System.out.println("Invalid Choice.");
            break;
          }
        }
    }
}
