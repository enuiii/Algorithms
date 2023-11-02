def check_brackets(s):
    # Стек для открывающихся скобок    stack = []

    # Проходим по каждому символу в выражении    for bracket in s:
        if bracket == '(':
            stack.append(bracket)  # Если встретили открывающуюся скобку, помещаем ее в стек        elif bracket == ')':
            if not stack:
                return False  # Если встретили закрывающуюся скобку и стек пуст, то скобки не сбалансированы            stack.pop()  # Если встретили закрывающуюся скобку и в стеке есть открывающаяся, удалаем ее из стека    # Если после прохода всех символов стек пуст, значит все скобки сбалансированы, иначе есть непарная скобка    return not stack


def count(s):
    if not check_brackets(s):
        return "Неправильное расположение скобок"    operators = '+-*/'  # Допустимые операторы    operator_stack = []  # Стек для операторов    operand_stack = []  # Стек для значений    i = 0    while i < len(s):
        if s[i].isdigit():  # Если текущий символ - цифра            j = i
            while j < len(s) and s[j].isdigit():
                j += 1            value = int(s[i:j])  # Извлекаем число из строки            operand_stack.append(value)
            i = j
        elif s[i] in operators:  # Если текущий символ - оператор            if i + 1 < len(s) and s[i + 1] in operators:  # Если имеется двойной знак оператора                return "Ошибка: повторяющийся знак оператора"            while operator_stack and (operator_stack[-1] in operators) and \
                    operators.index(s[i]) <= operators.index(operator_stack[-1]):
                operator = operator_stack.pop()
                value2 = operand_stack.pop()
                value1 = operand_stack.pop()
                if operator == '+':
                    operand_stack.append(value1 + value2)
                elif operator == '-':
                    operand_stack.append(value1 - value2)
                elif operator == '*':
                    operand_stack.append(value1 * value2)
                elif operator == '/':
                    if value2 == 0:
                        return "Ошибка: деление на ноль"                    operand_stack.append(value1 / value2)

            operator_stack.append(s[i])
            i += 1        elif s[i] == '(':
            operator_stack.append(s[i])
            i += 1        elif s[i] == ')':
            while operator_stack[-1] != '(':
                operator = operator_stack.pop()
                value2 = operand_stack.pop()
                value1 = operand_stack.pop()
                if operator == '+':
                    operand_stack.append(value1 + value2)
                elif operator == '-':
                    operand_stack.append(value1 - value2)
                elif operator == '*':
                    operand_stack.append(value1 * value2)
                elif operator == '/':
                    if value2 == 0:
                        return "Ошибка: деление на ноль"                    operand_stack.append(value1 / value2)

            operator_stack.pop()
            i += 1        elif s[i] == ' ':
            i += 1        else:
            return "Ошибка: недопустимый символ в выражении"    while operator_stack:
        operator = operator_stack.pop()
        value2 = operand_stack.pop()
        value1 = operand_stack.pop()
        if operator == '+':
            operand_stack.append(value1 + value2)
        elif operator == '-':
            operand_stack.append(value1 - value2)
        elif operator == '*':
            operand_stack.append(value1 * value2)
        elif operator == '/':
            if value2 == 0:
                return "Ошибка: деление на ноль"            operand_stack.append(value1 / value2)

    if len(operand_stack) == 1:
        return operand_stack[0]
    else:
        return "Неверное выражение"s = input("Введите выражение: ")

if not s.endswith('='):
    print("Нет '=' ")
else:
    ss = s.rstrip('=')
    res = count(ss)
    print(s, res)
