// Write a program that accepts the radius of a circle and displays the area of the circle. 
// Declare a constant pi equals 3.14.

import java.util.*;

class F
{
    static double pi = 3.14; // Declaring a constant pi
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in); // Creating a Scanner object
        double radius, area;

        System.out.println("Enter the radius of the circle : ");
        radius = buffer.nextDouble(); // Getting the radius of the circle

        area = pi*radius*radius; // Calculating the area of the circle

        System.out.println("The area of the circle is " + area + " unit square."); // Printing the area of the circle

        buffer.close(); // Closing the Scanner object
    }
}
