#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H
/*
***** ALL RESULTS ARE VERIFIED ******
//---------------------------------------------------------------------
// normal run:
//---------------------------------------------------------------------

[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 83
tree_node CTOR: item: 83:0
|83|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 98
tree_node CTOR: item: 98:0
    |98|0
|83|1

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 39
tree_node CTOR: item: 39:0
    |98|0
|83|0
    |39|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 10
tree_node CTOR: item: 10:0
    |98|0
|83|-1
    |39|-1
        |10|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 23
tree_node CTOR: item: 23:0
    |98|0
|83|-1
        |39|0
    |23|0
        |10|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 49
tree_node CTOR: item: 49:0
        |98|0
    |83|0
        |49|0
|39|0
    |23|-1
        |10|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 7
tree_node CTOR: item: 7:0
        |98|0
    |83|0
        |49|0
|39|0
        |23|0
    |10|0
        |7|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 57
tree_node CTOR: item: 57:0
        |98|0
    |83|-1
            |57|0
        |49|1
|39|1
        |23|0
    |10|0
        |7|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 9
tree_node CTOR: item: 9:0
        |98|0
    |83|-1
            |57|0
        |49|1
|39|0
        |23|0
    |10|-1
            |9|0
        |7|1

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:r

-- Inserting 85
tree_node CTOR: item: 85:0
        |98|-1
            |85|0
    |83|0
            |57|0
        |49|1
|39|0
        |23|0
    |10|-1
            |9|0
        |7|1

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:s

what number to search ?10

item is found. |10|
        |98|-1
            |85|0
    |83|0
            |57|0
        |49|1
|39|0
        |23|0
    |10|-1
            |9|0
        |7|1

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:s

what number to search ?11

item not found.
        |98|-1
            |85|0
    |83|0
            |57|0
        |49|1
|39|0
        |23|0
    |10|-1
            |9|0
        |7|1

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:e

what number to erase ?
10
        |98|-1
            |85|0
    |83|0
            |57|0
        |49|1
|39|1
        |23|0
    |9|0
        |7|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:e

what number to erase ?
9
        |98|-1
            |85|0
    |83|0
            |57|0
        |49|1
|39|1
        |23|0
    |7|1

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:e

what number to erase ?
7
    |98|-1
        |85|0
|83|-1
            |57|0
        |49|1
    |39|1
        |23|0

================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:c

clearing the tree
================================
[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:x

ending program~
================================

//---------------------------------------------------------------------
// help:
//---------------------------------------------------------------------
The program will ask the user for their instruction and act accordingly,
    the program will be able to randomly insert number, insert entered
    number, search for number, and clear the whole tree.

------------ RESULTS --------------------
a interactive function


*/
#endif // Z_OUTPUT_H