#ifndef ibi_c
#define ibi_c
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define lBI_E int_to_lBI(M_E)
#define lBI_PI int_to_lBI(M_PI)
#define lBI_Infinity lBI_pow((struct lBI){2, 0}, (struct lBI){1.024, 3})
#define lBI_Nev_Infinity lBI_neg(lBI_pow((struct lBI){2, 0}, (struct lBI){1.024, 3}))
#define lBI_True_Infinity (struct lBI){INFINITY, INFINITY}
#define lBI_Nev_True_Infinity (struct lBI){- INFINITY, - INFINITY}
#define Infinity lBI_pow((struct lBI){2, 0}, (struct lBI){1.024, 3})
#define Nev_Infinity lBI_neg(lBI_pow((struct lBI){2, 0}, (struct lBI){1.024, 3}))
#define True_Infinity (struct lBI){INFINITY, INFINITY}
#define Nev_True_Infinity (struct lBI){- INFINITY, - INFINITY}
#define lBI_NAN (struct lBI){NAN, NAN}
#define max(a, b) ((a > b)? (a): (b))
#define min(a, b) ((a > b)? (b): (a))
#if !(!defined(__STRICT_ANSI__) || defined(_POSIX_C_SOURCE) || defined(_POSIX_SOURCE) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_USE_MATH_DEFINES))
#define M_E	2.7182818284590452354
#define M_PI 3.14159265358979323846
#endif
struct lBI;
struct lBI int_to_lBI(double a);
struct lBI str_to_lBI(char* a);
struct lBI lBI_plus(struct lBI a, struct lBI b);
struct lBI lBI_minus(struct lBI a, struct lBI b);
struct lBI lBI_multi(struct lBI a, struct lBI b);
struct lBI lBI_div(struct lBI a, struct lBI b);
struct lBI lBI_mod(struct lBI a, struct lBI b);
struct lBI lBI_floor(struct lBI a);
struct lBI lBI_ceil(struct lBI a);
struct lBI lBI_round(struct lBI a);
struct lBI lBI_log(struct lBI a);
struct lBI lBI_log10(struct lBI a);
struct lBI lBI_logx(struct lBI a, struct lBI b);
struct lBI lBI_pow(struct lBI a, struct lBI b);
struct lBI lBI_sqrtx(struct lBI a, struct lBI b);
struct lBI lBI_hypot(struct lBI a, struct lBI b);
struct lBI lBI_sqrt(struct lBI a);
struct lBI lBI_exp(struct lBI a);
struct lBI lBI_abs(struct lBI a);
struct lBI lBI_reci(struct lBI a);
struct lBI lBI_neg(struct lBI a);
struct lBI lBI_frexp(struct lBI a, struct lBI* b);
struct lBI lBI_ldexp(struct lBI a, struct lBI b);
struct lBI lBI_cos(struct lBI a);
struct lBI lBI_sin(struct lBI a);
struct lBI lBI_tan(struct lBI a);
struct lBI lBI_cosh(struct lBI a);
struct lBI lBI_sinh(struct lBI a);
struct lBI lBI_tanh(struct lBI a);
struct lBI lBI_acos(struct lBI a);
struct lBI lBI_asin(struct lBI a);
struct lBI lBI_atan(struct lBI a);
struct lBI lBI_atan2(struct lBI a, struct lBI b);
bool lBI_isnan(struct lBI a);
struct lBI lBI_format(struct lBI a);
struct lBI print_lBI(struct lBI a, int b, bool c);
double lBI_to_int(struct lBI a);
void lBI_to_str(struct lBI a, int b, char* c);
struct lBI
{
	double x;
	double e;
};
bool lBI_g(struct lBI a, struct lBI b)
{
	struct lBI tmp = a;
	struct lBI ttmp = b;
	tmp = lBI_format(tmp);
	ttmp = lBI_format(ttmp);
	if (tmp.x <= 0 && ttmp.x > 0)
	{
		return false;
	}
	if (tmp.x < 0 && ttmp.x >= 0)
	{
		return false;
	}
	if (tmp.x > 0 && ttmp.x <= 0)
	{
		return true;
	}
	if (tmp.x >= 0 && ttmp.x < 0)
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
bool lBI_ge(struct lBI a, struct lBI b)
{
	struct lBI tmp = a;
	struct lBI ttmp = b;
	tmp = lBI_format(tmp);
	ttmp = lBI_format(ttmp);
	if (tmp.x <= 0 && ttmp.x > 0)
	{
		return false;
	}
	if (tmp.x < 0 && ttmp.x >= 0)
	{
		return false;
	}
	if (tmp.x > 0 && ttmp.x <= 0)
	{
		return true;
	}
	if (tmp.x >= 0 && ttmp.x < 0)
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
			if (tmp.x >= ttmp.x)
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
			if (tmp.x >= ttmp.x)
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
bool lBI_l(struct lBI a, struct lBI b)
{
	struct lBI tmp = a;
	struct lBI ttmp = b;
	tmp = lBI_format(tmp);
	ttmp = lBI_format(ttmp);
	if (tmp.x <= 0 && ttmp.x > 0)
	{
		return true;
	}
	if (tmp.x < 0 && ttmp.x >= 0)
	{
		return true;
	}
	if (tmp.x > 0 && ttmp.x <= 0)
	{
		return false;
	}
	if (tmp.x >= 0 && ttmp.x < 0)
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
bool lBI_le(struct lBI a, struct lBI b)
{
	struct lBI tmp = a;
	struct lBI ttmp = b;
	tmp = lBI_format(tmp);
	ttmp = lBI_format(ttmp);
	if (tmp.x <= 0 && ttmp.x > 0)
	{
		return true;
	}
	if (tmp.x < 0 && ttmp.x >= 0)
	{
		return true;
	}
	if (tmp.x > 0 && ttmp.x <= 0)
	{
		return false;
	}
	if (tmp.x >= 0 && ttmp.x < 0)
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
bool lBI_e(struct lBI a, struct lBI b)
{
	struct lBI tmp = a;
	struct lBI ttmp = b;
	tmp = lBI_format(tmp);
	ttmp = lBI_format(ttmp);
	if (tmp.e == ttmp.e && tmp.x == ttmp.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool lBI_ne(struct lBI a, struct lBI b)
{
	struct lBI tmp = a;
	struct lBI ttmp = b;
	tmp = lBI_format(tmp);
	ttmp = lBI_format(ttmp);
	if (tmp.e != ttmp.e || tmp.x != ttmp.x)
	{
		return true;
	}
	else
	{
		return false;
	}
}
struct lBI int_to_lBI(double a)
{
	if (isnan(a))
	{
		return (struct lBI){NAN, NAN};
	}
	else if (a == INFINITY)
	{
		return (struct lBI){INFINITY, INFINITY};
	}
	else if (a == - INFINITY)
	{
		return (struct lBI){- INFINITY, - INFINITY};
	}
	else if (a < 0)
	{
		return (struct lBI){a / pow(10, floor(log10(abs(a)))), floor(log10(abs(a)))};
	}
	else if (a == 0)
	{
		return (struct lBI){0, 0};
	}
	else
	{
		return (struct lBI){a / pow(10, floor(log10(a))), floor(log10(a))};
	}
}
struct lBI str_to_lBI(char* a)
{
	int e_count = 0;
	int first_e_pos = 0;
	int second_e_pos = 0;
	struct lBI ans = (struct lBI){0, 0};
	if (strcmp(a, "Infinity") == 0 || strcmp(a, "inf") == 0)
	{
		return (struct lBI){INFINITY, INFINITY};
	}
	if (strcmp(a, "-Infinity") == 0 || strcmp(a, "-inf") == 0)
	{
		return (struct lBI){- INFINITY, - INFINITY};
	}
	if (strcmp(a, "NaN") == 0 || strcmp(a, "nan") == 0)
	{
		return (struct lBI){NAN, NAN};
	}
	if (strlen(a) == 0)
	{
		return ans;
	}
	for (int i = 0; i < strlen(a); i ++)
	{
		if (a[i] == 'e' || a[i] == 'E' || a[i] == ' ')
		{
			if (first_e_pos == 0 && e_count == 0)
			{
				first_e_pos = i;
			}
			else if (second_e_pos == 0)
			{	
				second_e_pos = i;
			}
			e_count ++;
		}
	}
	if (e_count == 0)
	{
		ans = int_to_lBI(strtod(a, NULL));
	}
	else
	{
		if (first_e_pos == 0)
		{
			ans.x = 1;
			if (second_e_pos == 1)
			{
				char buff[1024];
				memcpy(buff, a + 2, strlen(a) - 1);
				ans.e = pow(10, strtod(buff, NULL));
			}
			else
			{
				char buff[1024];
				memcpy(buff, a + 1, strlen(a));
				ans.e = strtod(buff, NULL);
			}
		}
		else
		{
			char buffa[1024], buffb[1024];
			memcpy(buffa, a, first_e_pos);
			buffa[first_e_pos] = '\0';
			memcpy(buffb, a + first_e_pos + 1, strlen(a) - first_e_pos);
			ans.x = strtod(buffa, NULL);
			ans.e = strtod(buffb, NULL);
		}
	}
	return lBI_format(ans);
}
struct lBI lBI_plus(struct lBI a, struct lBI b)
{
		struct lBI tmp = {0, 0};
		if (b.e > a.e)
		{
			tmp = (struct lBI){b.x + a.x * pow(10, a.e - b.e), b.e};
		}
		else if (b.e < a.e)
		{
			tmp = (struct lBI){b.x * pow(10, b.e - a.e) + a.x, a.e};
		}
		else
		{
			tmp = (struct lBI){b.x + a.x, a.e};
		}
		return lBI_format(tmp);
}
struct lBI lBI_minus(struct lBI a, struct lBI b)
{
	struct lBI tmp= {0, 0};
	if (a.e > b.e)
	{
		tmp = (struct lBI){a.x - b.x * pow(10, b.e - a.e), a.e};
	}
	else if (a.e < b.e)
	{
		tmp = (struct lBI){a.x * pow(10, a.e - b.e) - b.x, b.e};
	}
	else
	{
		tmp = (struct lBI){a.x - b.x, a.e};
	}
	return lBI_format(tmp);
}
struct lBI lBI_multi(struct lBI a, struct lBI b)
{
	struct lBI tmp = {0, 0};
	if ((b.e == - INFINITY && a.e == INFINITY) || (b.e == INFINITY && a.e == - INFINITY))
	{
		tmp = (struct lBI){- INFINITY, - INFINITY};
	}
	else
	{
		tmp = (struct lBI){b.x * a.x, b.e + a.e};
	}
	return lBI_format(tmp);
}
struct lBI lBI_div(struct lBI a, struct lBI b)
{
	if (b.x == 0)
	{
		if (a.x > 0)
		{
			return (struct lBI){INFINITY, INFINITY};
		}
		else if (a.x < 0)
		{
			return (struct lBI){- INFINITY, - INFINITY};
		}
		else
		{
			return (struct lBI){NAN, NAN};
		}
	}
	struct lBI tmp = {a.x / b.x, a.e - b.e};
	return lBI_format(tmp);
}
struct lBI lBI_mod(struct lBI a, struct lBI b)
{
	if (isnan(a.x) || isnan(a.e) || isnan(b.x) || isnan(b.e))
	{
		return (struct lBI){NAN, NAN};
	}
	else if (a.x == INFINITY || a.x == - INFINITY)
	{
		return (struct lBI){NAN, NAN};
	}
	else if (lBI_e(b, (struct lBI){0, 0}))
	{
		return (struct lBI){NAN, NAN};
	}
	else if (b.x == INFINITY || b.x == - INFINITY)
	{
		return a;
	}
	else if (lBI_e(a, (struct lBI){0, 0}))
	{
		return (struct lBI){0, 0};
	}
	else if (lBI_l((struct lBI){fabs(a.x), a.e}, b))
	{
		return a;
	}
	else if (lBI_l((struct lBI){fabs(a.x), a.e}, lBI_Infinity) && lBI_l((struct lBI){fabs(b.x), b.e}, lBI_Infinity))
	{
		return int_to_lBI(fmod(lBI_to_int(a), lBI_to_int(b)));
	}
	else
	{ 
     	struct lBI tmp = lBI_div(a, b);
     	if (lBI_ge(tmp, lBI_Infinity))
     	{
     		return (struct lBI){0, 0};
		}
		else
		{
			return lBI_multi((struct lBI){fmod(lBI_to_int(tmp), 1.0)}, b);
		}
	}
}
struct lBI lBI_floor(struct lBI a)
{
	return lBI_minus(a, lBI_mod(a, (struct lBI){1, 0}));
}
struct lBI lBI_ceil(struct lBI a)
{
	if (lBI_ne(lBI_mod(a, (struct lBI){1, 0}), (struct lBI){0, 0}))
	{
		return lBI_plus(lBI_floor(a), (struct lBI){1, 0});
	}
	else
	{
		return a;
	}
}
struct lBI lBI_round(struct lBI a)
{
	if (lBI_ge(lBI_mod(a, (struct lBI){1, 0}), (struct lBI){5, -1}))
	{
		return lBI_plus(lBI_floor(a), (struct lBI){1, 0});
	}
	else
	{
		return lBI_floor(a);
	}
}
struct lBI lBI_log(struct lBI a)
{
	return lBI_logx(a, lBI_E);
}
struct lBI lBI_log10(struct lBI a)
{
	if (isnan(a.x) || isnan(a.e))
	{
		return (struct lBI){NAN, NAN};
	}
	else if (lBI_e(a, (struct lBI){INFINITY, INFINITY}))
	{
		return (struct lBI){INFINITY, INFINITY};
	}
	else if (lBI_e(a, (struct lBI){- INFINITY, - INFINITY}))
	{
		return (struct lBI){NAN, NAN};
	}
	else if (lBI_l(a, (struct lBI){0, 0}))
	{
		return (struct lBI){NAN, NAN};
	}
	else if (lBI_e(a, (struct lBI){0, 0}))
	{
		return (struct lBI){- INFINITY, - INFINITY};
	}
	else
	{
		return lBI_plus(int_to_lBI(log10(a.x)), int_to_lBI(a.e));
	}
}
struct lBI lBI_logx(struct lBI a, struct lBI b)
{
	return lBI_div(lBI_log10(a), lBI_log10(b));
}
struct lBI lBI_pow(struct lBI a, struct lBI b)
{
	struct lBI tmp = (struct lBI){0, 0};
	if (isnan(a.x) || isnan(a.e) || isnan(b.x) || isnan(b.e))
	{
		tmp.x = NAN;
		tmp.e = NAN;
	}
	else if (a.x == 0)
	{
		if (b.x < 0)
		{
			tmp.x = INFINITY;
			tmp.e = INFINITY;
		}
		else
		{
			tmp.x = 0;
			tmp.e = 0;
		}
	}
	else if (a.x == INFINITY || a.e == INFINITY)
	{
		if (b.x > 0)
		{
			tmp.x = INFINITY;
			tmp.e = INFINITY;
		}
		else if (b.x == 0)
		{
			tmp.x = 1;
			tmp.e = 0;
		}
		else
		{
			tmp.x = 0;
			tmp.e = 0;
		}
	}
	else if (a.x == 1)
	{
		if (a.e == 0 && (b.x == INFINITY || b.e == INFINITY))
		{
			tmp.x = 1;
			tmp.e = 0;
		}
		else
		{
			tmp.e = lBI_to_int(lBI_multi(int_to_lBI(a.e), b));
			tmp.x = 1;
		}
	}
	else if (a.x > 1)
	{
		tmp.e = lBI_to_int(lBI_plus(lBI_multi(int_to_lBI(a.e), b), lBI_multi(b, int_to_lBI(log10(a.x)))));
		tmp.x = 1;
	}
	else
	{
		tmp.x = NAN;
		tmp.e = NAN;
	}
	tmp = lBI_format(tmp);
	return tmp;
}
struct lBI lBI_sqrtx(struct lBI a, struct lBI b)
{
	struct lBI tmp = lBI_pow(a, lBI_div((struct lBI){1, 0}, b));
	return tmp;
}
struct lBI lBI_hypot(struct lBI a, struct lBI b)
{
	return lBI_sqrt(lBI_plus(lBI_multi(a, a), lBI_multi(b, b)));
}
struct lBI lBI_sqrt(struct lBI a)
{
	return lBI_sqrtx(a, (struct lBI){2, 0});
}
struct lBI lBI_cbrt(struct lBI a)
{
	if (isnan(a.x) || isnan(a.e))
	{
		return (struct lBI){NAN, NAN};
	}
	else if (a.x >= 0)
	{
		return lBI_pow(a, (struct lBI){3, 0});
	}
	else 
	{
		return lBI_neg(lBI_pow(lBI_neg(a), (struct lBI){3, 0}));
	}
}
struct lBI lBI_exp(struct lBI a)
{
	return lBI_pow(lBI_E, a);
}
struct lBI lBI_abs(struct lBI a)
{
	return (struct lBI){fabs(a.x), a.e};
}
struct lBI lBI_reci(struct lBI a)
{
	return lBI_div((struct lBI){1, 0}, a);
}
struct lBI lBI_neg(struct lBI a)
{
	struct lBI tmp = a;
	tmp = lBI_minus((struct lBI){0, 0}, tmp);
	return lBI_format(tmp);
}
struct lBI lBI_frexp(struct lBI a, struct lBI* b)
{
	if (isnan(a.x) || isnan(a.e))
	{
		b -> x = NAN;
		b -> e = NAN;
		return (struct lBI){NAN, NAN};
	}
	else if (a.x == INFINITY || a.e == INFINITY)
	{
		b -> x = INFINITY;
		b -> e = INFINITY;
		return (struct lBI){INFINITY, INFINITY};
	}
	else if (a.x == - INFINITY || a.e == - INFINITY)
	{
		b -> x = - INFINITY;
		b -> e = - INFINITY;
		return (struct lBI){- INFINITY, - INFINITY};
	}
	else if (lBI_e(a, (struct lBI){0, 0}))
	{
		b -> x = 0;
		b -> e = 0;
		return (struct lBI){0, 0}; 
	}
	else if (lBI_l(a, (struct lBI){0, 0}))
	{
		struct lBI tmp = lBI_logx(lBI_neg(a), int_to_lBI(2));
		if (lBI_e(lBI_ceil(tmp), tmp))
		{
			if (lBI_l(tmp, (struct lBI){0, 0}))
			{
				*b = lBI_plus(tmp, (struct lBI){1, 0});
			}
			else
			{
				*b = lBI_minus(tmp, (struct lBI){1, 0});
			}
			return (struct lBI){-5, -1};
		}
		else
		{
			*b = lBI_ceil(tmp);
			return lBI_div(lBI_neg(a), lBI_pow((struct lBI){2, 0}, lBI_ceil(tmp)));
		}
	}
	else
	{
		struct lBI tmp = lBI_logx(a, int_to_lBI(2));
		if (lBI_e(lBI_ceil(tmp), tmp))
		{
			if (lBI_l(tmp, (struct lBI){0, 0}))
			{
				*b = lBI_plus(tmp, (struct lBI){1, 0});
			}
			else
			{
				*b = lBI_minus(tmp, (struct lBI){1, 0});
			}
			return (struct lBI){5, -1};
		}
		else
		{
			*b = lBI_ceil(tmp);
			return lBI_div(a, lBI_pow((struct lBI){2, 0}, lBI_ceil(tmp)));
		}
	}
}
struct lBI lBI_ldexp(struct lBI a, struct lBI b)
{
	return lBI_multi(a, lBI_pow((struct lBI){2, 0}, b));
}
struct lBI lBI_cos(struct lBI a)
{
	return int_to_lBI(cos(lBI_to_int(lBI_mod(a, lBI_multi((struct lBI){2, 0}, lBI_PI)))));
}
struct lBI lBI_sin(struct lBI a)
{
	return int_to_lBI(sin(lBI_to_int(lBI_mod(a, lBI_multi((struct lBI){2, 0}, lBI_PI)))));
}
struct lBI lBI_tan(struct lBI a)
{
	return lBI_div(lBI_sin(a), lBI_cos(a));
}
struct lBI lBI_cosh(struct lBI a)
{
	return lBI_div(lBI_plus(lBI_pow(lBI_E, a), lBI_pow(lBI_E, lBI_neg(a))), (struct lBI){2, 0});
}
struct lBI lBI_sinh(struct lBI a)
{
	return lBI_div(lBI_minus(lBI_pow(lBI_E, a), lBI_pow(lBI_E, lBI_neg(a))), (struct lBI){2, 0});
}
struct lBI lBI_tanh(struct lBI a)
{
	return lBI_div(lBI_sinh(a), lBI_cosh(a));
}
struct lBI lBI_acos(struct lBI a)
{
	if (lBI_le((struct lBI){-1, 0}, a) && lBI_le(a, (struct lBI){1, 0}))
	{
		return int_to_lBI(acos(lBI_to_int(a)));
	}
	else
	{
		return (struct lBI){NAN, NAN};
	}
}
struct lBI lBI_asin(struct lBI a)
{
	if (lBI_le((struct lBI){-1, 0}, a) && lBI_le(a, (struct lBI){1, 0}))
	{
		return int_to_lBI(asin(lBI_to_int(a)));
	}
	else
	{
		return (struct lBI){NAN, NAN};
	}
}
struct lBI lBI_atan(struct lBI a)
{
	return int_to_lBI(atan(lBI_to_int(a)));
}
struct lBI lBI_atan2(struct lBI a, struct lBI b)
{
	return int_to_lBI(atan2(lBI_to_int(a), lBI_to_int(b)));
}
bool lBI_isnan(struct lBI a)
{
	if (isnan(a.x) || isnan(a.e))
	{
		return true;
	}
	else
	{
		return false;
	}
}
struct lBI lBI_format(struct lBI a)
{
	if (isnan(a.x) || isnan(a.e))
	{
		return (struct lBI){NAN, NAN};
	}
	else if (a.x == INFINITY || a.e == INFINITY)
	{
		return (struct lBI){INFINITY, INFINITY};
	}
	else if (a.x == - INFINITY)
	{
		return (struct lBI){- INFINITY, - INFINITY};
	}
	else
	{
		if (floor(a.e) != a.e)
		{
			a.x *= pow(10, a.e - floor(a.e));
			a.e = floor(a.e);
		}
		if (a.x == 0)
		{
			a.x = 0;
			a.e = 0;
		}
		else if (a.x < 1)
		{
			a.e += floor(log10(fabs(a.x)));
			a.x = a.x / pow(10, floor(log10(fabs(a.x))));
		}
		else if (a.x >= 10)
		{
			a.e += floor(log10(fabs(a.x)));
			a.x = a.x / pow(10, floor(log10(fabs(a.x))));
		}
		else
		{
			a.x = a.x;
			a.e = a.e;
		}
		return a;
	}
}
struct lBI print_lBI(struct lBI a, int b, bool c)
{
	if (b == 0)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else
		{
			printf("%lfe%lg", a.x, a.e);	
		}
	}
	else if (b == 1)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else
		{
			printf("%lf %lg", a.x, a.e);
		}
	}
	else if (b == 2)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else
		{
			printf("%lfx10^%lg", a.x, a.e);
		}
	}
	else if (b == 3)
	{				
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else
		{
			printf("%lf*10^%lg", a.x, a.e);
		}
	}
	else if (b == 4)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else if (a.x < 0)
		{
			printf("-e%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
		}
		else if (a.x == 0)
		{
			printf("e(-inf)");
		}
		else
		{
			printf("e%lg", lBI_to_int(lBI_log10(a)));
		}
	}
	else if (b == 5)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else if (a.x < 0)
		{
			printf("-e%lg", a.e);
		}
		else
		{
			printf("e%lg", a.e);
		}
	}
	else if (b == 6)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else if (a.x == 0)
		{
			printf("e(-e(inf))");
		}
		else if (a.x < 0)
		{
			if (lBI_g(lBI_log10(lBI_neg(a)), (struct lBI){0, 0}))
			{
				printf("-ee%lg", lBI_to_int(lBI_log10(lBI_log10(lBI_neg(a)))));
			}
			else if (lBI_e(lBI_log10(lBI_neg(a)), (struct lBI){0, 0}))
			{
				printf("-ee(-inf)");
			}
			else
			{
				printf("-e(-e%lg)", lBI_to_int(lBI_log10(lBI_neg(lBI_log10(lBI_neg(a))))));
			}
		}
		else
		{
			if (lBI_g(lBI_log10(a), (struct lBI){0, 0}))
			{
				printf("ee%lg", lBI_to_int(lBI_log10(lBI_log10(a))));
			}
			else if (lBI_e(lBI_log10(a), (struct lBI){0, 0}))
			{
				printf("ee(-inf)");
			}
			else
			{
				printf("e(-e%lg)", lBI_to_int(lBI_log10(lBI_neg(lBI_log10(a)))));
			}
		}
	}
	else if (b == 7)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else if (a.x == 0)
		{
			printf("10^(-10^(inf))");
		}
		else if (a.x < 0)
		{
			if (lBI_g(lBI_log10(lBI_neg(a)), (struct lBI){0, 0}))
			{
				printf("-10^^%lg", lBI_to_int(lBI_log10(lBI_log10(lBI_neg(a)))));
			}
			else if (lBI_e(lBI_log10(lBI_neg(a)), (struct lBI){0, 0}))
			{
				printf("-10^^(-inf)");
			}
			else
			{
				printf("-10^(-10^%lg)", lBI_to_int(lBI_log10(lBI_neg(lBI_log10(lBI_neg(a))))));
			}
		}
		else
		{
			if (lBI_g(lBI_log10(a), (struct lBI){0, 0}))
			{
				printf("10^^%lg", lBI_to_int(lBI_log10(lBI_log10(a))));
			}
			else if (lBI_e(lBI_log10(a), (struct lBI){0, 0}))
			{
				printf("10^^(-inf)");
			}
			else
			{
				printf("10^(-10^%lg)", lBI_to_int(lBI_log10(lBI_neg(lBI_log10(a)))));
			}
		}
	}
	else if (b == 8)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else
		{
			printf("%lg", lBI_to_int(a));
		}
	}
	else if (b == 9)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else if (fabs(a.e) < 6)
		{
			printf("%lg", lBI_to_int(a));
		}
		else if (fabs(a.e) < 1e6)
		{
			printf("%lfe%lg", a.x, a.e);
		}
		else 
		{
			if (a.x < 0)
			{
				printf("-e%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
			}
			else
			{	
				printf("e%lg", lBI_to_int(lBI_log10(a)));
			}
		}
	}			
	else if (b == 10)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else if (fabs(a.e) < 6)
		{
			printf("%lg", lBI_to_int(a));
		}
		else if (fabs(a.e) < 1e6)
		{
			printf("%lf*10^%lg", a.x, a.e);
		}
		else 
		{
			if (a.x < 0)
			{
				printf("-10^%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
			}
			else
			{
				printf("10^%lg", lBI_to_int(lBI_log10(a)));
			}
		}
	}			
	else if (b == 11)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else if (fabs(a.e) < 6)
		{
			printf("%lg", lBI_to_int(a));
		}
		else if (fabs(a.e) < 1e6)
		{
			printf("%lfx10^%lg", a.x, a.e);
		}
		else 
		{
			if (a.x < 0)
			{
				printf("-10^%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
			}
			else
			{
				printf("10^%lg", lBI_to_int(lBI_log10(a)));
			}
		}
	}
	else
	{
		if (isnan(a.x) || isnan(a.e))
		{
			printf("nan");
		}				
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			printf("inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			printf("-inf");
		}
		else if (fabs(a.e) < 6)
		{
			printf("%lg", lBI_to_int(a));
		}
		else if (fabs(a.e) < 1e6)
		{
			printf("%lfe%lg", a.x, a.e);
		}
		else 
		{
			if (a.x < 0)
			{
				printf("-e%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
			}
			else
			{	
				printf("e%lg", lBI_to_int(lBI_log10(a)));
			}
		}
	}		
	if (c)
	{
		printf("\n");
	}
	return a;
}
double lBI_to_int(struct lBI a)
{
	if (a.x == INFINITY)
	{
		return INFINITY;
	}
	else if (a.x == - INFINITY)
	{
		return - INFINITY;
	}
	else if (isnan(a.x) || isnan(a.e))
	{
		return NAN;
	}
	else
	{
		return a.x * pow(10, a.e);
	}
}
struct lBI* input_lBI(struct lBI* a)
{
	char buff[1024];
	fgets(buff, 1024, stdin);
	buff[strlen(buff) - 1] = '\0';
	*a = str_to_lBI(buff);
	return a;
}
void lBI_to_str(struct lBI a, int b, char* c)
{
    char buff[1024];
	if (b == 0)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else
		{
			sprintf(buff, "%lfe%lg", a.x, a.e);	
		}
	}
	else if (b == 1)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else
		{
			sprintf(buff, "%lf %lg", a.x, a.e);
		}
	}
	else if (b == 2)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else
		{
			sprintf(buff, "%lfx10^%lg", a.x, a.e);
		}
	}
	else if (b == 3)
	{				
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else
		{
			sprintf(buff, "%lf*10^%lg", a.x, a.e);
		}
	}
	else if (b == 4)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else if (a.x < 0)
		{
			sprintf(buff, "-e%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
		}
		else if (a.x == 0)
		{
			sprintf(buff, "e(-inf)");
		}
		else
		{
			sprintf(buff, "e%lg", lBI_to_int(lBI_log10(a)));
		}
	}
	else if (b == 5)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else if (a.x < 0)
		{
			sprintf(buff, "-e%lg", a.e);
		}
		else
		{
			sprintf(buff, "e%lg", a.e);
		}
	}
	else if (b == 6)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else if (a.x == 0)
		{
			sprintf(buff, "e(-e(inf))");
		}
		else if (a.x < 0)
		{
			if (lBI_g(lBI_log10(lBI_neg(a)), (struct lBI){0, 0}))
			{
				sprintf(buff, "-ee%lg", lBI_to_int(lBI_log10(lBI_log10(lBI_neg(a)))));
			}
			else if (lBI_e(lBI_log10(lBI_neg(a)), (struct lBI){0, 0}))
			{
				sprintf(buff, "-ee(-inf)");
			}
			else
			{
				sprintf(buff, "-e(-e%lg)", lBI_to_int(lBI_log10(lBI_neg(lBI_log10(lBI_neg(a))))));
			}
		}
		else
		{
			if (lBI_g(lBI_log10(a), (struct lBI){0, 0}))
			{
				sprintf(buff, "ee%lg", lBI_to_int(lBI_log10(lBI_log10(a))));
			}
			else if (lBI_e(lBI_log10(a), (struct lBI){0, 0}))
			{
				sprintf(buff, "ee(-inf)");
			}
			else
			{
				sprintf(buff, "e(-e%lg)", lBI_to_int(lBI_log10(lBI_neg(lBI_log10(a)))));
			}
		}
	}
	else if (b == 7)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else if (a.x == 0)
		{
			sprintf(buff, "10^(-10^(inf))");
		}
		else if (a.x < 0)
		{
			if (lBI_g(lBI_log10(lBI_neg(a)), (struct lBI){0, 0}))
			{
				sprintf(buff, "-10^^%lg", lBI_to_int(lBI_log10(lBI_log10(lBI_neg(a)))));
			}
			else if (lBI_e(lBI_log10(lBI_neg(a)), (struct lBI){0, 0}))
			{
				sprintf(buff, "-10^^(-inf)");
			}
			else
			{
				sprintf(buff, "-10^(-10^%lg)", lBI_to_int(lBI_log10(lBI_neg(lBI_log10(lBI_neg(a))))));
			}
		}
		else
		{
			if (lBI_g(lBI_log10(a), (struct lBI){0, 0}))
			{
				sprintf(buff, "10^^%lg", lBI_to_int(lBI_log10(lBI_log10(a))));
			}
			else if (lBI_e(lBI_log10(a), (struct lBI){0, 0}))
			{
				sprintf(buff, "10^^(-inf)");
			}
			else
			{
				sprintf(buff, "10^(-10^%lg)", lBI_to_int(lBI_log10(lBI_neg(lBI_log10(a)))));
			}
		}
	}
	else if (b == 8)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else
		{
			sprintf(buff, "%lg", lBI_to_int(a));
		}
	}
	else if (b == 9)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else if (fabs(a.e) < 6)
		{
			sprintf(buff, "%lg", lBI_to_int(a));
		}
		else if (fabs(a.e) < 1e6)
		{
			sprintf(buff, "%lfe%lg", a.x, a.e);
		}
		else 
		{
			if (a.x < 0)
			{
				sprintf(buff, "-e%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
			}
			else
			{
				sprintf(buff, "e%lg", lBI_to_int(lBI_log10(a)));
			}
		}
	}			
	else if (b == 10)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else if (fabs(a.e) < 6)
		{
			sprintf(buff, "%lg", lBI_to_int(a));
		}
		else if (fabs(a.e) < 1e6)
		{
			sprintf(buff, "%lf*10^%lg", a.x, a.e);
		}
		else 
		{
			if (a.x < 0)
			{
				sprintf(buff, "-10^^%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
			}
			else
			{
				sprintf(buff, "10^^%lg", lBI_to_int(lBI_log10(a)));
			}
		}
	}			
	else if (b == 11)
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else if (fabs(a.e) < 6)
		{
			sprintf(buff, "%lg", lBI_to_int(a));
		}
		else if (fabs(a.e) < 1e6)
		{
			sprintf(buff, "%lfx10^%lg", a.x, a.e);
		}
		else 
		{
			if (a.x < 0)
			{
				sprintf(buff, "-10^^%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
			}
			else
			{
				sprintf(buff, "10^^%lg", lBI_to_int(lBI_log10(a)));
			}
		}
	}
	else
	{
		if (isnan(a.x) || isnan(a.e))
		{
			sprintf(buff, "nan");
		}			
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			sprintf(buff, "inf");
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			sprintf(buff, "-inf");
		}
		else if (fabs(a.e) < 6)
		{
			sprintf(buff, "%lg", lBI_to_int(a));
		}
		else if (fabs(a.e) < 1e6)
		{
			sprintf(buff, "%lfe%lg", a.x, a.e);
		}
		else 
		{
			if (a.x < 0)
			{
				sprintf(buff, "-e%lg", lBI_to_int(lBI_log10(lBI_neg(a))));
			}
			else
			{
				sprintf(buff, "e%lg", lBI_to_int(lBI_log10(a)));
			}
		}
	}	
	strcpy(c, buff);
}
#endif
