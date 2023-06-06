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
 abstract class Area
 {
   double ar;
   abstract void area();
   double retArea()
   {
     return ar;
   }
 }
 class Rectangle extends Area
 {
   double length, breadth;
   Rectangle(double l, double b)
   {
     length = l;
     breadth = b;
   }
   void area()
   {
     ar = length * breadth;
   }
 }
 class Circle extends Area
 {
   double radius;
   Circle(double r)
   {
     radius = r;
   }
   void area()
   {
     ar =  3.14*radius*radius;
   }
 }

 public class AbstractAreaCalc_RC
 {
   public static void main(String args[])
   {

     Rectangle rec = new Rectangle(25,30);
     rec.area();
     double recar= rec.retArea();
     System.out.println("Area of Rectangle: "+recar);
     Circle c = new Circle(12);
     c.area();
     double car = c.retArea();
     System.out.println("Area of Circle: "+car);
   }
 }
