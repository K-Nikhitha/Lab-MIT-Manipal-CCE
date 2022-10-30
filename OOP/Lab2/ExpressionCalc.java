/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab1;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */
public class ExpressionCalc {
   //result of expressions
    public static void main(String[] args) {
      int a;
      int b;
      Scanner in = new Scanner(System.in);
      System.out.println("Enter the value for 'a': ");
      a=in.nextInt();
      System.out.println("Enter the value for 'b': ");
      b=in.nextInt();
      System.out.println("(a<<2)+(b>>2): " + ((a<<2)+(b>>2)));
      System.out.println("(b>0): " + (b>0));
      System.out.println("(a+b*100)/10: " + (a+b*100)/10 );
      System.out.println("a&b : "+ (a&b));
    }

}
