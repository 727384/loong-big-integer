# loong-big-integer
（部分灵感来自于zlyxj的[breakinfinity.h](https://github.com/zlyxj/breakinfinity.h)）

使用`loong::lBI`创建大整数变量，头文件下的所有运算均要包含`loong::`前缀。

这是一个大整数运算头文件，使用 C++ 编写，能表示不超过10^10^308的整数，并支持各种运算。
支持的运算包括：基本四则运算、`pow`、n次方根、任意底的对数。
比较运算适用。
`std::cin`与`std::cout`适用。

2025.11.29更新：现在四则运算也支持函数了。另外，`loong::int_to_lBI`函数已改名为`loong::to_lBI`。

**部分代码使用AI辅助完成。**（包括报错，`std::cin`与`std::cout`、与模相关的运算）
