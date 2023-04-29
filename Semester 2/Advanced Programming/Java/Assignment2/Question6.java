class Main 
{
    public static void main(String[] Tusher)
    {
        int primitive_int1 = 500;
        //i) Basic type to Object
        //Integer Int_Object = new Integer(primitive_int) -- this is deprecated and on it's way to removal after the jDK version 9
        Integer Int_Object1 = Integer.valueOf(primitive_int1);
        System.out.println(Int_Object1);
        //ii) object  to basic type
        int primitive_int2;
        primitive_int2 = Int_Object1.intValue();
        System.out.println(primitive_int2);
        //iii) basic type to string
        String Str_Object1 = String.valueOf(primitive_int1);
        System.out.println(Str_Object1);
        //iv) string (holding numeric data) to numeric object
        Integer Int_Object2 = Integer.valueOf(Str_Object1);
        System.out.println(Int_Object2);
        //v) object to string
        String Str_Object2 = String.valueOf(Int_Object2);
        System.out.println(Str_Object2);
    }
}