//
//  endingGenerator.h
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#ifndef endingGenerator_h
#define endingGenerator_h
#include "Sudoku.h"

class eGenerator
{
private:
    int num;                //生成数量
    int firstRow[9];        //暂存数独首行
public:
    eGenerator();
    eGenerator(const int &);
    ~eGenerator();
    int* permutation();    //生成第一行的合法排列
};

#endif /* endingGenerator_h */
