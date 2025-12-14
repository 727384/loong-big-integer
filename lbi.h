#ifndef ibi
#define ibi
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <stdexcept>
#define Infinity loong::pow(loong::lBI({2, 0}), loong::lBI({1.024, 3}))
#define Nev_Infinity loong::neg(loong::pow(loong::lBI({2, 0}), loong::lBI({1.024, 3})))
#define True_Infinity int_to_lBI(pow(2, 1024))
namespace loong
{
	struct lBI;
	lBI int_to_lBI(double a);
	lBI plus(lBI a, lBI b);
	lBI minus(lBI a, lBI b);
	lBI multi(lBI a, lBI b);
	lBI div(lBI a, lBI b);
	lBI div_no_error(lBI a, lBI b);
	lBI log10(lBI a);
	lBI logx(lBI a, lBI b);
	lBI pow(lBI a, lBI b, bool not_from_sqrtx = 1);
	lBI sqrtx(lBI a, lBI b);
	lBI sqrt(lBI a);
	lBI abs(lBI a);
	lBI reci(lBI a);
	lBI neg(lBI a);
	lBI lBI_format(lBI a);
	lBI print_lBI(lBI a, int b, bool c);
	double lBI_to_int(lBI a);
	std::string lBI_to_str(lBI a, int b);
	std::istream& operator>>(std::istream& is, lBI& p);
	std::ostream& operator<<(std::ostream& os, const lBI& p);
	struct lBI
	{
		double x;
		double e;
		lBI input()
		{
			scanf("%lf%lf", &x, &e);
			return (*this).format();
		}
		lBI print(int a = 9, bool b = 0)
		{
			if (a == 0)
			{
				printf("%lfe%lg", x, e);
			}
			if (a == 1)
			{
				printf("%lf %lg", x, e);
			}
			if (a == 2)
			{
				printf("%lfx10^%lg", x, e);
			}
			if (a == 3)
			{
				printf("%lf*10^%lg", x, e);
			}
			if (a == 4)
			{
				if (*this < lBI({0, 0}))
				{
					printf("-e%lg", log10(neg({x, e})).to_int());
				}
				else if (*this == lBI({0, 0}))
				{
					printf("e(-inf)");
				}
				else
				{
					printf("e%lg", log10({x, e}).to_int());
				}
			}
			if (a == 5)
			{
				printf("e%lg", e);
			}
			if (a == 6)
			{
				if (*this < lBI({0, 0}) && neg({x, e}) >= lBI({0, 0}))
				{
					printf("-ee%lg", log10(log10(neg({x, e}))).to_int());
				}
				else if (*this == lBI({0, 0}) || log10(neg({x, e})) <= lBI({0, 0}))
				{
					throw std::invalid_argument("Invalid input");
				}
				else
				{
					printf("ee%lg", log10(log10({x, e})).to_int());
				}
			}
			if (a == 7)
			{
				if (*this < lBI({0, 0}) && neg({x, e}) >= lBI({0, 0}))
				{
					printf("-10^^%lg", log10(log10(neg({x, e}))).to_int());
				}
				else if (*this == lBI({0, 0}) || log10(neg({x, e})) <= lBI({0, 0}))
				{
					throw std::invalid_argument("Invalid input");
				}
				else
				{
					printf("10^^%lg", log10(log10({x, e})).to_int());
				}
			}
			if (a == 8)
			{
				printf("%lg", lBI_to_int(*this));
			}
			if (a == 9)
			{
				if (std::fabs(e) < 9)
				{
					printf("%lg", lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e9)
				{
					printf("%lfe%lg", x, e);
				}
				else 
				{
					printf("e%lg", log10({x, e}).to_int());
				}
			}			
			if (b)
			{
				printf("\n");
			}
			return {x, e};
		}
		std::string to_str(int a = 9)
		{
			if (a == 0)
			{
				return std::to_string(x) + "e" + std::to_string(e);
			}
			if (a == 1)
			{
				return std::to_string(x) + " " + std::to_string(e);
			}
			if (a == 2)
			{
				return std::to_string(x) + "x10^" + std::to_string(e);
			}
			if (a == 3)
			{
				return std::to_string(x) + "*10^" + std::to_string(e);
			}
			if (a == 4)
			{
				return "e" + std::to_string(log10({x, e}).to_int());
			}
			if (a == 5)
			{
				return "e" + std::to_string(e);
			}
			if (a == 6)
			{
				if (*this < lBI({0, 0}) && neg({x, e}) >= lBI({0, 0}))
				{
					return "-ee" + std::to_string(log10(log10(neg({x, e}))).to_int());
				}
				else if (*this == lBI({0, 0}) || log10(neg({x, e})) <= lBI({0, 0}))
				{
					throw std::invalid_argument("Invalid input");
				}
				else
				{
					return "ee" + std::to_string(log10(log10({x, e})).to_int());
				}
			}
			if (a == 7)
			{
				if (*this < lBI({0, 0}) && neg({x, e}) >= lBI({0, 0}))
				{
					return "-10^^" + std::to_string(log10(log10(neg({x, e}))).to_int());
				}
				else if (*this == lBI({0, 0}) || log10(neg({x, e})) <= lBI({0, 0}))
				{
					throw std::invalid_argument("Invalid input");
				}
				else
				{
					return "10^^" + std::to_string(log10(log10({x, e})).to_int());
				}
			}
			if (a == 8)
			{
				return std::to_string(lBI_to_int(*this));
			}
			if (a == 9)
			{
				if (std::fabs(e) < 9)
				{
					return std::to_string(lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e9)
				{
					return std::to_string(x) + "e" + std::to_string(e);
				}
				else 
				{
					return "e" + std::to_string(log10({x, e}).to_int());
				}
			}
		}
		double to_int()
		{
			if (std::isnan(x * std::pow(10, e)))
			{
				throw std::out_of_range("Number is out of -2^1024 ~ 2^1024");
			}
			return x * std::pow(10, e);
		}
		lBI format()
		{
			if (std::floor(e) != e)
			{
				x *= std::pow(10, e - floor(e));
				e = floor(e);
			}
			if (x == 0)
			{
				x = 0;
				e = 0;
			}
			else if (x < 1)
			{
				e += floor(std::log10(fabs(x)));
				x = x / std::pow(10, floor(std::log10(fabs(x))));
			}
			else if (x >= 10)
			{
				e += floor(std::log10(fabs(x)));
				x = x / std::pow(10, floor(std::log10(fabs(x))));
			}
			else
			{
				x = x;
				e = e;
			}
			return {x, e};
		}
		lBI operator+(const lBI t)const
		{
			lBI tmp = {};
			if (t.e > e)
			{
				tmp = {t.x + x * std::pow(10, e - t.e), t.e};
			}
			else if (t.e < e)
			{
				tmp = {t.x * std::pow(10, t.e - e) + x, e};
			}
			else
			{
				tmp = {t.x + x, e};
			}
			return tmp.format();
		}
		lBI operator-(const lBI t)const
		{
			lBI tmp = {};
			if (e > t.e)
			{
				tmp = {x - t.x * std::pow(10, t.e - e), e};
			}
			else if (e < t.e)
			{
				tmp = {x * std::pow(10, e - t.e) - t.x, t.e};
			}
			else
			{
				tmp = {x - t.x, e};
			}
			return tmp.format();
		}
		lBI operator*(const lBI t)const
		{
			lBI tmp = {t.x * x, t.e + e};
			return tmp.format();
		}
		lBI operator/(const lBI t)const
		{
			if (t.x == 0)
			{
				throw std::invalid_argument("Division by zero error");
			}
			lBI tmp = {x / t.x, e - t.e};
			return tmp.format();
		}
		lBI operator<<(const lBI t)const
		{
			lBI tmp = {x, e};
			return tmp * pow(lBI({2, 0}), t);
		}
		lBI operator>>(const lBI t)const
		{
			lBI tmp = {x, e};
			return tmp / pow(lBI({2, 0}), t);
		}
		bool operator>(const lBI t)const
		{
			lBI tmp = {x, e};
			lBI ttmp = {t.x, t.e};
			tmp.format();
			ttmp.format();
			if (tmp.x <= 0 && ttmp.x > 0)
			{
				return false;
			}
			if (tmp.x > 0 && ttmp.x <= 0)
			{
				return true;
			}
			if (tmp.x >= 0 && ttmp.x >= 0)
			{
				if (tmp.e > ttmp.e)
				{
					return true;
				}
				else if (tmp.e < ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x > ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (tmp.e < ttmp.e)
				{
					return true;
				}
				else if (tmp.e > ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x > ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool operator>=(const lBI t)const
		{
			lBI tmp = {x, e};
			lBI ttmp = {t.x, t.e};
			tmp.format();
			ttmp.format();
			if (tmp.x <= 0 && ttmp.x > 0)
			{
				return false;
			}
			if (tmp.x > 0 && ttmp.x <= 0)
			{
				return true;
			}
			if (tmp.x >= 0 && ttmp.x >= 0)
			{
				if (tmp.e > ttmp.e)
				{
					return true;
				}
				else if (tmp.e < ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x >= t.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (tmp.e < ttmp.e)
				{
					return true;
				}
				else if (tmp.e > ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x >= t.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool operator<(const lBI t)const
		{
			lBI tmp = {x, e};
			lBI ttmp = {t.x, t.e};
			tmp.format();
			ttmp.format();
			if (tmp.x <= 0 && ttmp.x > 0)
			{
				return true;
			}
			if (tmp.x > 0 && ttmp.x <= 0)
			{
				return false;
			}
			if (tmp.x >= 0 && ttmp.x >= 0)
			{
				if (tmp.e < ttmp.e)
				{
					return true;
				}
				else if (tmp.e > ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x < ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (tmp.e > ttmp.e)
				{
					return true;
				}
				else if (tmp.e < ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x < ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool operator<=(const lBI t)const
		{
			lBI tmp = {x, e};
			lBI ttmp = {t.x, t.e};
			tmp.format();
			ttmp.format();
			if (tmp.x <= 0 && ttmp.x > 0)
			{
				return true;
			}
			if (tmp.x > 0 && ttmp.x <= 0)
			{
				return false;
			}
			if (tmp.x >= 0 && ttmp.x >= 0)
			{
				if (tmp.e < ttmp.e)
				{
					return true;
				}
				else if (tmp.e > ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x <= ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (tmp.e > ttmp.e)
				{
					return true;
				}
				else if (tmp.e < ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x <= ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool operator==(const lBI t)const
		{
			lBI tmp = {x, e};
			lBI ttmp = {t.x, t.e};
			tmp.format();
			ttmp.format();
			if (tmp.e == ttmp.e && tmp.x == ttmp.x)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator!=(const lBI t)const
		{
			lBI tmp = {x, e};
			lBI ttmp = {t.x, t.e};
			tmp.format();
			ttmp.format();
			if (tmp.e != ttmp.e || tmp.x != ttmp.x)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		lBI operator+=(const lBI t)
		{
			lBI tmp = *this;
			*this = t + tmp;
			return t + tmp;
		}
		lBI operator-=(const lBI t)
		{
			lBI tmp = *this;
			*this = tmp - t;
			return tmp - t;
		}
		lBI operator*=(const lBI t)
		{
			lBI tmp = *this;
			*this = t * tmp;
			return t * tmp;
		}
		lBI operator/=(const lBI t)
		{
			lBI tmp = *this;
			*this = tmp / t;
			return tmp / t;
		}
		lBI operator++()
		{
			lBI tmp = *this;
			*this = tmp + lBI({1, 0});
			return tmp + lBI({1, 0});
		}
		lBI operator--()
		{
			lBI tmp = *this;
			*this = *this - lBI({1, 0});
			return tmp - lBI({1, 0});
		}
		lBI operator++(int)
		{
			lBI tmp = *this;
			*this = tmp + lBI({1, 0});
			return tmp;
		}
		lBI operator--(int)
		{
			lBI tmp = *this;
			*this = *this - lBI({1, 0});
			return tmp;
		}
		lBI operator<<=(const lBI t)
		{
			lBI tmp = *this;
			*this = t << tmp;
			return t << tmp;
		}
		lBI operator>>=(const lBI t)
		{
			lBI tmp = *this;
			*this = t >> tmp;
			return t >> tmp;
		}
		lBI()
		{
			this->x = 0;
			this->e = 0;			 
		}
		lBI(double a)
		{
			lBI tmp = int_to_lBI(a);
			this->x = tmp.x;
			this->e = tmp.e;
		}
		lBI(double a, double b)
		{
			this->x = a;
			this->e = b;
		}
	};
	lBI int_to_lBI(double a = 0)
	{
		if (a < 0)
		{
			return {(- a) / std::pow(10, floor(std::log10(std::abs(a)))), floor(std::log10(std::abs(a)))};
		}
		else if (a == 0)
		{
			return {0, 0};
		}
		else
		{
			return {a / std::pow(10, floor(std::log10(a))), floor(std::log10(a))};
		}
	}
	lBI plus(lBI a, lBI b)
	{
		return a + b;
	}
	lBI minus(lBI a, lBI b)
	{
		return a - b;
	}
	lBI multi(lBI a, lBI b)
	{
		return a * b;
	}
	lBI div(lBI a, lBI b)
	{
		return a / b;
	}
	lBI div_no_error(lBI a, lBI b)
	{
		lBI tmp = {a.x / b.x, a.e - b.e};
		return tmp.format();
	}
	lBI log10(lBI a)
	{
		if (a <= lBI({0, 0}))
		{
			throw std::invalid_argument("Natural number is invalid");
		}
		return int_to_lBI(std::log10(a.x) + a.e);
	}
	lBI logx(lBI a, lBI b = {1, 1})
	{
		if (((b <= lBI({0, 0})) || (b == lBI({1, 0}))) && (a <= lBI({0, 0})))
		{
			throw std::invalid_argument("Base number and natural number are invalid");
		}
		if ((b <= lBI({0, 0})) || (b == lBI({1, 0})))
		{
			throw std::invalid_argument("Base number is invalid");
		}
		if (a <= lBI({0, 0}))
		{
			throw std::invalid_argument("Natural number is invalid");
		}
		return log10(a) / log10(b);
	}
	lBI pow(lBI a, lBI b, bool not_from_sqrtx)
	{
		/*
		lBI tmpb = reci(b);
		if ((a < lBI({0, 0})) && (((std::abs((fmod(tmpb.x, 2 / std::pow(10, tmpb.e)))) * std::pow(10, tmpb.e)) <= 1e-8) || ((std::abs(std::abs((fmod(tmpb.x, 2 / std::pow(10, tmpb.e))) - 2 / std::pow(10, tmpb.e))) * std::pow(10, tmpb.e)) <= 1e-8)))
		{
			throw std::invalid_argument("Base number is invalid");
		}
		*/
		lBI tmp = {0, 0};
		if (a.x == 1)
		{
			tmp.e = (int_to_lBI(a.e) * b).to_int();
		}
		else
		{
			tmp.e = (int_to_lBI(a.e) * b + b * int_to_lBI(std::log10(a.x))).to_int();
		}
		tmp.x = 1;
		tmp.format();
		if ((std::isnan(tmp.x) || std::isnan(tmp.e)) && not_from_sqrtx)
		{
			throw std::invalid_argument("Base number is invalid");
		}
		return tmp;
	}
	lBI sqrtx(lBI a, lBI b = {2, 0})
	{
		/*
		if ((a < lBI({0, 0})) && (((std::abs((fmod(b.x, 2 / std::pow(10, b.e)))) * std::pow(10, b.e)) <= 1e-8) || ((std::abs(std::abs((fmod(b.x, 2 / std::pow(10, b.e))) - 2 / std::pow(10, b.e))) * std::pow(10, b.e)) <= 1e-8)))
		{
			throw std::invalid_argument("Radicand number is invalid");
		}
		*/
		lBI tmp = pow(a, lBI({1, 0}) / b, 0);
		if (std::isnan(tmp.x) || std::isnan(tmp.e))
		{
			throw std::invalid_argument("Radicand number is invalid");
		}
		return tmp;
	}
	lBI sqrt(lBI a)
	{
		return sqrtx(a, lBI({2, 0}));
	}
	lBI abs(lBI a)
	{
		return {fabs(a.x), a.e};
	}
	lBI reci(lBI a)
	{
		return lBI({1, 0}) / a;
	}
	lBI neg(lBI a)
	{
		return lBI({0, 0}) - a;
	}
	lBI lBI_format(lBI a)
	{
		return a.format();
	}
	lBI print_lBI(lBI a, int b = 9, bool c = 0)
	{
		return a.print(b, c);
	}
	double lBI_to_int(lBI a)
	{
		return a.to_int();
	}
	std::string lBI_to_str(lBI a, int b = 9)
	{
		return a.to_str(b);
	}
	std::istream& operator>>(std::istream& is, lBI& p) 
	{
	    is >> p.x >> p.e;
	    p.format();
	    return is; 
	}
	std::ostream& operator<<(std::ostream& os, const lBI& p) 
	{
		if (std::fabs(p.e) < 9)
		{
			os << lBI_to_int(p);
		}
		else if (std::fabs(p.e) < 1e9)
		{
			os << p.x << "e" << p.e;
		}
		else 
		{
			os << "e" << log10(p).to_int();
		}
	    return os; 
	}
}
#endif
