#include "tic_tac_toe_3.h"

/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/
bool check_column_win()
{   //0,3,6 or 1,4,7 or 2,5,8
    for(std::size_t i=0; i < pegs.size()/3; ++i)
    {
        if((pegs[i] == pegs[i+3]) && (pegs[i] == pegs[i+6]) && (pegs[i] != " "))
        {
            return true;
        }
    }
    return false;
}


/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/
bool check_row_win()
{   //0,1,2 or 3,4,5 or 6,7,8
    for(std::size_t i=0; i < pegs.size()/3; ++i)
    {
        if((pegs[3*i] == pegs[3*i+1]) && (pegs[3*i] == pegs[3*i+2] && (pegs[3*i] != " ")))
        {
            return true;
        }
    }
    return false;
}


/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/
bool check_diagonal_win()
{   //0,4,8 or 2,4,6
    if((pegs[0] == pegs[4]) && (pegs[0] == pegs[8]) && (pegs[0] != " "))
    {
        return true;
    }

    else if((pegs[2] == pegs[4]) && (pegs[2] == pegs[6]) && (pegs[2] != " "))
    {
        return true;
    }
    return false;
}