import math


def solve_zero(polynomial):
    if polynomial.degree() == -1:
        print("All real numbers are solutions.")
    else:
        print("No solution.")


def solve_linear(polynomial):
    a = polynomial.get_coefficient(1)
    b = polynomial.get_coefficient(0)

    solution = -b / a

    print("The solution is:")
    print(solution)


def solve_quadratic(polynomial):
    a = polynomial.get_coefficient(2)
    b = polynomial.get_coefficient(1)
    c = polynomial.get_coefficient(0)

    delta = b ** 2 - 4 * a * c

    if delta > 0:
        x1 = (-b - math.sqrt(delta)) / (2 * a)
        x2 = (-b + math.sqrt(delta)) / (2 * a)

        print("Discriminant is strictly positive, the two solutions are:")
        print(x1)
        print(x2)

    elif delta == 0:
        x = -b / (2 * a)

        print("Discriminant is zero, the solution is:")
        print(x)

    else:
        print("Discriminant is strictly negative, no real solution.")


def solve(polynomial):
    degree = polynomial.degree()
    terms = []

    for exponent in sorted(polynomial.coefficients):
        coefficient = polynomial.get_coefficient(exponent)

        if not terms:
            terms.append(f"{coefficient} * X^{exponent}")
        elif coefficient < 0:
            terms.append(f"- {abs(coefficient)} * X^{exponent}")
        else:
            terms.append(f"+ {coefficient} * X^{exponent}")

    reduced = " ".join(terms) if terms else "0 * X^0"

    print(f"Reduced form: {reduced} = 0")
    print(f"Polynomial degree: {max(degree, 0)}")

    if degree <= 0:
        solve_zero(polynomial)
    elif degree == 1:
        solve_linear(polynomial)
    elif degree == 2:
        solve_quadratic(polynomial)
    else:
        print("The polynomial degree is strictly greater than 2, I can't solve.")

