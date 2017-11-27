#ifndef CUBE_H
#define CUBE_H

static int init_facet_data[NUM_BASIS_CUBES][NUM_CUBE_EDGES] = {
  
  {-1,-1,-1,  -1,-1,-1,  -1,-1,-1,  -1,-1,-1,},
  { 6, 5,10,  -1,-1,-1,  -1,-1,-1,  -1,-1,-1,},
  { 2,10, 9,   2, 9, 0,  -1,-1,-1,  -1,-1,-1,},
  { 6, 5,10,   1, 9, 0,  -1,-1,-1,  -1,-1,-1,},
		     
  {10, 9, 8,  10, 8,11,  -1,-1,-1,  -1,-1,-1,},
  { 9, 4, 7,   9, 7, 1,   1, 7,11,   1,11, 2,},
  { 1, 5, 4,   1, 4, 0,   3, 6, 2,   3, 7, 6,},
  { 1, 9, 8,   1, 8, 6,   8, 7, 6,   1, 6, 2,},

  { 6, 5,10,   0, 8, 3,  -1,-1,-1,  -1,-1,-1,},
  { 1, 0,10,   0, 8,10,  10, 8,11,  -1,-1,-1,},
  {11, 7, 6,  10, 9, 0,  10, 0, 2,  -1,-1,-1,},
  { 5, 4, 9,  11, 7, 6,   2,10, 1,  -1,-1,-1,},

  { 5, 4, 9,   1, 0,10,  10, 0, 8,  10, 8,11,},
  { 4, 7, 8,   6, 5,10,   1, 9, 0,   2, 3,11,},
  { 4, 7,11,   1, 4,11,   1, 0, 4,   1,11,10,},
};

static int init_facet_index[NUM_BASIS_CUBES][NUM_CUBE_VERTICES] = {
	{0,0,0,0, 0,0,0,0,},
  	{0,0,0,0, 0,0,1,0,},
  	{0,1,1,0, 0,0,0,0,},
  	{0,1,0,0, 0,0,1,0,},

  	{1,1,1,1, 0,0,0,0,},
  	{1,1,0,1, 1,0,0,0,},
  	{0,1,0,1, 0,1,0,1,},
  	{1,1,0,1, 0,0,0,1,},

  	{1,0,0,0, 0,0,1,0,},
  	{1,0,1,1, 0,0,0,0,},
  	{0,1,1,0, 0,0,0,1,},
  	{0,0,1,0, 0,1,0,1,},

  	{1,0,1,1, 0,1,0,0,},
  	{0,1,0,1, 1,0,1,0,},
  	{1,0,1,1, 1,0,0,0,},
};


static int facet_data[NUM_CUBE_PERMS][NUM_CUBE_EDGES];
static int edge_data[NUM_CUBE_PERMS][NUM_CUBE_EDGES];
static int edge_list[NUM_CUBE_EDGES]={11,2,1, 0,4,6, 3,7,5, 8,9,10};

