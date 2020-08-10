/*
 * Escreva uma função int comparaString(char str1[], char str2[]) que compara duas strings, retornando 1 quando são iguais, e 0 caso sejam diferentes.
 * Porém, esta função deve ignorar a diferença entre maiúsculas e minúsculas, e interpretar o caracter ‘?’ como um coringa, ou seja, como igual a todos os outros caracteres.
 * Por exemplo, as strings “EstruTuras” e “e?tRutu?aS” são iguais de acordo com a função.
 * Não é permitido usar laços, nem funções da string.h, nem sizeof, nem alocar novos vetores.
 * Não altere o protótipo da função, isto é, não envie outros parâmetros além das duas strings.
 */

#include <stdio.h>
#include <ctype.h>

int comparaString(char str1[], char str2[]) {
	if (str1[0] == '\0' ^ str2[0] == '\0' ||
		((tolower(str1[0]) != tolower(str2[0])) && (str1[0] != '?' && str2[0] != '?')))
		return 0;
	else {
		if (str1[0] == '\0' && str2[0] == '\0')
			return 1;
		else
			return comparaString(&str1[1], &str2[1]);
	}
}

int main() {
	char str1[] = "EstruTuras";
	char str2[] = "e?tRutu?aS";

	printf("%d\n", comparaString(str1, str2));

	return 0;
}
