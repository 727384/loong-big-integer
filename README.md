# loong-big-integer
（部分灵感来自于zlyxj的[breakinfinity.h](https://github.com/zlyxj/breakinfinity.h)）

一系列大整数库/头文件的结合。

**部分代码使用AI辅助完成。**

# `lbi.h`
这是一个大整数运算头文件，使用 C++ 编写，能表示不超过 $10^{2^{1024}}$ 的整数，并支持各种运算。

使用`loong::lBI`创建大整数变量。头文件下的所有*函数*均在`loong`命名空间内。

支持的运算包括：基本四则运算、`pow`、n次方根、任意底的对数，比较运算也适用。

`std::cin`与`std::cout`适用，也可用`print()`成员函数输出。

# `lbi.py`

这是一个大整数运算库，使用 Python 编写。

使用`lBI`创建大整数变量。

`print()`适用。

更新记录（`lbi.h`）
---
2026.6.30 UPD：新增`std::hash<loong::lBI>`。

2026.6.26 UPD：新增以下数学函数：
- `loong::frexp()`；
- `loong::ldexp()`；
- `loong::cos()`；
- `loong::sin()`；
- `loong::tan()`；
- `loong::cosh()`；
- `loong::sinh()`；
- `loong::tanh()`；
- `loong::acos()`；
- `loong::asin()`。


2026.6.16 UPD：再次重构代码并新增`loong::str_to_lBI()`函数，输入格式也因此改动。现在也可以从`std::string`构造了。

2026.5.30 UPD：重构代码并新增`loong::hypot()`、`loong::log()`、`loong::exp()`函数及`lBI_E`、`lBI_PI`常量。真正移除了报错（`loong::lBI_mod_no_error`也因此删除）。

2026.3.15 UPD：修复了一些bug。

2026.2.21 UPD：修复了两个bug。

2026.2.16 UPD：对输出及转字符串函数做较小改动。

2026.2.11 UPD：将函数`loong::运算()`更改为`loong::lBI_运算()`。修复了一个bug。

2026.2.10 UPD：除模运算外，移除了所有函数的报错。对对数运算、幂运算和n次方根运算进行重构。修复了一个bug。

2026.2.3 UPD：移除了除法和`loong::lBI_to_int()`函数的报错。重构除法和`loong::lBI_to_int()`函数。添加了`loong::log10_no_error()`和`loong::logx_no_error()`函数。新增`lBI_Nev_True_Infinity`。

2026.1.30 UPD：重构`to_str()`成员函数及`loong::lBI_to_str()`函数，原函数仍保留（加`_old`后缀）。把`*_Infinity`改为了`lBI_*_Infinity`。新增`lBI_NAN`。

2026.1.26 UPD：移除了对`__int128`的支持。

2026.1.17 UPD：增加了`loong::pow_no_error`、`loong::lBI_to_int_no_error`函数。对输出格式进行了小改动。

2026.1.14 UPD：对输出及转字符串函数做较大改动。为修复一个bug，将运算符做了较大改动。

2026.1.8 UPD：现在`loong::lBI`可以直接转成`double`和`std::string`类型了。

2025.12.28 UPD：新增`loong::floor`和`loong::ceil`函数。

2025.12.27 UPD：现在也支持模运算了。

2025.12.20 UPD：现在也支持一元运算符`+`、`-`和`~`了。

2025.12.19 UPD：新增`loong::isnan`函数和两种输出格式。

2025.12.14 UPD：新增一种输出格式。新增`loong::print_lBI`函数，用于输出数字。

2025.12.7 UPD：新增构造函数，现在可以直接将整数或浮点数赋值给`loong::lBI`了。

2025.12.2 UPD：现在也支持`++`和`--`运算符了。

2025.11.29 UPD：现在四则运算也支持函数了。

2025.10.24 UPD：初次上传代码。

更新记录（`lbi.py`）
---
2026.3.15 UPD：初次上传代码。
