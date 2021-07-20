#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>

int max_bc(int, int);
int max_abc(int, int, int, int (*)(int, int));

int passing_argument_by_value(int, int, int );
void passing_argument_by_reference(int*, int*, int*, int*);

#endif	/* __MAIN_H__ */
