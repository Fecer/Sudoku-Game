//
//  endingGenerator.cpp
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#include "endingGenerator.h"
#include <algorithm>
#include <iostream>
using namespace std;

//构造函数，需要num个终局
eGenerator::eGenerator()
{
    //初始化firstRow,首位为6
    firstRow[0] = 6;
    for(int i = 1; i < 6; i++)
    {
        firstRow[i] = i;
    }
    for(int i = 6; i < 9; i++)
    {
        firstRow[i] = i + 1;
    }
}

//生成下一个首行元素
int* eGenerator::permutation()
{
    next_permutation(this->firstRow + 1, this->firstRow + 9);
    
    return firstRow;
}

//获取首行
int* eGenerator::getFirstRow()
{
    return this->firstRow;
}
