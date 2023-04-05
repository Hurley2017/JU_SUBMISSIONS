import java.util.*;
class Main
{
    public static void main(String[] Tusher)
    {
        System.out.println("Question 5 :");
        Scanner buffer = new Scanner(System.in);
        String one, two;
        String inputone, inputtwo;
        System.out.println("Enter the first string.");
        inputone = buffer.nextLine();
        System.out.println("Enter the first string.");
        inputtwo = buffer.nextLine();
        System.out.println("Assigning them to another strings : ");
        one = inputone;
        two = inputtwo;
        System.out.println("Trying '==' for comparison - ");
        System.out.println("The outcome is '" + (one==two) + "'");
        System.out.println("Trying 'equals()' for comparison - ");
        System.out.println("The outcome is '" + one.equals(two) + "'");
        buffer.close();
    }
}
