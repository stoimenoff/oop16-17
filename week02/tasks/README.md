Използвайте следната структура, описваща задача в списък от задачи.
```c++
	const int MAX_TITLE_SIZE = 24;
	const int MAX_DESCRIPTION_SIZE = 300;

	struct Task
	{
		char title[MAX_TITLE_SIZE];
		double priority;
		char description[MAX_DESCRIPTION_SIZE];
	};

```

1. Направете функция, която прочита от стандартния вход една задача.

2. Направете функция, която прочита от стандартния вход произволен брой задачи (първо се прочита броя на задачите, а след това и самите те), записва ги в масив в динамичната памет и връща указател към него.

3. Направете функция, която извежда на стандартния изход една задача.
4. Направете функция, която извежда на стандартния изход масив от задачи. Преди да изведете задачите, изведете и техния брой.

#### 5. Адаптирайте горните фунцкии, така че да работят с текстови файлове. Нека приемат като параметър и потока, в който записват или от който четат.
