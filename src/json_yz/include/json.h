#pragma once

#include <string>
#include <vector>
#include <map>
using namespace std;

namespace yazi {

namespace json {

class Json {
public:
	enum class Type {
	    json_null = 0,
	    json_bool,
	    json_int,
	    json_double,
	    json_string,
	    json_array,
	    json_object
	};

	Json();
	Json(bool value);
	Json(int value);
	Json(double value);
	Json(const char* value);
	Json(const string& value);
	Json(Type type);
	Json(const Json& other);

	operator bool();
	operator int();
	operator double();
	operator string();
	
	Json& operator[](int index);
	void append(const Json& other);

	Json& operator[](const char* key);
	Json& operator[](const string& key);

	void operator = (const Json& other);
	bool operator == (const Json& other);
	bool operator != (const Json& other);

	//内存释放
	void clear();

	string str()const;

	typedef std::vector<Json>::iterator iterator;
	iterator begin() {
		return m_value.m_array->begin();
	}
	iterator end() {
		return m_value.m_array->end();
	}

	//是否为该类型
	bool isNull()   const { return m_type == Type::json_null; }
	bool isBool()   const { return m_type == Type::json_bool; }
	bool isInt ()   const { return m_type == Type::json_int; }
	bool isDouble() const { return m_type == Type::json_double; }
	bool isString() const { return m_type == Type::json_string; }
	bool isArray()  const { return m_type == Type::json_array; }
	bool isObject() const { return m_type == Type::json_object; }

	//显示转换
	bool asBool()const;
	int asInt()const;
	double asDouble()const;
	string asString()const;

	//判断数组中是否有该索引
	bool has(int index);
	//判断对象中是否有key
	bool has(const char* key);
	bool has(const string& key);

	//删除索引的元素
	void remove(int index);
	//删除key的元素
	void remove(const char* key);
	void remove(const string& key);

	void parse(const string& str);
private:
	union Value
	{
		bool               m_bool;
		int                m_int;
		double             m_double;
		string*            m_string;
		vector<Json>*      m_array;
		map<string, Json>* m_object;
	};

	Type  m_type;
	Value m_value;

};

}
}