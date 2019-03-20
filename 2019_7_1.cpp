#include <cmath>
#include <iostream>
using namespace std;

int isprime(int n)
{
	int ret = 1, tmp = sqrt(n);
	for (int i = 2; i <= tmp; i++){
		if (n%i == 0){
			return 0;
		}
	}
	return ret;
}

int main()
{
	int num;
	scanf("%d", &num);
	//cin >> num;
	if (num < 2){
		printf("No\n");
		for (int i = 2;; i++){
			if (isprime(i) && isprime(i + 6)) {
				printf("%d\n", i);
				return 0;
			}
		}
	}
	if (isprime(num)){
		if (num - 6>1 && isprime(num - 6)){
			printf("Yes\n");
			printf("%d\n", num - 6);
		}
		else if (isprime(num + 6)){
			printf("Yes\n");
			printf("%d\n", num + 6);
		}
		else {
			printf("No\n");
			for (int i = num + 1;; i++){
				if (isprime(i) && (isprime(i + 6) || (i-6>1&&isprime(i - 6)))) {
					printf("%d\n", i);
					return 0;
				}
			}
		}
	}
	else {
		printf("No\n");
		for (int i = num + 1;; i++)
			if (isprime(i) && (isprime(i + 6) || (i - 6 > 1 && isprime(i - 6)))) {
			printf("%d\n", i);
			return 0;
			}
	}
    return 0;
}