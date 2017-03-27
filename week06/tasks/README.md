1. Довършете задачата за [`Todo list`](../../week05/practicum/README.md)-a
2. Решете 3 и 4 задача от [ЗЗС-то](https://github.com/stranxter/lecture-notes/blob/master/homeworks/02_oop/05%20copy%20constructurs/copy%20constructors.pdf)
3. Напишете клас, който представя символен низ, но позволява удобна работа с него (String). За улеснение, използвайте следния шаблон:

```c++
class String
{
	public:
		String(const char *str = "");
		String(const String &other);
		String& operator = (const String &other);
		String& operator = (const char *str);
		~String();

		int length() const;

		char& operator [] (unsigned int index);
		char operator [] (unsigned int index) const;

		String operator + (const String &other) const;
		String& operator += (const String &other);

		bool operator < (const String &other) const;
		bool operator > (const String &other) const;
		bool operator <= (const String &other) const;
		bool operator >= (const String &other) const;
		bool operator == (const String &other) const;
		bool operator != (const String &other) const;

};

std::ostream& operator << (std::ostream& out, const String& string);
```
