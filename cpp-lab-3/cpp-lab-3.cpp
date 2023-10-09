#include <stdio.h>
#include <math.h>

int diff(int count, int n, int* cups, int Masha, int Petya) {
	if (count == n)
		return abs(Masha - Petya);
	else {
		int first_variant = diff(count + 1, n, cups, Masha + cups[count], Petya);
		int second_variant = diff(count + 1, n, cups, Masha, Petya + cups[count]);

		if (first_variant < second_variant)
			return first_variant;
		else
			return second_variant;
	}
}

int main() {
	int n;
	int cups[32];

	printf("Enter n:");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &cups[i]);

	int answer = diff(0, n, cups, 0, 0);
	printf("%d", answer);
}