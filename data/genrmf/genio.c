/* I/O routines for DIMACS standard format generator */
/*
   Implemented by 
   Tamas Badics, 1991, 
   Rutgers University, RUTCOR
   P.O.Box 5062
   New Brunswick, NJ, 08903
 
   e-mail: badics@rutcor.rutgers.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include "gen_maxflow_typedef.h"
#include "genio.h"

/*===============================================================*/
void gen_free_net(network * n)
{
	free(n->edges);
	free(n);
}

/*================================================================*/
void print_max_format (FILE * out, network * n
					   , char * comm[], int dim)
                           /* prints a network heading with 
							  dim lines of comments
							  (no \n needs at the ends )*/
	 
{
	int i, vnum, e_num;
	edge * e;

	vnum = n->vertnum;
	e_num = n->edgenum;
	
	for( i = 0; i < dim; i++)
	  fprintf( out, "c %s\n", comm[i]);
	
	fprintf( out, "p max %7d %10d\n", vnum, e_num);
	fprintf( out, "n %7d s\n", n->source);
	fprintf( out, "n %7d t\n", n->sink);

	for (i = 1; i <= e_num; i++){
		e = &n->edges[i];
		fprintf(out, "a %7d %7d %10d\n"
			   , e->from, e->to, (int)e->cap); 
	}
}

