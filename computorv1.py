import sys

# 등호를 기준으로 좌변과 우변을 나눈다.
def split_equation(equation):
    equation = equation.strip()
    parts = equation.split("=")
    left = parts[0].strip()
    right = parts[1].strip()
    return left, right

# 변의 항을 정리한다. 
def parse_side(side):
    terms = split_terms(side) # 항 분리
    coeffs = {}
    for term in terms:
        degree, coefficient = parse_term(term) # 계수 차수 추출
        coeffs[degree] = coeffs.get(degree, 0) + coefficient # 기존의 차수가 있다면 바로 더하기 혹은 빼기
    return coeffs

# 하나의 항으로 나눈다. -의 경우 +-로 대치해 처리한다.
def split_terms(side):
    side = side.replace("-", "+-")
    parts = side.split("+")
    terms = []
    for part in parts:
        part = part.strip()
        if part != "":
            terms.append(part)
    return terms

#하나의 항을 계수와 차수로 나눈다.
def parse_term(term):
    temp = term.split("*")
    coefficient = float(temp[0].strip())
    exponent_text = temp[1].strip()
    exponent = int(exponent_text.split("^")[1])
    return exponent, coefficient

#이항정리
def reduce_equation(left_coeffs, right_coeffs):
    coeffs = left_coeffs.copy()

    for degree, coefficient in right_coeffs.items():
        if degree in coeffs:
            coeffs[degree] -= coefficient
        else:
            coeffs[degree] = -coefficient

    return coeffs

#차수 추출
def get_degree(coeffs):
    degree = 0

    for exponent, coefficient in coeffs.items():
        if coefficient != 0 and exponent > degree:
            degree = exponent

    return degree

def format_reduced_form(coeffs):
    pass

def solve_degree_0(coeffs):
    pass

def solve_degree_1(coeffs):
    pass

def solve_degree_2(coeffs):
    pass

def solve_equation(coeffs, degree):
    if degree == 0:
        solve_degree_0(coeffs)
    elif degree == 1:
        solve_degree_1(coeffs)
    elif degree == 2:
        solve_degree_2(coeffs)
    else:
        print("The polynomial degree is strictly greater than 2, I can't solve.")

def main():
    equation = input("Equation: ")

    left, right = split_equation(equation)

    left_coeffs = parse_side(left)
    right_coeffs = parse_side(right)

    coeffs = reduce_equation(left_coeffs, right_coeffs)

    print("Reduced form:", format_reduced_form(coeffs))
    
    degree = get_degree(coeffs)
    print("Polynomial degree:", degree)

    solve_equation(coeffs, degree)


if __name__ == "__main__":
    main()
