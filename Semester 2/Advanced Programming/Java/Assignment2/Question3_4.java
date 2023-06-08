import java.util.Scanner;
import libsys.Booklist.Booklist;
import libsys.Memberlist.Memberlist;
import libsys.Transaction.Transaction;
class Main
{
    public static void main(String[] Tusher)
    {
        Scanner buffer = new Scanner(System.in);
        int flag_logged_member = 0, member_flag = 0, book_id, member_id, sw, book_count = 1, member_count = 1, transaction_count = 1;
        Booklist[] books = new Booklist[100];
        Memberlist[] members = new Memberlist[100];
        Transaction[] transactions = new Transaction[100];
        boolean con = true;
        for(int i=0; i<100; i++)
        {
            books[i] = new Booklist();
            transactions[i] = new Transaction();
            members[i] = new Memberlist();
        }
        while(con)
        {
            UI_Statements();
            sw = buffer.nextInt();
            switch(sw)
            {
                case 1:
                    int id, number;
                    String book_name;
                    System.out.print("Enter book id :");
                    id = buffer.nextInt();
                    System.out.print("Total number to be added : ");
                    number = buffer.nextInt();
                    System.out.print("Name : ");
                    buffer.next();
                    book_name = buffer.nextLine();
                    books[book_count-1].setData(id, number, book_name);
                    System.out.println("Book successfully added!");
                    book_count++;
                    break;
                case 2:
                    System.out.print("Enter book id : ");
                    book_id = buffer.nextInt();
                    boolean hit = false;
                    for(int i=0; i<book_count; i++)
                    {
                        if(book_id == books[i].ret_id())
                        {
                            System.out.print("How many books to add? ");
                            int more_books = buffer.nextInt();
                            books[i].increase(more_books);
                            hit = true;
                            break;
                        }
                    }
                    if(hit)
                    {
                        System.out.println("Successfully added copies of books.");
                    }
                    else 
                    {
                        System.out.println("Book not found");
                    }
                    hit = false;
                    break;
                case 3:
                    System.out.print("Enter book id : ");
                    book_id = buffer.nextInt();
                    boolean hit2 = false;
                    for(int i=0; i<book_count; i++)
                    {
                        if(book_id == books[i].ret_id())
                        {
                            books[i].getData();
                            hit2 = true;
                            break;
                        }
                    }
                    if(hit2)
                    {
                        System.out.println("Successfully displayed.");
                    }
                    else 
                    {
                        System.out.println("Book not found");
                    }
                    hit2 = false;
                    break;
                case 4:
                    System.out.println("Showing all the books : ");
                    for(int i=0; i<book_count; i++)
                    {
                        books[i].getData();
                    }
                    break;
                case 5:
                    int m_id;
                    String member_name;
                    System.out.print("Enter member id :");
                    m_id = buffer.nextInt();
                    System.out.print("Name : ");
                    buffer.next();
                    member_name = buffer.nextLine();
                    members[member_count-1].setData(m_id, member_name);
                    System.out.println("Member successfully added!");
                    member_count++;
                    break;
                case 6:
                    System.out.print("Enter member id : ");
                    member_id = buffer.nextInt();
                    boolean hit3 = false;
                    for(int i=0; i<member_count; i++)
                    {
                        if(member_id == members[i].ret_id())
                        {
                            System.out.print("Displaying member ");
                            members[i].getData();
                            hit3 = true;
                            break;
                        }
                    }
                    if(hit3)
                    {
                        System.out.println("Successfully displayed member.");
                    }
                    else 
                    {
                        System.out.println("member not found");
                    }
                    hit3 = false;
                    break;
                case 7:
                    System.out.print("Member id : ");
                    flag_logged_member = buffer.nextInt();
                    boolean hit4 = false;
                    for(int i=0; i<member_count; i++)
                    {
                        if(flag_logged_member == members[i].ret_id())
                        {
                            member_flag = i;
                            hit4 = true;
                            break;
                        }
                    }
                    if(hit4)
                    {
                        System.out.println("Successfully Logged.");
                    }
                    else 
                    {
                        System.out.println("Invalid member id.");
                        flag_logged_member = 0;
                    }
                    hit4 = false;
                    break;
                case 8:
                    if(flag_logged_member == 0)
                    {
                        System.out.println("Member is not logged in.");
                    }
                    else 
                    {
                        System.out.print("Enter book id : ");
                        book_id = buffer.nextInt();
                        boolean hit5 = false;
                        for(int i=0; i<book_count; i++)
                        {
                            if(book_id == books[i].ret_id())
                            {
                                if(members[member_flag].request_book())
                                {
                                    if(books[i].purchase())
                                    {
                                        System.out.println("Success!");
                                        transactions[transaction_count-1].setData(flag_logged_member, book_id);
                                        transaction_count++;
                                    }
                                    else 
                                    {
                                        System.out.println("Book is not available.");
                                    }
                                }
                                else 
                                {
                                    System.out.println("Cannot borrow book. limit reached.");
                                }
                                break;
                            }
                            hit5  = true;
                        }
                        if(hit5)
                        {
                            System.out.println("Transaction completed");
                        }
                        else 
                        {
                            System.out.println("Book not found");
                        }
                        hit5 = false;
                    }
                    break;
                case 9:
                    if(flag_logged_member == 0)
                    {
                        System.out.println("Member is not logged in.");
                    }
                    else 
                    {
                        System.out.print("Enter book id : ");
                        book_id = buffer.nextInt();
                        boolean hit6 = false;
                        for(int i=0; i<book_count; i++)
                        {
                            if(book_id == books[i].ret_id())
                            {
                                if(members[member_flag].return_book())
                                {
                                    books[i].return_book();
                                    System.out.println("Success!");
                                    for(int j=0; j<transaction_count; j++)
                                    {   
                                        if(transactions[j].getMemberId() == flag_logged_member)
                                        {
                                            transactions[j].changeMember();
                                        }
                                    }
                                    System.out.println("Returned successfully.");
                                }
                                else 
                                {
                                    System.out.println("Cannot return book. none borrowed.");
                                }
                                break;
                            }
                            hit6 = true;
                        }
                        if(hit6)
                        {
                            System.out.println("Transaction completed");
                        }
                        else 
                        {
                            System.out.println("Book not found");
                        }
                        hit6 = false;
                    }
                    break;
                case 10:
                    for(int i=0; i<transaction_count; i++)
                    {
                        System.out.println(transactions[i].getMemberId()+"borrowed "+transactions[i].getBookId());
                    }
                    break;
                case 11:
                    con = false;
                    break;
                default:
                    System.out.println("Invalid input.");
                    break;
            }
        }
        buffer.close();
    }
    static void UI_Statements()
    {
        System.out.println("Choose from the following : ");
        System.out.println("1) Add a book");
        System.out.println("2) Add more copies of a book.");
        System.out.println("3) Display a book");
        System.out.println("4) Display list of books");
        System.out.println("5) Add a member");
        System.out.println("6) View a member");
        System.out.println("7) Login as a member");
        System.out.println("8) Borrow a book");
        System.out.println("9) Return a book");
        System.out.println("10) View all transaction");
        System.out.println("11) Exit");
        System.out.print("Enter your choice : ");
    }
}