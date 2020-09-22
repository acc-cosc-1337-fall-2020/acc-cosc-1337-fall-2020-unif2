//cpp
#include "decision.h"

string get_letter_grade_using_if(int grade)
{
    string letter_grade;

    if (grade >= 90 && grade <= 100)
    {
        letter_grade = "A";
    }
    else if (grade >= 80 && grade <= 89)
    {
        letter_grade = "B";
    }
    else if (grade >= 70 && grade <= 79)
    {
        letter_grade = "C";
    }
    else if (grade >= 60 && grade <= 69)
    {
        letter_grade = "D";
    }
    else
    {
        letter_grade = "F";
    }
    return letter_grade;
}

string get_letter_grade_using_switch(int grade)
{
    string letter_grade;
    int range = grade / 10;
    
    switch(range)
    {
        case 10:
        {
            letter_grade = "A";
            break;
        }
        case 9:
        {
            letter_grade = "A";
            break;
        }
        case 8:
        {
            letter_grade = "B";
            break;
        }
        case 7:
        {
            letter_grade = "C";
            break;
        }
        case 6:
        {
            letter_grade = "D";
            break;
        }
        default:
        {
            letter_grade = "F";
        }
    }
    return letter_grade;
}