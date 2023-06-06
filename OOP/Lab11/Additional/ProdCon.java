
class Producer implements Runnable
{
    Q q;
    Producer(Q q)
    {
        this.q =q;
        new Thread(this," producer").start();
    }
    public void run()
    {
        int i= 0;
        while(true)
        {
            q.put(i++);
            if(i== 5)
            System.exit(0);
        }
    }
}
class Consumer implements Runnable
{
    Q q;
    Consumer(Q q)
    {
        this.q= q;
        new Thread(this, "consumer").start();
    }
    public void run()
    {
        while(true)
        q.get();
    }
}

public class ProdCon
{
    public static void main(String ar[])
    {
        Q q= new Q();
        new Producer(q);
        new Consumer(q);
    }
}

class Q
{
    int n;
    boolean valueset= true;
    synchronized int get()
    {
        while(!valueset)
        {
            try
            {
                wait();
            }
            catch(Exception e)
            {
            }
        }
        System.out.println("GET " +n);
        valueset= false;
        notify();
        return n;
    }
    synchronized void put(int n)
    {
        while(valueset)
        {
            try
            {
              wait();
            }
            catch(Exception e)
            {
            }
        }
        this.n= n;
        valueset =true;
        System.out.println("PUT " +n);
        notify();
    }
}
