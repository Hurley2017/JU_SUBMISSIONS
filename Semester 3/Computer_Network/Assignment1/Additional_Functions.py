# Function to convert an arithmetic expression to postfix notation
def Arithmatic_Expression_Infix_to_PostFix(arg):
    Stack = []  # Initialize a stack for operators
    res = []    # Initialize a list for postfix expression
    Precedence = lambda X : 2 if X in ['+', '-'] else 3 if X in ['/', '*'] else 1 if X in ['(', ')'] else 0
    for char in arg:
        if char in ['+', '-', '*', '/']:
            while len(Stack) != 0 and Precedence(Stack[-1]) >= Precedence(char):
                res.append(Stack.pop())
            Stack.append(char)
        elif char == '(':
            Stack.append(char)
        elif char == ')':
            while len(Stack) != 0 and Stack[-1] != '(':
                res.append(Stack.pop())
            Stack.pop()
        else:
            res.append(char)
    return res + Stack[::-1]

    

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
    arg = arg.replace(' ', '')  # Remove all spaces from the expression
    temp = ''  # Initialize a temporary string for storing operands
    res = []   # Initialize a list for tokenized result
    for char in arg:
        if char in ['+', '-', '*', '/', ')', '('] and temp == '':
            res.append(char)  # Append operator directly if no operand yet
        elif char in ['+', '-', '*', '/', ')', '('] and temp != '':
            res.append(temp)  # Append operand
            res.append(char)  # Append operator
            temp = ''  # Reset temporary operand string
        else:
            temp += char  # Continue building the operand string
    if temp != '':
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