// Write a program where the class contains void show(int) to display the argument passed. 
// Call the function once with short as actual parameter and again double as actual parameter. 
// Add another function as void show(double). Repeat the calls. Observe the outcome in each case.

import java.util.*;

class Main
{
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in);

        ShowClass SC = new ShowClass(); // Creating an object of ShowClass to use the show function

        short check1;
        double check2;

        System.out.println("Enter short value : ");
        check1 = buffer.nextShort(); // Getting the short value

        System.out.println("Enter double value : ");
        check2 = buffer.nextDouble(); // Getting the double value

        System.out.println("Printing short value : ");
        SC.show(check1); // Invoking the show function with short type parameter

        System.out.println("Printing the double value : ");
        SC.show(check2); // Invoking the show function with double type parameter

        buffer.close();
    }
}
//this is a good example of method overloading
class ShowClass
{
    void show(int arg)
    {
        System.out.println(arg);
    }
    //While not adding a show function for double type parameter,
    //it automatically tries to invoke the show function with short type parameter and fails to convert type
    //and throws an error.
    void show(double arg)
    {
        System.out.println(arg);
    }
}
