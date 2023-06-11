// Write a program to accept two short integers from the user and display the sum.

import java.util.*;

class Main
{
    public static void main(String[] Tusher)
    {
        short a, b;
        int answer;
        Scanner buffer = new Scanner(System.in); // Scanner Object to get data from standard input stream

        System.out.println("Enter first short integer : ");
        a = buffer.nextShort(); // Getting the first short integer from standard input stream

        System.out.println("Enter second short integer : ");
        b = buffer.nextShort(); // Getting the second short integer from standard input stream

        answer = a + b; // Since the sum of two short integers can be a integer, we are storing the sum in a integer variable

        System.out.println("The sum of the two integers is " + answer + "."); // Printing the sum of the two short integers

        buffer.close(); // Closing the Scanner Object
    }
}