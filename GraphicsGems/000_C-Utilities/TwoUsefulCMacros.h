/* 
Althought Ansi C (and hence prototypes) are becoming more 
widespread, there is still a need for backward compatibility
with traditional (K + R) C. To accomodate this need, programmers
will often repeat the declarations for global procedures
within an #ifdef - one copy with prototype information, the
other without. the following approach allows for only one
declaration per procedure instead of two
*/

#ifdef _STDC_
#define Proto(arglist) arglist
#else
#define Proto(arglist) ()
#endif
extern double tan Proto(double);
extern int strcmp Proto((char *, char *));

/* Note that the double parentheses are needed to				  */
/* allow the passing of a variable number of arguments  in this   */
/* C-preprocessor macro. */

/* In any C program that has a large number of globals, a robust   */
/* way of keeping the definitions and the declarations consistent  */
/* is to use the foolowing approach .The file glabals.h looks like */

#ifdef DEFINE_GLOBALS
#define GLOBAL
#define INIT(x) = x
#else
#define GLOBAL extern

GLOBAL char  *prompt_string INIT("prompt> ");
GLOBAL int   lines_read     INIT(0);
GLOBAL int   line_buf;
GLOBAL float epsilon		INIT(.0001);

/* then exactly one source file #defines DEFINE_GLOBALS 			*/
/* before #including globals.h:This will allocate space for and 	*/
/* initialize all the globals. Every other file simply #includes	*/
/* globals.h */