static int edge_rotation[NUM_CUBE_ROTATIONS][NUM_CUBE_EDGES] = {
  /* face 5,6,2,1 forward */
  /* 00 */  { 0, 1, 2, 3,   4, 5, 6, 7,   8, 9,10,11,},
  /* 01 */  { 2,10, 6,11,   0, 9, 4, 8,   3, 1, 5, 7,},
  /* 02 */  { 6, 5, 4, 7,   2, 1, 0, 3,  11,10, 9, 8,},
  /* 03 */  { 4, 9, 0, 8,   6,10, 2,11,   7, 5, 1, 3,},

  /* face 6,7,3,2 forward */
  /* 04 */  { 1, 2, 3, 0,   5, 6, 7, 4,   9,10,11, 8,},
  /* 05 */  { 3,11, 7, 8,   1,10, 5, 9,   0, 2, 6, 4,},
  /* 06 */  { 7, 6, 5, 4,   3, 2, 1, 0,   8,11,10, 9,},
  /* 07 */  { 5,10, 1, 9,   7,11, 3, 8,   4, 6, 2, 0,},

  /* face 7,4,0,3 forward */
  /* 08 */  { 2, 3, 0, 1,   6, 7, 4, 5,  10,11, 8, 9,},
  /* 09 */  { 0, 8, 4, 9,   2,11, 6,10,   1, 3, 7, 5,},
  /* 10 */  { 4, 7, 6, 5,   0, 3, 2, 1,   9, 8,11,10,},
  /* 11 */  { 6,11, 2,10,   4, 8, 0, 9,   5, 7, 3, 1,},

  /* face 4,5,1,0 forward */
  /* 12 */  { 3, 0, 1, 2,   7, 4, 5, 6,  11, 8, 9,10,},
  /* 13 */  { 1, 9, 5,10,   3, 8, 7,11,   2, 0, 4, 6,},
  /* 14 */  { 5, 4, 7, 6,   1, 0, 3, 2,  10, 9, 8,11,},
  /* 15 */  { 7, 8, 3,11,   5, 9, 1,10,   6, 4, 0, 2,},

  /* face 4,7,6,5 forward */
  /* 16 */  { 9, 5,10, 1,   8, 7,11, 3,   0, 4, 6, 2,},
  /* 17 */  {10, 6,11, 2,   9, 4, 8, 0,   1, 5, 7, 3,},
  /* 18 */  {11, 7, 8, 3,  10, 5, 9, 1,   2, 6, 4, 0,},
  /* 19 */  { 8, 4, 9, 0,  11, 6,10, 2,   3, 7, 5, 1,},

  /* face 1,2,3,0 forward */
  /* 20 */  { 8, 3,11, 7,   9, 1,10, 5,   4, 0, 2, 6,},
  /* 21 */  {11, 2,10, 6,   8, 0, 9, 4,   7, 3, 1, 5,},
  /* 22 */  {10, 1, 9, 5,  11, 3, 8, 7,   6, 2, 0, 4,},
  /* 23 */  { 9, 0, 8, 4,  10, 2,11, 6,   5, 1, 3, 7,},
};

static int corner_rotation[NUM_CUBE_ROTATIONS][NUM_CUBE_VERTICES] = {
  /* face 5,6,2,1 forward */
  /* 00 */  { 0, 1, 2, 3,   4, 5, 6, 7,},
  /* 01 */  { 3, 2, 6, 7,   0, 1, 5, 4,},
  /* 02 */  { 7, 6, 5, 4,   3, 2, 1, 0,},
  /* 03 */  { 4, 5, 1, 0,   7, 6, 2, 3,},

  /* face 6,7,3,2 forward */
  /* 04 */  { 1, 2, 3, 0,   5, 6, 7, 4,},
  /* 05 */  { 0, 3, 7, 4,   1, 2, 6, 5,},
  /* 06 */  { 4, 7, 6, 5,   0, 3, 2, 1,},
  /* 07 */  { 5, 6, 2, 1,   4, 7, 3, 0,},

  /* face 7,4,0,3 forward */
  /* 08 */  { 2, 3, 0, 1,   6, 7, 4, 5,},
  /* 09 */  { 1, 0, 4, 5,   2, 3, 7, 6,},
  /* 10 */  { 5, 4, 7, 6,   1, 0, 3, 2,},
  /* 11 */  { 6, 7, 3, 2,   5, 4, 0, 1,},

  /* face 4,5,1,0 forward */
  /* 12 */  { 3, 0, 1, 2,   7, 4, 5, 6,},
  /* 13 */  { 2, 1, 5, 6,   3, 0, 4, 7,},
  /* 14 */  { 6, 5, 4, 7,   2, 1, 0, 3,},
  /* 15 */  { 7, 4, 0, 3,   6, 5, 1, 2,},

  /* face 4,7,6,5 forward */
  /* 16 */  { 1, 5, 6, 2,   0, 4, 7, 3,},
  /* 17 */  { 2, 6, 7, 3,   1, 5, 4, 0,},
  /* 18 */  { 3, 7, 4, 0,   2, 6, 5, 1,},
  /* 19 */  { 0, 4, 5, 1,   3, 7, 6, 2,},

  /* face 1,2,3,0 forward */
  /* 20 */  { 4, 0, 3, 7,   5, 1, 2, 6,},
  /* 21 */  { 7, 3, 2, 6,   4, 0, 1, 5,},
  /* 22 */  { 6, 2, 1, 5,   7, 3, 0, 4,},
  /* 23 */  { 5, 1, 0, 4,   6, 2, 3, 7,},
};


#endif
