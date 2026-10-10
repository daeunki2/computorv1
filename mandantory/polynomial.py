class Polynomial:
    def __init__(self):
        self.coefficients = {}

    def add_term(self, exponent, coefficient):
        if type(exponent) is not int or exponent < 0:
            raise ValueError("Invalid exponent")

        if type(coefficient) not in (int, float):
            raise ValueError("Invalid coefficient")

        original = self.coefficients.get(exponent, 0)
        total = original + coefficient

        if total == 0:
            self.coefficients.pop(exponent, None)
        else:
            self.coefficients[exponent] = total

    def degree(self):
        if not self.coefficients:
            return -1

        return max(self.coefficients)

    def get_coefficient(self, exponent):
        return self.coefficients.get(exponent, 0)