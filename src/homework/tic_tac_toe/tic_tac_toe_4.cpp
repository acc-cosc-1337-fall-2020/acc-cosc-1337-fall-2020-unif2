#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/
bool check_column_win()
{//0,4,8,12  1,5,9,13   2,6,10,14   3,7,11,15
    for(std::size_t i=0; i < pegs.size()/4; ++i)
    {
        if((pegs[i] == pegs[i+4]) && (pegs[i] == pegs[i+8]) && (pegs[i] == pegs[i+12]) && (pegs[i] != " "))
        {
            return true;
        }
    }
    return false;
}



/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/
bool check_row_win()
{//0,1,2,3   4,5,6,7   8,9,10,11   12,13,14,15
    for(std::size_t i=0; i < pegs.size()/4; ++i)
    {
        if((pegs[4*i] == pegs[4*i + 1]) && (pegs[4*i] == pegs[4*i + 2]) && (pegs[4*i] == pegs[4*i + 3]) && (pegs[4*i] != " "))
        {
            return true;
        }
    }
    return false;
}


/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
bool check_diagonal_win()
{//0,5,10,15   3,6,9,12
    if((pegs[0] == pegs[5]) && (pegs[0] == pegs[10]) && (pegs[0] == pegs[15]) && (pegs[0] != " "))
    {
        return true;
    }

    else if((pegs[3] == pegs[6]) && (pegs[3] == pegs[9]) && (pegs[3] == pegs[12]) && (pegs[3] != " "))
    {
        return true;
    }
    return false;
}