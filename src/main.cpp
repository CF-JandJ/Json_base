#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "json_yz/include/json.h"

using namespace yazi::json;


int main() {

	//转换基本类型
	/*yazi::json::Json v1;
	yazi::json::Json v2 = true;
	yazi::json::Json v3 = 123;
	yazi::json::Json v4 = 1.23;
	yazi::json::Json v5 = "hello world";

	bool b = v2;
	int i = v3;
	double f = v4;
	const string& s = v5;*/
	
	//数组形式，转化成字符串
	/*Json arr;
	arr[0] = true;
	arr[1] = 123;
	
	arr.append(1.23);
	arr.append("hello world");

	cout << arr.str() << endl;

	bool b = arr[0];
	int i = arr[1];
	double f = arr[2];
	const string& s = arr[3];*/

	//对象类型API
	/*Json obj;
	obj["bool"] = true;
	obj["int"] = 123;
	obj["double"] = 1.23;
	obj["str"] = "hello world";

	cout << obj.str() << endl;*/

	//array迭代器遍历
	/*Json arr;
	arr[0] = true;
	arr[1] = 123;
	arr[2] = 1.23;
	arr[3] = "hello world";

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << it->str() << endl;
	}*/

	//判断，删除元素
	/*Json arr;
	arr[0] = true;
	arr[1] = 123;
	arr[2] = 1.23;
	arr[3] = "hello world";

	cout << arr.str() << endl;

	cout << arr.has(0) << endl;
	cout << arr.has(4) << endl;

	arr.remove(0);
	cout << arr.str() << endl;

	arr.clear();

	Json obj;
	obj["bool"]   = true;
	obj["int"]    = 123;
	obj["double"] = 1.23;
	obj["string"] = "hello world";

	cout << obj.str() << endl;

	cout << obj.has("bool") << endl;
	cout << obj.has("float") << endl;

	obj.remove("int");
	cout << obj.str() << endl;

	obj.clear();*/

	//parser实例
	/*const string& str = "[\"a\",true,1,false,1.1,2,3]";
	Json v;
	v.parse(str);

	cout << v.str() << endl;

	const string& str1 = "{\"a\":1,\"b\":2,\"c\":3}";
	Json v1;
	v1.parse(str1);

	cout << v1.str() << endl;*/

	//解析实例
	ifstream fin("./src/test.json");
	stringstream ss;
	ss << fin.rdbuf();
	const string& str = ss.str();

	Json v;
	v.parse(str);
	cout << v.str() << endl;

	auto c = v["Model"]["Boundary Conditions"]["Farfield"]["Patches"];

	cout << c.str() << endl;
	return 0;
}