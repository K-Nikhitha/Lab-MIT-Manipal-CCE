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
public class CountObjs 
{
    static int count;
    public CountObjs()
    {
        count +=1;
    }
    public static void main(String args[])
    {
        CountObjs ob1 = new CountObjs();
        CountObjs ob2 = new CountObjs();
        CountObjs ob3 = new CountObjs();
        CountObjs ob4 = new CountObjs();
        CountObjs ob5 = new CountObjs();
        CountObjs ob6 = new CountObjs();
        CountObjs ob7 = new CountObjs();
        CountObjs ob8 = new CountObjs();
        System.out.println("Number of Objects: " + CountObjs.count);
    }
    
}
