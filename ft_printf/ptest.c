#include <stdio.h>

int main(void)
{
	char s[10] = "";
	
	printf("ddddddddddddddddddddddddddddddd\n");
	/*
	//flag
	printf("0s :%0s[e]\n", s);
	printf("0.s :%0.s[e]\n", s);
	printf(".0s :%.0s[e]\n", s);
	printf("0.0s :%0.0s[e]\n", s);

	printf("*s :%*s[e]\n", s);
	printf("*.s :%*.s[e]\n", s);
	printf(".*s :%.*s[e]\n", s);
	printf("*.*s :%*.*s[e]\n", s);
	
	printf("-s :%-s[e]\n", s);
	printf("-.s :%-.s[e]\n", s);
	printf(".-s :%.-s[e]\n", s);
	printf("-.-s :%-.-s[e]\n", s);

	printf("-*s :%-*s[e]\n", s);
	printf("-*.s :%-*.s[e]\n", s);
	printf(".-*s :%.-*s[e]\n", s);
	printf("-*.-*s :%-*.-*s[e]\n", s);

	printf("-0s :%-0s[e]\n", s);
	printf("-0.s :%-0.s[e]\n", s);
	printf(".-0s :%.-0s[e]\n", s);
	printf("-0.-0s :%-0.-0s[e]\n", s);
	
	printf("*0s :%*0s[e]\n", s);
	printf("*0.s :%*0.s[e]\n", s);
	printf(".*0s :%.*0s[e]\n", s);
	printf("*0.*0s :%*0.*0s[e]\n", s);
	*/
	
	printf(".5s :%.5s", s);
	printf("[e]\n");
	printf(".6s :%.6s", s);
	printf("[e]\n");

	return 0;
}
