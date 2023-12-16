#include <unistd.h>
#include <stdlib.h> //Выделение памяти
#include <stdio.h> //EOF
#include <iostream> //cout, для несвязанных с основной задачей сообщений

using namespace std;

void get_string(char *strPtr)
{
	int strLen = 2;
	int ch;
	int i = 0;
	strPtr = (char*) calloc(strLen, 1);
	strPtr[1] = '\0';

	while((ch = getchar()) != '\n' && ch != EOF) {
		strPtr[i] = ch;
		++i;

		if (i == strLen) {
			strLen *=2;
			strPtr = (char*) realloc(strPtr, strLen);
		}

		strPtr[i] = '\0';
	}

	for (int j = 0; strPtr[j] != '\0'; j++) //!Тест
		write(1, &strPtr[j], 1);
}

int main()
{
	//int ch;
	//int strLen = 2; //Стартовый размер массива под строку
	char *str = 0; //= (char*) calloc(strLen, 1);
	//char newLine = '\n';
	//int i = 0;
	//str[1] = '\0';
	get_string(str);

	cout << str[0];
/*
	while ((ch = getchar()) != '\n' && ch != EOF) { //! Нужен ли тут EOF? EOF == getchar fail!!! Как тут получить fail?
		str[i] = ch;
		++i;
		
		if (i == strLen) {
			strLen *=2;
			str = (char*) realloc(str, strLen);
		}

		str[i] = '\0';
	}
*/

/*
	write(1, &newLine, 1);

	cout << "Initial string: ";

	for (int j = 0; str[j] != '\0'; j++)
		write(1, &str[j], 1);

	write(1, &newLine, 1);

	for (int j = 0; str[j] != '\0'; j++) {

		if (str[j] == 'a' || str[j] == 'A')
			str[j] = '*';

		if (str[j] >= '0' && str[j] <= '9'){
			str[j] = '#';
		}

	}

	write(1, &newLine, 1);

	cout << "Resutl string: ";

	for (int j = 0; str[j] != '\0'; j++)
		write(1, &str[j], 1);
	
	*/

	free(str);
	return (0);
}
