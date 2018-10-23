#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "sieve.h"

int sieve (int target_prime) {
	float mod = 0;
	if (target_prime < 1000) {
		if (target_prime == 1) {
			return 2;
		}
		mod = 1.5;
	}
	else {
		mod = 1.15;
	}
	int upper_bound = (int) round(target_prime * log(target_prime) * mod);
	int current_prime = 3;
	int primes_found = 1;
	char *list = calloc(upper_bound, 1);
	for(;primes_found<target_prime;current_prime+=2){
	    if (list[current_prime] == 0) {
			primes_found++;
			for (int i = current_prime; i <= upper_bound; i += 2 * current_prime) {
				list[i] = 1;
			}
	    }
	}
	free(list);
	return current_prime -2;
} 
