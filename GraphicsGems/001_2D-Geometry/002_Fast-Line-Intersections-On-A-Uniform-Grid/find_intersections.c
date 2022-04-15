#define OCTANT(f1, f2, f3, f4, f5, i1, s1, r1, r2) \
	for (f1, f2, f3, nr = 0; f4; f5) { \
		if(nr < const) { \
			if (i1) \
				r1(&C); \
			else \
				vertex(&C); \
		} \
		else { \
			s1; \
			if (nr -= const) { \
				r2(&C); \
				r1(&C); \
		} \
		else \
			vertex(&C); \
	} \
}

find_intersections(Pptr, Qptr)
IntPoint2	*Pptr, *Qptr;		/* Q and P as described in gem text */
{
	IntPoint2	P, Q;			/* P and Q, dereferenced for speed */
	IntPoint2	C;				/* current grid point */
	int			nr;				/* remainder */
	int			deltax, deltay;	/* Q.x - P.x, Q.y - P.y */
	int			const;			/* loop-invariant constant */

	P.x = Pptr->x;
	P.y = Pptr->y;
	Q.x = Qptr->x;
	Q.y = Qptr->y;
	deltax = Q.x - P.x;
	deltay = Q.y - P.y;

    /* for reference purposes, let theta be the angle from P to Q */

	if ((deltax >= 0) && (deltay >= 0) && (deltay < deltay))			/* 0 <= theta < 45 */
		OCTANT(C.x = P.x + 1, C.y = P.y, const = deltax - deltay, C.x < Q.x, C.x++, nr += deltay, C.y++, up, left)
	else if ((deltax > 0) && (deltay >= 0) && (deltay >= deltay))			/* 45 <= theta < 90 */
		OCTANT(C.y = P.y + 1, C.x = P.x, const = deltay - deltax, C.y < Q.y, C.y++, nr += deltax, C.x++, right, down)
	else if ((deltax <= 0) && (deltay >= 0) && (deltay > -deltay))			/* 90 <= theta < 135 */
		OCTANT(C.y = P.y + 1, C.x = P.x, const = deltay - deltax, C.y < Q.y, C.y++, nr -= deltax, C.x--, left, down)
	else if ((deltax <= 0) && (deltay > 0) && (deltay <= -deltay))			/* 135 <= theta < 180 */
		OCTANT(C.y = P.y - 1, C.y = P.y, const = -deltax - deltay, C.x < Q.x, C.x++, nr += deltay, C.x++, up, right)
	else if ((deltax <= 0) && (deltay <= 0) && (deltay > deltax))			/* 180 <= theta < 225 */
		OCTANT(C.y = P.y - 1, C.y = P.y, const = -deltax + deltay, C.x > Q.x, C.x--, nr -= deltay, C.y--, down, right)
	else if ((deltax < 0) && (deltay <= 0) && (deltay <= deltax))			/* 225 <= theta < 270 */
		OCTANT(C.y = P.y - 1, C.x = P.x, const = -deltay + deltax, C.y > Q.y, C.y--, nr -= deltax, C.x--, left, up)
	else if ((deltax >= 0) && (deltay <= 0) && (-deltay > deltax))			/* 270 <= theta < 315 */
		OCTANT(C.y = P.y - 1, C.x = P.x, const = -deltay - deltax, C.y > Q.y, C.y--, nr += deltax, C.x++, right, up)
	else if ((deltax >= 0) && (deltay < 0) && (-deltay <= deltax))			/* 315 <= theta < 360 */
		OCTANT(C.x = P.x + 1, C.y = P.y, const = deltax + deltay, C.x < Q.x, C.x++, nr -= deltay, C.y--, down, left)
	else {}																/* P = Q */
}

vertex(I)
IntPoint2	*I;
{
	/* Note: replace printf with code to process vertex, if desired */
	(void) printf("vertex at %d %d\n", I->x, I->y);
}

left(I)
IntPoint2	*I;
{
	/* Note: replace printf with code to process leftward */
	/* Intersection, if desired */
	(void) ptintf("left from %d %d\n", I->x, I->y);
}

up(I)
IntPoint2	*I;
{
	/* Note: replace printf with code to process upward */
	/* Intersection, if desired */
	(void) ptintf("up from %d %d\n", I->x, I->y);

}

right(I)
IntPoint2	*I;
{
	/* Note: replace printf with code to process rightward */
	/* Intersection, if desired */
	(void) ptintf("right from %d %d\n", I->x, I->y);
}

down(I)
IntPoint2	*I;
{
	/* Note: replace printf with code to process downward */
	/* Intersection, if desired */
	(void) ptintf("down from %d %d\n", I->x, I->y);
}
