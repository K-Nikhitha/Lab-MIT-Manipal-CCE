/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab8;

import java.util.Scanner;

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
 class Square extends Area
 {
   double side;
   Square(double s)
   {
     side = s;
   }
   void area()
   {
     ar = side * side;
   }
 }
 class Triangle extends Area
 {
   double base, height;
   Triangle(double b, double h)
   {
     base = b;
     height = h;
   }
   void area()
   {
     ar =  0.5*base*height;
   }
 }

 public class AbstractAreaCalc_ST
 {
   public static void main(String args[])
   {

     Square sq = new Square(25);
     sq.area();
     double sqar= sq.retArea();
     System.out.println("Area of Square: "+sqar);
     Triangle tr = new Triangle(12,15);
     tr.area();
     double trar = tr.retArea();
     System.out.println("Area of Triangle: "+trar);
   }
 }
