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
class Rectangle implements Area
{
  double length, breadth;
  Rectangle (double l, double b)
  {
    length = l;
    breadth = b;
  }
  public void area()
  {
    double ar = length * breadth;
    System.out.println("Area of Rectangle: "+ar);
  }
}
class Circle implements Area
{
  double radius;
  Circle (double r)
  {
    radius = r;
  }
  public void area()
  {
    double ar = 3.14*radius*radius;
    System.out.println("Area of Circle: "+ar);
  }
}

public class InterfaceAreaCalc_RC
{
  public static void main(String args[])
  {
    Area r = new Rectangle(25,30);
    r.area();
    r = new Circle(12);
    r.area();
  }
}
