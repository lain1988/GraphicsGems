/* To improve the readability of C sources, we can replace lines like */
/* ptr = (OBJ *) malloc(sizeof(OBJ)) with the shorter ptr = NEW(OBJ) */
/* using a macro */

#define NEW(baz) (baz *) malloc(sizeof(baz))

/* We might also want to replace malloc with our own routine, which */
/* tests for a successful result */

char *my_malloc(unsigned bytes)
{
	char *tmp = malloc(bytes);
	if (! tmp) {
		handle_error_condition();
	}
	return(tmp);
}
