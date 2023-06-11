// Write a program that accepts height in cm as int and displays the height in feet and inches. 
// Assume, 1 inch equals 2.54 cm and 1 foot equals 30.5 cm.

import java.util.*;

class Main
{
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in);
        double heightincm, heightinfeet = 0, heightininches = 0, feet;

        System.out.println("Enter the height in CM");
        heightincm = buffer.nextInt();
        
        heightinfeet = heightincm%30;
        if(heightincm < 30.5)
        {
            heightininches = heightincm / 2.54;
            heightininches = Math.floor(heightininches);
        }
        else
        {
            feet = heightincm / 30.5;
            heightinfeet = Math.floor(feet);
            heightininches = (feet - heightinfeet)*30.5 / 2.54;
            heightininches = Math.floor(heightininches);
        }
        System.out.println("The height is " + heightinfeet + " feet and " + heightininches + " inche(s).");
        buffer.close();
    }
}
