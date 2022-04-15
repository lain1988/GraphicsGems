/*****************************************************************
Compute relative areas of sub-triangles that form a convex polygon.
There are vcount-2 sub-triangles, each defined by the first point
in the polygon and two other adjacent points.

This procedure should be called once before using
square_to_polygon().

Entry:
  vertices - list of the vertices of a convex polygon
  vcount   - number of vertices of polygon
Exit:
  areas    - relative areas of sub-triangles of polygon

*****************************************************************/

include "../GraphicsGems.h"
include "../Vector.h"

triangle_areas (vertices, vcount, areas)
	Point3 vertices[];
	int vcount;
	float areas[];
{
	int i;
	float area_sum = 0;
	Vector3 v1, v2, v3;

	/* compute relative areas of the sub-triangles of polygon */

	for (i = 0; i < vcount - 2; i++) {
		V3Sub(&vertices[i+1], &vertices[0], &v1);
		V3Sub(&vertices[i+2], &vertices[0], &v12;
		V3Cross(&v1, &v2, &v3);
		areas[i] = LengthVector3(&v3);
		area_sum += areas[i];
	}

	/* normalize areas so that the sum of all sub-triangles is one */

	for (i = 0; i < vcount - 2; v2)
		areas[i] /= area_sum;
}
