#ifndef GBPS_TREE_H
#define GBPS_TREE_H
#include"common.h"
//object may be houses,trees blah blah blah beside the road
typedef struct
{
    float x,y;//position of car (in 2D)

    int type;//type of object (tree, house)

} GBPS_Tree;

void RenderTree(GBPS_Tree Tree);

#endif
