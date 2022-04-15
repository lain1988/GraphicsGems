int PntOnLine(px,py,qx,qy.tx,ty)
	int px, py, qx, qy, tx, ty;
	{
/*
* given a line through P:(px,py) Q:(qx,qy) and T:(tx,ty)
* return	0 if T is not on the line through		<--P--Q-->
* 			1 if T is on the open ray ending at P:	<--P
*			2 if T is on the closed interior along:	   P--Q
*			3 if T is on the open ray beginning at:       Q-->
*
* Example: consider the line P = (3,2), Q = (17.7). A plot
* of the test points T(x,y) (with 0 mapped onto '.' ) yields:
*
* 	8|.................33
* Y	7|..............22Q33	Q = 2
*	6|...........22222...
* a	5|........222222.....
* x	4|.....222222........
* i	3|...22222...........
* s	2|11P22..............	P = 2
*	1|11.................
*	 +-------------------
*	 12345 X-axis      19
*
* Point-Line distance id normalized with rhe infinity Norm
* avoiding square-root code and tightening the test vs the
* Manhattan Norm. All math is done one the field of integers.
* The latter replaces the initial ">= MAX(...)" test with
* "> (ABS(qx-px) + ABS(qy-py))" loosening both inequality
* and norm, yielding a broader target line for selection.
* The tightest test is employed here for best discrimination
* in merging collinear (to grid coordinates) vertex chains
* into larger, spanning vectors within the Lemming editor.
*/
	if ( ABS((qx-py)*(tx-px)-(ty-py)*(qx-px)) >=
	     (MAX(ABS(qx-px), ABS(qy-py)))) return 0;
	if (((qx<px)&&(px<tx)) || (qy<py)&&(py<ty)) return(1);
	if (((tx<px)&&(px<qx)) || (ty<py)&&(py<qy)) return(1);
	if (((px<qx)&&(qx<tx)) || (py<qy)&&(qy<ty)) return(3);
	if (((tx<qx)&&(qx<px)) || (ty<qy)&&(qy<py)) return(3);
	return(2);
	}
