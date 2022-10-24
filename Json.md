# json

json对象：值和类型
json类型： null, bool,int,double,string,array,object(Json),可在官网查看
json值  ： bool,int,double,string,array,object(Json)

成员函数：
1.  默认构造函数
2.  根据类型构造函数：bool,int,double,string,char*,Type,Json
3.  转换函数：将Json转换为其他类型，operator Type();
4.  重载[]运算符:对于array，根据index。对于object，根据key值。
5.  重载 = ，==，！=运算符
6.  内存释放函数：因为string,array,object是指针复制的方式，所以要考虑内存泄漏问题，释放内存
7.  将Json转换成字符串输出
8.  增加判断是否为对应类型函数
9.  显式转换函数
10.  判断数组是否有该索引、key值
11.  删除数组对应的索引、key值
12.  解析函数parse

# parser

解析函数，实现对Json的解析

parser对象：字符串和索引

成员函数：
1. 默认构造函数
2. 赋值函数load
3. 解析函数:忽略空白字符函数，解析对应类型函数

get_next_token();获取当前位置字符，并且跳到下一个字符

parse_Type()函数

通过parse()函数对字符进行分析，判断第一个字符是什么，从而调用相应类型的解析函数



