def Arithmatic_Expression_to_PostFix(arg):
    Stack = []
    PostFix = []
    Precedence = lambda x: 1 if x in ['+', '-'] else 2 if x in ['*', '/'] else 0
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

def PostFix_Expression_Evaluation(PostFix):
    Stack = []
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

def Tokenizing_Operands(arg):
    temp = ''
    res = []
    for char in arg:
        if char in ['+', '-', '*', '/'] and temp == '':
            res.append(char)
        elif char in ['+', '-', '*', '/'] and temp != '':
            res.append(temp)
            res.append(char)
            temp = ''
        else:
            temp += char
    res.append(temp)
    return res