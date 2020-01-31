#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT (0x7fffffff)

typedef struct node_ {
	int freq;
	char c;
	struct node_ *left;
	struct node_ *right;
} node_t;

void heapify (node_t array[], int idx, int n)
{
    int l_idx, r_idx, min_idx;
	node_t min = {MAX_INT};

    while (1) {
        l_idx = 2 * idx + 1;
        r_idx = 2 * idx + 2;

        if ((r_idx < n) && (array[r_idx].freq < array[l_idx].freq)) {
            min = array[r_idx];
            min_idx = r_idx;
        } else if (l_idx < n) {
            min = array[l_idx];
            min_idx = l_idx;
        } else {
            break;
        }
        if (min.freq < array[idx].freq) {
            array[min_idx] = array[idx];
            array[idx] = min;
            idx = min_idx;
        } else {
            break;
        }
    }
}

node_t *delete (node_t array[], int *n) {
	if (*n == 0) {
		return NULL;
	} else if (*n == 1) {
		--*n;
		return &array[0];
	} else {
		int idx = *n - 1;
		node_t tmp = array[0];
		array[0] = array[idx];
		array[idx] = tmp;

		heapify(array, 0, --*n);

		return &array[idx];
	}
}

node_t *insert(node_t array[], node_t elem, int *n) {
    int idx = *n;
	int pidx;
	array[idx] = elem;

	while (idx > 0) {
		pidx = (idx - 1) / 2;
		if (array[idx].freq < array[pidx].freq) {
			node_t tmp = array[pidx];
			array[pidx] = array[idx];
			array[idx] = tmp;
			idx = pidx;
		} else {
			break;
		}
	}

	(*n)++;
	return &array[idx];
}

node_t *generateHuffmanCodes(node_t array[], int *n)
{
	int count = *n;

	/* Start process of optimized merge */
	node_t *root = NULL;
	node_t *min1, *min2;
	while (1) {
		min1 = delete(array, &count);
		if (!min1) {
			break;
		}
		min2 = delete(array, &count);
		if (!min2) {
			break;
		}

		node_t *new = (node_t *)malloc(sizeof(node_t));
		node_t *left = (node_t *)malloc(sizeof(node_t));
		node_t *right = (node_t *)malloc(sizeof(node_t));
		*left = *min1;
		*right = *min2;
		new->freq = left->freq + right->freq;
		new->left = left;
		new->right = right;
		new->c = '\0';

		min2 = new;
		insert(array, *min2, &count);

		root = new;

		printf("root %d", root->freq);
		printf(" left %c %d", root->left->c, root->left->freq);
		printf(" right %c %d", root->right->c, root->right->freq);
		printf("\n");
	}

	*n = count;
	return root;
}

int stack[100];
int sptr = 0;

void printHuffmanCodes(node_t *root) {
	if (!root) return;
	if (root->left == NULL && root->right == NULL) {
		int i = 0;
		printf("%c ", root->c);
		while (i < sptr) {
			printf("%d", stack[i++]);
		}
		printf("\n");
	} else {
		stack[sptr++] = 0;
		printHuffmanCodes(root->left);
		sptr--;
		stack[sptr++] = 1;
		printHuffmanCodes(root->right);
		sptr--;
	}
}

node_t *initFrequencyArray(char *str, int *uniq) {
	char *ptr = str;
	size_t n = 26;
	node_t *array = (node_t *)malloc(sizeof(node_t) * n);
	int count = 0;
	int i, j;

	memset(array, 0, sizeof(node_t) * n);

	/* Fill up frequency array */
	while (*ptr) {
		if (array[*ptr - 'A'].c != *ptr) {
			array[*ptr - 'A'].c = *ptr;
			count++;
		}
		array[*ptr - 'A'].freq++;
		ptr++;
	}

	*uniq = count;
	printf("Total unique characters: %d\n", *uniq);

	/* Bring all non-zero values to beginning of array */
	i = 0;
	j = n - 1;
	while (i < j) {
		if (array[i].freq == 0) {
			while (!array[j].freq) {
				j--;
			}
			if (i != j) {
				node_t tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
		i++;
	}

	/* Print the array */
	for (int i = 0; i < count; i++) {
		printf("%c %2d\n", array[i].c, array[i].freq);
	}

	/* Heapify */
	for (int i = (count - 2) / 2; i >= 0; i--) {
		heapify(array, i, count);
	}

	printf("After heapify...\n");
	for (int i = 0; i < count; i++) {
		printf("%c %2d\n", array[i].c, array[i].freq);
	}

	return array;
}

int main()
{
	char str[] = "ABCBCBCBAABCBBCABBABABALAJAGHA";
	int count = 0;
	node_t *array = initFrequencyArray(str, &count);
	node_t *tree = generateHuffmanCodes(array, &count);
	printf("Huffman Codes...\n");
	printHuffmanCodes(tree);

	return 0;
}
