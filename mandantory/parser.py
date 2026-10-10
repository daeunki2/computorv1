from polynomial import Polynomial

def validate_expression(expression):

    if expression.count("=") != 1:
        raise ValueError("Invalid equal sign")

    for char in expression:
        if char not in "0123456789X^*+-= .":
            raise ValueError("Invalid character")

    left, right = expression.split("=")
    left = left.strip()
    right = right.strip()

    if not left or not right:
        raise ValueError("Empty side")

    for side in (left, right):
        compact = side.replace(" ", "")

        operators = "+-*/^"

        for i in range(len(compact) - 1):
            if compact[i] in operators and compact[i + 1] in operators:
                raise ValueError("Consecutive operators")

        if compact[-1] in operators:
            raise ValueError("Invalid ending")
        
def split_terms(expression):
    terms = []
    current = ""

    for char in expression.replace(" ", ""):
        if char in "+-" and current:
            terms.append(current)
            current = char
        else:
            current += char

    if current:
        terms.append(current)

    return terms

def parse(expression):
    validate_expression(expression)

    left, right = expression.split("=")
    polynomial = Polynomial()

    for side, sign in ((left, 1), (right, -1)):
        terms = split_terms(side)

        for term in terms:
            parts = term.split("*")

            if len(parts) != 2:
                raise ValueError("Invalid term")

            coefficient = float(parts[0])

            variable = parts[1].split("^")

            if len(variable) != 2 or variable[0] != "X":
                raise ValueError("Invalid term")

            exponent = int(variable[1])

            polynomial.add_term(exponent, coefficient * sign)

    return polynomial