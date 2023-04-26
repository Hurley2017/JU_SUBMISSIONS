//Question 10
import java.util.*; 
class Main 
{
    public static void main(String[] Tusher)
    {
        Scanner Converter = new Scanner(System.in);
        double KiloMeter, Miles;
        Metric One = new Metric();
        System.out.print("Enter KiloMeter Value : ");
        KiloMeter = Converter.nextDouble();
        System.out.println("Converted Miles value is : " + One.KiloMeterToMiles(KiloMeter));
        System.out.print("Enter Miles Value : ");
        Miles = Converter.nextDouble();
        System.out.println("Converted KiloMeter value is : " + One.MilesToKiloMeter(Miles));
        Converter.close();
    }
}
class Metric
{
    double KiloMeterToMiles(double KiloMeter)
    {
        return KiloMeter/1.5;
    }
    double MilesToKiloMeter(double Miles)
    {
        return Miles*1.5;
    }
}
