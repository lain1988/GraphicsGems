/**************************************************************** 
Map a point from the square [0,1] x [0,1] into a convex polygon.
Uniform random points in the square will genrerate uniform random
points in the polygon.

The procedure triangle_areas() must be called once to compute 
'areas', and then this procedure can be called repeatedly.

Entry:
  vertices - list of the vertices of a convex polygon
  vcount   - number of vertices of polygon
  areas    - relative areas of sub-triangles of polygon
  s,t      -  position in the square [0,1] x [0,1]
Exit:
  p        - position in polygon
*****************************************************************/
include "../GraphicsGems.h";
include "../Vector.h";

square_to_polygon (vertices, vcount, areas, s, t, p)
	Point3 vertices[];
	int vcount;
	float areas[];
	float s,t;
	Point3 *p;
{
	int i;
	float area_sum = 0;
	float a,b,c;

	/* use 's' to pick one sub-triangle, weighted by relative */
	/* area of triangles */

	for (i = 0; i < vcount - 2; i++) {
		area_sum += areas[i];
		if(area_sum >= s)
			break;
	}

	/* map 's' into interval [0,1] */

	s = (s - area_sum + areas[i]) / areas[i];

	/* map (s,t) to a point in that sub-triangle */

	t = sqrt(t);

	a = 1 - t;
	b = (1 - s) * t;
	c = s * t;

	p->x = a * vertices[0].x + b * vertices[i+1].x + c * vertices[i+2].x;
	p->y = a * vertices[0].y + b * vertices[i+1].y + c * vertices[i+2].y;
	p->z = a * vertices[0].z + b * vertices[i+1].z + c * vertices[i+2].z;
}
