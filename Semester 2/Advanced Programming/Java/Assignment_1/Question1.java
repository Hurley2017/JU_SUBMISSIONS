import java.util.*;
class Main
{
    public static void main(String[] Tusher)
    {
        short a, b;
        int answer;
        Scanner buffer = new Scanner(System.in);
        System.out.println("Question 1 : ");
        System.out.println("Enter first short integer : ");
        a = buffer.nextShort();
        System.out.println("Enter second short integer : ");
        b = buffer.nextShort();
        answer = a + b;
        System.out.println("The sum of the two integers is " + answer + ".");
        buffer.close();
    }
}