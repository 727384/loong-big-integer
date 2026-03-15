from math import log10, floor
class lBI:
    x = 0
    e = 0
    def lBI_format(self):
        if self.x < 0:
            if self.x > -1 or self.x <= -10:
                self.e += floor(log10(- self.x))
                self.x /= 10 ** floor(log10(- self.x))
        elif self.x > 0:
            if self.x < 1 or self.x >= 10:
                self.e += floor(log10(self.x))
                self.x /= 10 ** floor(log10(self.x))
        else:
            self.x = 0
            self.e = 0
        return self
    def __init__(self, x = 0, e = 0):
        self.x = x
        self.e = e
        self.lBI_format()
    def __add__(self, other):
        tmp = lBI()
        if self.e < other.e:
            tmp = lBI(self.x * (10 ** (self.e - other.e)) + other.x, other.e)
        elif self.e > other.e:
            tmp = lBI(self.x + other.x * (10 ** (other.e - self.e)), self.e)
        else:
            tmp = lBI(self.x + other.x, other.e)
        return tmp.lBI_format()
    def __sub__(self, other):
        tmp = lBI()
        if self.e < other.e:
            tmp = lBI(self.x * (10 ** (self.e - other.e)) - other.x, other.e)
        elif self.e > other.e:
            tmp = lBI(self.x - other.x * (10 ** (other.e - self.e)), self.e)
        else:
            tmp = lBI(self.x - other.x, other.e)
        return tmp.lBI_format()
    def __mul__(self, other):
        tmp = lBI(self.x * other.x, self.e + other.e)
        return tmp.lBI_format()
    def __truediv__(self, other):
        tmp = lBI(self.x / other.x, self.e - other.e)
        return tmp.lBI_format()
    def __str__(self):
        if abs(self.e) < 6:
            return str(self.x * (10 ** self.e))
        elif abs(self.e) < 1e6:
            return f'{self.x}e{self.e}'
        else:
            if self.x < 0:
                return f"-e{log10(- self.x) + self.e}"
            else:
                return f"e{log10(self.x) + self.e}"
    def __neg__(self):
        tmp = self
        tmp.x = - tmp.x
        return tmp.lBI_format()

