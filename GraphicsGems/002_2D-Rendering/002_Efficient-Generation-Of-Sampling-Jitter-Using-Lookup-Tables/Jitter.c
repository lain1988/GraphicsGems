/*		Jitter.c - Sampling jitter generation rutines
*	
*	Description:
*		Jitter.c contains the routines for generation of sampling
*		jitter using lookup-tables
*
*	Contents:
*		Jitter1		Generate random jitter function 1.
*		Jitter2		Generate random jitter function 2.
*		JitterInit	Initialize lookup-tables.
*/

#define			NRAN	1024	/* Random number table length */

static double	URANX[NRAN],	/* Random number tables */
				URANY[NRAN];
static int 		IRAND[NRAN];	/* Shuffle table */
static int		MASK = NRAN-1;	/* mask for jitter mod function */
extern double	xranf();		/* Random number generator producing uniform numbers 0 to 1 */

/* 		Jitter1 - Generate random jitter.	 */

void 	Jitter1 (x,y,s,xj,yj)
	 	int x, y;				/* Pixel Location */
		int s;					/* Sample number for the the Pixel */
		double *xj, *yj;		/* Jitter (x,y) */
{
		*xj = URANX[ (x + (y<<2) + IRAND[(x+s)&MASK]) & MASK ];
		*xj = URANY[ (y + (x<<2) + IRAND[(y+s)&MASK]) & MASK ];
}


/* 		Jitter2- Generate random jitter.	 */

void 	Jitter2 (x,y,s,xj,yj)
	 	int x, y;				/* Pixel Location */
		int s;					/* Sample number for the the Pixel */
		double *xj, *yj;		/* Jitter (x,y) */
{
		*xj = URANX[ (x | (y<<2) + IRAND[(x+s)&MASK]) & MASK ];
		*xj = URANY[ (y | (x<<2) + IRAND[(y+s)&MASK]) & MASK ];
}

/* 		JitterInit - Initialize lookup-tables */

void 	JitterInit	()
{
		int i;

		for ( i = 0 ; i < NRAN ; i++) URANX[i] = xranf();
		for ( i = 0 ; i < NRAN ; i++) URANY[i] = xranf();
		for ( i = 0 ; i < NRAN ; i++) IRAND[i] = (int) (NRAN * xranf());
}
