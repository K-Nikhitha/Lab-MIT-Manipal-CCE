/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab7;

/**
 *
 * @author STUDENT
 */
public class A_U_Boxing
{
    public static void main(String args[]){
      int n=10;
      Integer n1=n;//AutoBoxing
      Integer n2=25;//Boxing
      System.out.println("N1: " + n1 );
      System.out.println("N2: " + n2 );
      Integer i =new Integer(50);
      int n3=i;  //Unboxing
      System.out.println("N3: " + n3);
 }
}
