import java.util.*;
class Main
{
    public static void main(String[] Tusher)
    {
        System.out.println("Question 6 :");
        Scanner buffer = new Scanner(System.in);
        ShowClass SC = new ShowClass();
        short check1;
        double check2;
        System.out.println("Enter short value : ");
        check1 = buffer.nextShort();
        System.out.println("Enter double value : ");
        check2 = buffer.nextDouble();
        System.out.println("Printing short value : ");
        SC.show(check1);
        System.out.println("Printing the double value : ");
        SC.show(check2);
        buffer.close();
    }
}
class ShowClass
{
    void show(int arg)
    {
        System.out.println(arg);
    }
    //While not adding a show function for double type parameter it automatically tries to invoke the show function with short type parameter and fails to convert type
    void show(double arg)
    {
        System.out.println(arg);
    }
}
