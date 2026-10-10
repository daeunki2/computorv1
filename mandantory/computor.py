import sys

from parser import parse
from solver import solve


def main():
    if len(sys.argv) != 2:
        print("Usage: python3 computor.py \"equation\"")
        return

    try:
        polynomial = parse(sys.argv[1])
        solve(polynomial)

    except ValueError as error:
        print(f"Error: {error}")


if __name__ == "__main__":
    main()
    
    

# python3 computor.py "2 * X^1 + 4 * X^0 = 0 * X^0"
# python3 computor.py "5 * X^0 = 3 * X^0"
# python3 computor.py "5 * X^0 = 5 * X^0"
# python3 computor.py "1 * X^2 - 4 * X^1 + 4 * X^0 = 0 * X^0"
# python3 computor.py "1 * X^3 + 2 * X^0 = 0 * X^0"
# python3 computor.py "1 * X^2 + 1 * X^0 = 0 * X^0"
# python3 computor.py "1 * X^3 - 1 * X^3 + 2 * X^1 = 0 * X^0"
# python3 computor.py "hello"