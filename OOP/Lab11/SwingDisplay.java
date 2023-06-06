import javax.swing.*;
public class SwingDisplay 
{
  public static void main(String[] args)
  {
    JFrame f =new JFrame();
    JLabel l= new JLabel("Hello world");
    l.setBounds(80,80,100,50);
    f.add(l);
    f.setSize(250,250);
    f.setLayout(null);
    f.setVisible(true);
  }
}
