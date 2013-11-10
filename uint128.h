#ifndef UINT128_H
#define UINT128_H

struct uint128 {
	
	unsigned long long left;
	unsigned long long right;
};

void create_uint128(const char *input, struct uint128 *output);
int cmp_uint128(const struct uint128 *a, const struct uint128 *b);

#endif
