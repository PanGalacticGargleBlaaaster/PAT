#include <stdio.h>
void spell(char n)
{
    switch (n)
        {
            case '0':
                printf("zero");
                break;
            case '1':
                printf("one");
                break;
            case '2':
                printf("two");
                break;
            case '3':
                printf("three");
                break;
            case '4':
                printf("four");
                break;
            case '5':
                printf("five");
                break;
            case '6':
                printf("six");
                break;
            case '7':
                printf("seven");
                break;
            case '8':
                printf("eight");
                break;
            case '9':
                printf("nine");
                break;
        }
}
int main()
{
    char Num[101] = "0", s[101] ="0";
    int i, n = 0;
    scanf("%s", &Num);
    for(i = 0; Num[i]!='\0'; i++){
        n += Num[i] - '0';
    }
    sprintf(s, "%d", n);
    
    spell(s[0]);
    for(i = 1; s[i]!='\0'; i++) {
        printf(" ");
        spell(s[i]);
    }
    return 0;
}
