import java.util.*;
class Main
{
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in);
        Console print = new Console();
        String userInp;
        String[] result;
        char[] arr;
        int count_a = 0, count_and = 0;
        print.outln("Enter the String : ");
        userInp = buffer.nextLine();
        arr = new char[userInp.length()];
        result = userInp.split(" ");
        for(int i=0; i<result.length; i++)
        {
            if(result[i].equals("a"))
            {
                count_a++;
            }
            else if(result[i].equals("and"))
            {
                count_and++;
            }
        }
        for(int i=0; i<userInp.length(); i++)
        {
            arr[i] = userInp.charAt(i);
        }
        print.outln("1) total number of 'a' in the string is : "+count_a+".");
        print.outln("2) total number of 'and' in the string is : "+count_and+".");
        if(!result[0].equals("The"))
        {
            print.outln("3) The string doesn't start with 'The'.");
        }
        else
        {
            print.outln("3) The string starts with 'The'.");
        }
        print.outln("4) printing the array of characters : ");
        for(int i=0; i<arr.length; i++)
        {
            print.out(arr[i]+", ");
        }
        print.outln();
        print.outln("5) printing the tokens : ");
        for(int i=0; i<result.length-1; i++)
        {
            print.out(result[i]+", ");
        }
        print.outln(result[result.length-1]);
        buffer.close();
    }
}
class Console
{
    void outln()
    {
        System.out.println("");
    }
    void outln(String Object)
    {
        System.out.println(Object);
    }
    void outln(int Object)
    {
        System.out.println(Object);
    }
    void outln(double Object)
    {
        System.out.println(Object);
    }
    void outln(long Object)
    {
        System.out.println(Object);
    }
    void outln(boolean Object)
    {
        System.out.println(Object);
    }
    void out(String Object)
    {
        System.out.print(Object);
    }
    void out(int Object)
    {
        System.out.print(Object);
    }
    void out(double Object)
    {
        System.out.print(Object);
    }
    void out(long Object)
    {
        System.out.print(Object);
    }
    void out(boolean Object)
    {
        System.out.print(Object);
    }
}