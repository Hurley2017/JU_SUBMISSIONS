import java.util.*;
class Main
{
    public static void main(String[] Tusher)
    {
        System.out.println("Question 4 :");
        Scanner buffer = new Scanner(System.in);
        double radius, area, pi = 3.14;
        System.out.println("Enter the radius of the circle : ");
        radius = buffer.nextDouble();
        area = pi*radius*radius;
        System.out.println("The area of the circle is " + area + " unit square.");
        buffer.close();
    }
}
