//
//  test.cpp
//  SudokuGenerator
//
//  Created by Fever on 2020/1/19.
//  Copyright © 2020 BIT. All rights reserved.
//

#include "Sudoku.h"
#include "endingGenerator.h"

void RtoSqrTEST()
{
    string str = "6 1 2 3 4 5 7 8 9\n3 4 5 7 8 9 6 1 2\n7 8 9 6 1 2 3 4 5\n1 2 3 4 5 7 8 9 6\n4 5 7 8 9 6 1 2 3\n8 9 6 1 2 3 4 5 7\n2 3 4 5 7 8 9 6 1\n5 7 8 9 6 1 2 3 4\n9 6 1 2 3 4 5 7 8";
    
    eGenerator eg;
    Sudoku s(1);
    
    s.rowToSqr(eg.getFirstRow());
    
    if(str == s.getOutputE())
        cout << "R to Sqr Right" << endl;
    else
        cout << "R to Sqr Wrong" << endl;
    
    return;
}

void solveTEST()
{
    Sudoku s("./solveTest.txt");
    
    s.solve();
    
}

int main
{
    
    return 0;
}
