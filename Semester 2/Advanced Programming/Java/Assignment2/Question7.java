// Take a String input that contains multiple words. 
// Do the following, 
// i) number of times ‘a’ appears 
// ii) number of time ‘and’ appears 
// iii) whether it starts with ‘The’ or not 
// iv) put the String into an array of characters 
// v) display the tokens in the String ( tokens are the substrings separated by space or @ or . )

import java.util.*;

class Main
{
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in); // creating a Scanner object

        // declaring variables
        String userInp;
        String[] result;
        char[] arr;
        int count_a = 0, count_and = 0;

        System.out.println("Enter the String : ");
        userInp = buffer.nextLine(); // taking the string as input

        arr = new char[userInp.length()];
        result = userInp.split(" "); // splitting the string into tokens

        for(int i=0; i<result.length; i++)
        {
            if(result[i].equals("a") || result[i].equals("A"))
            {
                count_a++; // counting the number of 'a' in the string
            }
            else if(result[i].equals("and") || result[i].equals("And") || result[i].equals("AND"))
            {
                count_and++; // counting the number of 'and' in the string
            }
        }

        for(int i=0; i<userInp.length(); i++)
        {
            arr[i] = userInp.charAt(i); // putting the string into an array of characters
        }

        System.out.println("1) total number of 'a' in the string is : "+count_a+".");
        System.out.println("2) total number of 'and' in the string is : "+count_and+".");

        // checking whether the string starts with 'The' or not
        if(!result[0].equals("The"))
        {
            System.out.println("3) The string doesn't start with 'The'.");
        }
        else
        {
            System.out.println("3) The string starts with 'The'.");
        }

        System.out.println("4) printing the array of characters : ");
        for(int i=0; i<arr.length; i++)
        {
            System.out.print(arr[i]+", ");
        }

        System.out.println();
        System.out.println("5) printing the tokens : ");
        for(int i=0; i<result.length-1; i++)
        {
            System.out.print(result[i]+", "); // printing the tokens
        }
        System.out.println(result[result.length-1]);

        buffer.close(); // closing the buffer
    }
}