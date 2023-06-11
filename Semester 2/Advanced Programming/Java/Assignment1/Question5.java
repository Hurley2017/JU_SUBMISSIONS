// Write a program that accepts a string and assigns it to another. 
// Check the outcome of comparison with  == and equals() method. 
// Take two Strings and put the same input for them. 
// Repeat The equality checking. 
// Observe the outcome.

import java.util.*;

class Main
{
    public static void main(String[] Tusher)
    {
        String one, two;
        Scanner buffer = new Scanner(System.in);

        System.out.println("Enter the string 'one' to be assigned it to 'two' : "); // Getting the string 'one'
        one = buffer.nextLine();

        two = one; // Assigning the string 'one' to 'two'

        // Checking the equality of the two strings
        System.out.println("Using '==' operator, the result is : " + (one == two)); // prints true
        System.out.println("Using 'equals()' method, the result is : " + one.equals(two)); // prints true

        String three, four;

        // Getting the string 'three' and 'four' and giving the same input.
        System.out.println("Enter the string 'three' : "); 
        three = buffer.nextLine(); // Getting the string 'three'

        System.out.println("Enter the string 'four' : "); 
        four = buffer.nextLine(); // Getting the string 'four'

        // Checking the equality of the two strings
        System.out.println("Using '==' operator, the result is : " + (three == four)); // prints false
        System.out.println("Using 'equals()' method, the result is : " + three.equals(four)); // prints true

        buffer.close();
    }
}
