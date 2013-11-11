#include "uint128.h"

#include <stdlib.h>
#include <string.h>

void create_uint128(const char *input, struct uint128 *output) {

	output->right = strtoull(input+16, NULL, 16);

	char *tmp = alloca(17);
	memcpy(tmp, input, 16);

	tmp[16] = '\0';
	output->left = strtoull(tmp, NULL, 16);
}

void create_uint128_d(char *input, struct uint128 *output) {

	output->right = strtoull(input+16, NULL, 16);

	char *tmp = alloca(17);
	memcpy(tmp, input, 16);

	input[16] = '\0';
	output->left = strtoull(input, NULL, 16);
}

int cmp_uint128(const struct uint128 *a, const struct uint128 *b) {

	if (a->left != b->left) {
		return a->left > b->left? 1: -1;
	} else {

		if (a->right != b->right)
			return a->right > b->right? 1: -1;
		else
			return 0;
	}
}
