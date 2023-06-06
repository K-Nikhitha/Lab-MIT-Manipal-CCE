/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package lab9;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class Telephone
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        String tele;
        char[] areaCode = new char[3];
        char[] firstThree = new char[3];
        char[] lastFour = new char[4];
        System.out.println("Enter Telephone number: ");
        tele=in.next();
        for(int i=0; i<tele.length(); i++)
        {
            if(i>0 && i<4)
                areaCode[i-1] = tele.charAt(i);
            if(i>4 && i<8)
                firstThree[i-5] = tele.charAt(i);
            if(i>8 && i<=12)
                lastFour[i-9] = tele.charAt(i);
        }

        System.out.println("Area Code:");
        for(int i=0; i<3; i++)
            System.out.println(areaCode[i]);
        System.out.println("Last Seven Digits: ");
        for(int i=0; i<3; i++)
            System.out.println(firstThree[i]);
        for(int i=0; i<3; i++)
            System.out.println(lastFour[i]);
    }

}
