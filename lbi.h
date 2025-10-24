#ifndef ibi
#define ibi
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <stdexcept>
#define Infinity {1.79769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216, 308}
#define Nev_Infinity {-1.79769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216, 308}
namespace loong
{
	struct lBI;
	lBI int_to_lBI(double a);
	lBI div_no_error(lBI a, lBI b);
	lBI log10(lBI a);
	lBI logx(lBI a, lBI b);
	lBI pow(lBI a, lBI b);
	lBI sqrtx(lBI a, lBI b);
	lBI sqrt(lBI a);
	lBI abs(lBI a);
	lBI reci(lBI a);
	lBI neg(lBI a);
	lBI lBI_format(lBI a);
	std::istream& operator>>(std::istream& is, lBI& p);
	std::ostream& operator<<(std::ostream& os, const lBI& p);
	struct lBI
	{
		double x;
		double e;
		lBI input()
		{
			scanf("%lf%lf", &x, &e);
			return {x, e};
		}
		lBI print(int a = 0, bool b = 1)
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
				printf("e%lg", log10({x, e}).to_int());
			}
			if (a == 5)
			{
				printf("e%lg", e);
			}
			if (a == 6)
			{
				printf("ee%lg", std::log10(log10({x, e}).to_int()));
			}
			if (b)
			{
				printf("\n");
			}
			return {x, e};
		}
		std::string to_str(int a = 0)
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
				return "ee" + std::to_string(std::log10(log10({x, e}).to_int()));
			}
		}
		double to_int()
		{
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
			if (t.e > e)
			{
				tmp = {t.x * std::pow(10, e - t.e) - x, t.e};
			}
			else if (t.e < e)
			{
				tmp = {t.x - x * std::pow(10, e - t.e), e};
			}
			else
			{
				tmp = {t.x - x, e};
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
			if ((tmp.e == ttmp.e) && (tmp.x == ttmp.x))
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
			if ((tmp.e != ttmp.e) || (tmp.x != ttmp.x))
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
			*this = t - tmp;
			return t - tmp;
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
			*this = t / tmp;
			return t / tmp;
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
	};
	lBI int_to_lBI(double a)
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
	lBI pow(lBI a, lBI b)
	{
		lBI tmpb = reci(b);
		if ((a < lBI({0, 0})) && (((std::abs((fmod(tmpb.x, 2 / std::pow(10, tmpb.e)))) * std::pow(10, tmpb.e)) <= 1e-8) || ((std::abs(std::abs((fmod(tmpb.x, 2 / std::pow(10, tmpb.e))) - 2 / std::pow(10, tmpb.e))) * std::pow(10, tmpb.e)) <= 1e-8)))
		{
			throw std::invalid_argument("Base number is invalid");
		}
		lBI tmp = {0, 0};
		tmp.e = (int_to_lBI(a.e) * b).to_int();
		tmp.x = std::pow(a.x, b.to_int());
		return tmp.format();
	}
	lBI sqrtx(lBI a, lBI b = {2, 0})
	{
		if ((a < lBI({0, 0})) && (((std::abs((fmod(b.x, 2 / std::pow(10, b.e)))) * std::pow(10, b.e)) <= 1e-8) || ((std::abs(std::abs((fmod(b.x, 2 / std::pow(10, b.e))) - 2 / std::pow(10, b.e))) * std::pow(10, b.e)) <= 1e-8)))
		{
			throw std::invalid_argument("Radicand number is invalid");
		}
		return pow(a, lBI({1, 0}) / b);
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
	std::istream& operator>>(std::istream& is, lBI& p) 
	{
	    is >> p.x >> p.e;
	    return is; 
	}
	std::ostream& operator<<(std::ostream& os, const lBI& p) 
	{
	    os << p.x << "e" << p.e;
	    return os; 
	}
}
#endif
