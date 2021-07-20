#include <main.h>

int passing_argument_by_value(int m, int n, int p)
{
	int result;
	result = m > n ? m : n;
	result = result > p ? result : p;
	return(result);
}

void passing_argument_by_reference(int *ptra, int *ptrb, int *ptrc, int *ptrmax)
{
	*ptrmax = *ptra > *ptrb ? *ptra : *ptrb;
	*ptrmax = *ptrmax > *ptrc ? *ptrmax : *ptrc;
	return;
}

int max_bc(int n, int p)
{
	int result;
	result = n > p ? n : p;
	return(result);
}

int max_abc(int m, int n, int p, int (*ptrf)(int, int))
{
	int result;
	result = m > ptrf(n, p) ? m : ptrf(n, p);
	return(result);
}