/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab6;

import java.util.Scanner;

/**
 *
 * @author STUDENT
 */

   class Game
   {
     void type()
     {
       System.out.println("Indoor and Outdoor Games.");
     }
   }
   class Cricket extends Game
   {
     void type()
     {
       System.out.println("Cricket is an Outdoor Game.");
     }
   }
   class Chess extends Game
   {
     void type()
     {
       System.out.println("Chess is an Indoor Game.");
     }
   }
   public class DynamicMethodD
   {
     public static void main(String[] args)
     {
       Game ob = new Game();
       Cricket ob1 = new Cricket();
       Chess ob2 = new Chess();
       Game ref;
       ref=ob;
       ref.type();
       ref=ob1;
       ref.type();
       ref=ob2;
       ref.type();

     }
}
