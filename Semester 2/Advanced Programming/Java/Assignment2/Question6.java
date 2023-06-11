// Consider a wrapper class for a numeric basic type. 
// Check the support for the following: 
// conversion from - 
// i) basic type to object, 
// ii) object to basic type 
// iii) basic type to String 
// iv) String ( holding numeric data ) to numeric object 
// v) object to String.


class Main 
{
    public static void main(String[] Tusher)
    {
        int primitive_int1 = 500;

        System.out.println("i) Basic type to Object");
        Integer Int_Object1 = Integer.valueOf(primitive_int1); // Autoboxing
        System.out.println(Int_Object1); // printing the Integer object

        System.out.println("ii) Object  to Basic type");
        int primitive_int2; 
        primitive_int2 = Int_Object1.intValue(); // Unboxing
        System.out.println(primitive_int2); // printing the primitive int

        System.out.println("iii) Basic type to String");
        String Str_Object1 = String.valueOf(primitive_int1); // Autoboxing and type conversion using Wrapper class
        System.out.println(Str_Object1); // printing the String object containing the numeric data

        System.out.println("iv) String (holding numeric data) to numeric object");
        Integer Int_Object2 = Integer.valueOf(Str_Object1); // Autoboxing and type conversion using Wrapper class
        System.out.println(Int_Object2); // printing the Integer object containing the String data
        
        System.out.println("v) Object to String");
        String Str_Object2 = String.valueOf(Str_Object1); // Autoboxing using Wrapper class
        System.out.println(Str_Object2); // printing the String object containing the String data
    }
}