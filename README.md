# loong-big-integer
（部分灵感来自于zlyxj的[breakinfinity.h](https://github.com/zlyxj/breakinfinity.h)）

这是一个大整数运算头文件，使用 C++ 编写，能表示不超过10^10^308的整数，并支持各种运算。

使用`loong::lBI`创建大整数变量。头文件下的所有功能均要包含`loong::`前缀。（`lBI_Infinity`、`lBI_Nev_Infinity`、`lBI_True_Infinity`、`lBI_NAN`不需要）

支持的运算包括：基本四则运算、`pow`、n次方根、任意底的对数，比较运算也适用。

`std::cin`与`std::cout`适用，也可用`print()`成员函数输出。

**部分代码使用AI辅助完成。**

更新记录
---
2026.1.30 UPD：重构`to_str()`成员函数及`lBI_to_str()`函数，原函数仍保留（加`_old`后缀）。把`*_Infinity`改为了`lBI_*_Infinity`。新增`lBI_NAN`。

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
