// Write a program that accepts a number of command line parameters and displays the parameters and count of such parameters.

class Main
{
    public static void main(String[] Tusher) // The commandline arguments are stored in the String array Tusher passed to the main method
    {
        int len;
        String Arguments[] = Tusher; // Getting the commandline arguments
        len = Arguments.length; // Getting the length of the commandline arguments

        System.out.println("Total number of commandline arguments given is " + len + "."); // Printing the number of arguments provided

        if(len == 0)
        {
            System.out.println("Nothing to print"); // If no arguments are provided, then print this
        }

        for(int i=0; i<len; i++)
        {
            System.out.println((i+1) + ") " + Arguments[i]); // Printing the arguments provided 
        }

    }
}