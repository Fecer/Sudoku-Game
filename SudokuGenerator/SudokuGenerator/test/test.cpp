//
//  test.cpp
//  SudokuGenerator
//
//  Created by Fever on 2020/1/19.
//  Copyright © 2020 BIT. All rights reserved.
//

#include "Sudoku.h"
#include "endingGenerator.h"
#include <fstream>

void RtoSqrTEST()
{
    string str = "6 1 2 3 4 5 7 8 9\n3 4 5 7 8 9 6 1 2\n7 8 9 6 1 2 3 4 5\n1 2 3 4 5 7 8 9 6\n4 5 7 8 9 6 1 2 3\n8 9 6 1 2 3 4 5 7\n2 3 4 5 7 8 9 6 1\n5 7 8 9 6 1 2 3 4\n9 6 1 2 3 4 5 7 8\n\n";
    
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
    
    fstream fs("./sudokuAnswer.txt" );     // 创建个文件流对象,并打开txt
    stringstream ss;                        // 创建字符串流对象
    ss << fs.rdbuf();                       // 把文件流中的字符输入到字符串流中
    string str = ss.str();                  // 获取流中的字符串
    
    str += "\n\n";
    Sudoku s("./testsolve.txt");
    
    s.solve();
    
    if(str == s.getOutputE())
        cout << "solve Right" << endl;
    else
        cout << "solve Wrong" << endl;
        
    return;
}

