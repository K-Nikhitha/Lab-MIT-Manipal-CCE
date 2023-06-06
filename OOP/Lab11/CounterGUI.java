import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class CounterGUI extends JFrame implements ActionListener
{
  private JLabel label;
  private JTextField text;
  private JButton addBtn;
  private int count;
  public CounterGUI() 
  {
    setTitle("Counter");
    setLayout(new FlowLayout());
    count = 0;
    label = new JLabel("Counter");
    text = new JTextField("0", 4);
    addBtn = new JButton("Add");
    addBtn.addActionListener(this);
    add(label);
    add(text);
    add(addBtn);
    setSize(275, 250);
    setLocationRelativeTo(null);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setVisible(true);
  }
  public void actionPerformed(ActionEvent ae)
  {
    if (ae.getSource() == addBtn)
    {
      count=count+6;
      text.setText(String.valueOf(count));
      repaint();
    }
  }
  public static void main(String[] args)
  {
        new CounterGUI();
  }
}
