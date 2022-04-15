/* 
When programming in C, it is efficient to use a register variable
to point to a 2D array of values, for example a 4 x 4 array of doubles.
The more obvious ways of expressing this idea will confuse many compilers.
One solution is to put the matrix in a struct as the Vector C Library does.
*/

typedef struct {double element[4][4]; } Matrix4;

void func1 (matrix_pointer)
register Matrix4 *matrix_pointer;
{
	matrix_pointer->element[row][col] = expression;
}

/* Another solution to this problem is to use direct pointer typing */

void func2 (matrix_pointer)
register double (*matrix_pointer) [4][4];
{
	(*matrix_pointer) [row][col] = expression;
}

/* Both methods are somethat awkward. Sometimes it is helpful to */
/* define a macro to access a matrix via a register. */

/* See Fast Matrix Multiplication in this volume for hints on */
/* speeding up matrix multiplication. */
