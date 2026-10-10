# Computor v1

A polynomial equation solver written in Python.

This project is part of the 42 curriculum. Its objective is to understand polynomial equations, implement mathematical operations, and solve equations of degree 2 or lower without relying on external mathematical libraries.

## 1. Project Objectives

The program takes a polynomial equation as input and:

1. Parses the equation.
2. Moves all terms to the left-hand side.
3. Reduces the equation to its simplified form.
4. Determines the polynomial degree.
5. Calculates the solutions when the degree is 2 or lower.
6. Displays the results.

**Example**

Input:

```bash
python3 computor.py "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
```

Expected output:

```text
Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
Polynomial degree: 2
Discriminant is strictly positive, the two solutions are:
0.905239
-0.475131
```

## 2. Mathematical Concepts

### 2.1 Polynomial

A polynomial is an expression consisting of coefficients, variables, and non-negative integer exponents.

For example:

P(x) = 5 + 4x - 9.3x²

- 5 is the constant term.
- 4 is the coefficient of x.
- -9.3 is the coefficient of x².
- The polynomial degree is 2.

### 2.2 Reduced Form

Every equation must be transformed into:

P(x) = 0

For example:

5 + 4x - 9.3x² = 1

becomes:

4 + 4x - 9.3x² = 0

This is achieved by subtracting the right-hand polynomial from the left-hand polynomial.

### 2.3 Polynomial Degree

The degree is the highest exponent whose coefficient is not zero.

- Degree 0: constant equation
- Degree 1: linear equation
- Degree 2: quadratic equation
- Degree greater than 2: not supported

The zero polynomial is handled as a special case.

### 2.4 Solving Equations

**Degree 0**

a = 0

- If a = 0: every real number is a solution.
- Otherwise: no solution.

**Degree 1**

ax + b = 0

Solution:

x = -b / a

**Degree 2**

ax² + bx + c = 0

Discriminant:

Δ = b² - 4ac

Three possible cases:

- Δ > 0: two distinct real solutions.
- Δ = 0: one repeated real solution.
- Δ < 0: two complex solutions.

For Δ > 0:

x₁ = (-b + √Δ) / (2a)

x₂ = (-b - √Δ) / (2a)

For Δ = 0:

x = -b / (2a)

For Δ < 0:

x₁ = (-b + i√(-Δ)) / (2a)

x₂ = (-b - i√(-Δ)) / (2a)

## 3. Mandatory Requirements

- [ ] Parse polynomial equations.
- [ ] Support integer, decimal, negative, and zero coefficients.
- [ ] Reduce equations to P(x) = 0.
- [ ] Display the reduced form.
- [ ] Determine and display the polynomial degree.
- [ ] Solve degree 0 equations.
- [ ] Solve degree 1 equations.
- [ ] Solve degree 2 equations.
- [ ] Handle positive, zero, and negative discriminants.
- [ ] Display complex solutions when necessary.
- [ ] Reject equations of degree greater than 2.
- [ ] Accept equations through command-line arguments.
- [ ] Read an equation from standard input when no argument is provided.
- [ ] Implement required mathematical operations without prohibited math library functions.

## 4. Bonus Features

- [ ] Detect vocabulary and syntax errors.
- [ ] Support free-form expressions.
- [ ] Display solutions as irreducible fractions when appropriate.
- [ ] Display intermediate calculation steps.

Example of free-form input:

```text
5 + 4 * X + X^2 = X^2
```

Expected reduced form:

```text
5 + 4 * X = 0
```

## 5. Architecture

The project uses a hybrid architecture combining object-oriented programming and independent functions.

```text
computorv1/
├── computor.py
├── polynomial.py
├── parser.py
├── solver.py
├── README.md
└── .gitignore
```

### polynomial.py

Contains the `Polynomial` class.

Responsibilities:

- Store polynomial coefficients.
- Add terms.
- Combine terms with identical exponents.
- Subtract polynomials.
- Determine the polynomial degree.

Internal representation:

```python
{
    0: 4,
    1: 4,
    2: -9.3
}
```

Keys represent exponents. Values represent coefficients.

### parser.py

Converts input strings into polynomial objects.

Responsibilities:

- Separate the left-hand and right-hand sides.
- Extract coefficients and exponents.
- Validate input.
- Support free-form expressions for the bonus.

### solver.py

Contains the mathematical solving functions.

Responsibilities:

- Handle degree 0, 1, and 2 equations.
- Calculate the discriminant.
- Calculate real and complex solutions.
- Implement square root calculation without prohibited mathematical library functions.

### computor.py

The program entry point.

Responsibilities:

- Read command-line arguments or standard input.
- Call the parser.
- Reduce the equation.
- Call the solver.
- Display results and errors.

## 6. Execution Flow

```text
User Input
    |
    v
Parser
    |
    v
Polynomial Objects
    |
    v
Reduction (Left - Right)
    |
    v
Degree Detection
    |
    v
Solver
    |
    v
Formatted Output
```

## 7. Implementation Plan

**Phase 1 — Polynomial**

Implement the `Polynomial` class and its basic operations.

**Phase 2 — Parser**

Convert valid polynomial expressions into objects.

**Phase 3 — Reduction**

Move all terms to the left-hand side and combine coefficients.

**Phase 4 — Solver**

Implement degree 0, 1, and 2 equation solving.

**Phase 5 — Bonus**

Add flexible parsing, error handling, fractions, and calculation steps.

**Phase 6 — Testing**

Verify the examples from the subject and test edge cases.

## 8. Constraints

- Python is the chosen implementation language.
- No external mathematical solver.
- Mathematical functions prohibited by the subject must be implemented manually.
- The mandatory part must work correctly before bonus features are evaluated.
- Only submitted repository files will be evaluated.

## 9. Learning Goals

By completing this project, we aim to practice:

- Python classes and objects
- Dictionaries
- String parsing
- Error handling
- Separation of responsibilities
- Polynomial mathematics
- Algorithm implementation
- Unit testing
