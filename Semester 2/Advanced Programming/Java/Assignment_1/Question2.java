class Main
{
    public static void main(String[] Tusher)
    {
        System.out.println("Question 2 : ");
        int len;
        String Arguments[] = Tusher;
        len = Arguments.length;
        System.out.println("Total number of commandline arguments given is " + len + ".");
        for(int i=0; i<len; i++)
        {
            System.out.println((i+1) + ") " + Arguments[i]);
        }
    }
}