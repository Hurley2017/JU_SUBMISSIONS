# Function to convert an arithmetic expression to postfix notation
def Arithmatic_Expression_to_PostFix(arg):
    Stack = []  # Initialize a stack for operators
    PostFix = []  # Initialize a list to store postfix notation
    Precedence = lambda x: 1 if x in ['+', '-'] else 2 if x in ['*', '/'] else 0  # Define operator precedence
    for element in arg:
        if element in ['+', '-', '*', '/']:
            while Stack and Precedence(Stack[-1]) >= Precedence(element):
                PostFix.append(Stack.pop())
            Stack.append(element)
        else:
            PostFix.append(element)
    while Stack:
        PostFix.append(Stack.pop())
    return PostFix

# Function to evaluate a postfix expression
def PostFix_Expression_Evaluation(PostFix):
    Stack = []  # Initialize a stack for operands
    for char in PostFix:
        if char in ['+', '-', '*', '/']:
            Operand1 = Stack.pop()
            Operand2 = Stack.pop()
            if char == '+':
                Stack.append(Operand2 + Operand1)
            elif char == '-':
                Stack.append(Operand2 - Operand1)
            elif char == '*':
                Stack.append(Operand2 * Operand1)
            elif char == '/':
                Stack.append(Operand2 / Operand1)
        else:
            Stack.append(int(char))
    return Stack.pop()

# Function to tokenize an expression into operands and operators
def Tokenizing_Operands(arg):
    temp = ''  # Initialize a temporary string for storing operands
    res = []   # Initialize a list for tokenized result
    for char in arg:
        if char in ['+', '-', '*', '/'] and temp == '':
            res.append(char)  # Append operator directly if no operand yet
        elif char in ['+', '-', '*', '/'] and temp != '':
            res.append(temp)  # Append operand
            res.append(char)  # Append operator
            temp = ''  # Reset temporary operand string
        else:
            temp += char  # Continue building the operand string
    res.append(temp)  # Append the last operand
    return res

# Function to read data from a file and create a dictionary
def Read_File():
    Collective_Info = {}  # Initialize an empty dictionary
    name = ''  # Initialize a variable to store the name
    with open('./Files/input.txt', 'r') as file:
        data = file.read()  # Read data from the file
    for line in data.split('\n'):
        name = line.split(' ')[0] + ' ' + line.split(' ')[1]  # Extract the name from the line
        Collective_Info[name] = ' '.join(line.split(' ')[2:])  # Store the associated info in the dictionary
    return Collective_Info