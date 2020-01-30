#include <stdio.h>
#include <stdlib.h>

/* Rotate the array clockwise
 * by given number of elements r
 * If r < 0 -> rotation happens anti-clockwise
 */

void rotateClockwise(int *array, int n, int r) {
	int *ptr, i, tmp;

	printf("Starting array...\n");
	for (i = 0; i < n; i++) printf("%d ", array[i]);

	/* Reverse the array */
	ptr = &array[0];
	for (i = 0; i < n/2; i++) {
		tmp = ptr[i];
		ptr[i] = ptr[n - i - 1];
		ptr[n - i - 1] = tmp;
	}

	/* Reverse first r elements */
	ptr = &array[0];
	for (i = 0; i < r/2; i++) {
		tmp = ptr[i];
		ptr[i] = ptr[r - i - 1];
		ptr[r - i - 1] = tmp;
	}

	/* Reverse last (n-r) elementsa */
	ptr = &array[r];
	r = n - r;
	for (i = 0; i < r/2; i++) {
		tmp = ptr[i];
		ptr[i] = ptr[r - i - 1];
		ptr[r - i - 1] = tmp;
	}

	printf("\n\nAfter rotation by %d...\n", r);
	for (i = 0; i < n; i++) printf("%d ", array[i]);
	printf("\n");
}

void rotateAntiClockwise(int *array, int n, int r) {
	int *ptr, i, tmp;

	printf("Starting array...\n");
	for (i = 0; i < n; i++) printf("%d ", array[i]);

	/* Reverse the array */
	for (i = 0; i < n/2; i++) {
		tmp = array[i];
		array[i] = array[n - i - 1];
		array[n - i - 1] = tmp;
	}

	for (i = 0; i < (n - r)/2; i++) {
		tmp = array[i];
		array[i] = array[n - r - i - 1];
		array[n - r - i - 1] = tmp;
	}

	ptr = &array[n - r];
	for (i = 0; i < r/2; i++) {
		tmp = ptr[i];
		ptr[i] = ptr[r - i - 1];
		ptr[r - i - 1] = tmp;
	}

	printf("\n\nAfter rotation by %d...\n", r);
	for (i = 0; i < n; i++) printf("%d ", array[i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	int n, r;
	int i;

	if (argc != 3) {
		printf("Usage: %s <size of array> <rotateby>\n", argv[0]);
		exit(1);
	}

	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &r);
	
	int *array = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) array[i] = i + 1;

	if (r >= 0) {
		rotateClockwise(array, n, r);
	} else {
		rotateAntiClockwise(array, n, r*-1);
	}

	return 0;
}
