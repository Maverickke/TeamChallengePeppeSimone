#include <stdio.h>
#include <string.h>
//-realizzare un programma che prende un argomento e lo stampa al contrario(dall’ultima lettera alla prima)[1 punto]

int main(int argc, char **argv)
{
	void reverse(char *x, int begin, int end);
	char input_char[10];

	printf("Insert text");
	fgets(input_char, 10, stdin);

	reverse(input_char, 0, strlen(input_char) - 1);

	printf("%s\n", input_char);

	return 0;
}

void reverse(char *x, int begin, int end) 
{
	char c;

	if (begin >= end) {
		return;
	}
	c = *(x + begin);
	*(x + begin) = *(x + end);
	*(x + end) = c;

	reverse(x, ++begin, --end);
}