#include "Petla.h"

void Petla::petlowanie(int i, void(*func)(int)) {
	for (int iter_i = 0; iter_i < i; iter_i++) {
		func(iter_i);
	}
}

void Petla::petlowanie(int i, int j, void(*func)(int, int)) {
	for (int iter_j = 0; iter_j < j; iter_j++) {
		for (int iter_i = 0; iter_i < i; iter_i++) {
			func(iter_i, iter_j);
		}
	}
}

void Petla::petlowanie(int i, int j, int k, void(*func)(int, int, int)) {
	for (int iter_k = 0; iter_k < k; iter_k++) {
		for (int iter_j = 0; iter_j < j; iter_j++) {
			for (int iter_i = 0; iter_i < i; iter_i++) {
				func(iter_i, iter_j, iter_k);
			}
		}
	}
}