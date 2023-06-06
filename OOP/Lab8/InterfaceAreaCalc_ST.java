/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab8;


/**
 *
 * @author STUDENT
 */
interface Area
{
  void area();
}
class Square implements Area
{
  double side;
  Square (double s)
  {
    side = s;
  }
  public void area()
  {
    double ar = side * side;
    System.out.println("Area of Square: "+ar);
  }
}
class Triangle implements Area
{
  double base, height;
  Triangle (double b, double h)
  {
    base = b;
    height = h;
  }
  public void area()
  {
    double ar = 0.5*base*height;
    System.out.println("Area of Triangle: "+ar);
  }
}

public class InterfaceAreaCalc_ST
{
  public static void main(String args[])
  {
    Area r = new Square(25);
    r.area();
    r = new Triangle(12,15);
    r.area();
  }
}
