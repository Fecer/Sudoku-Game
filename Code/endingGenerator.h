//
//  endingGenerator.h
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#ifndef endingGenerator_h
#define endingGenerator_h

#include <algorithm>
#include <iostream>
#include "Sudoku.h"
using namespace std;

class eGenerator
{
private:
    int firstRow[9];        //暂存数独首行
public:
    eGenerator();
    int* permutation();     //生成第一行的合法排列
    int* getFirstRow();     //获得首行
};

#endif /* endingGenerator_h */
