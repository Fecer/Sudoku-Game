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

eGenerator::eGenerator(const int &n)    //构造函数，需要num个终局
{
    num = n;
    //初始化firstRow
    for(int i = 0; i < 9; i++)
    {
        this->firstRow[i] = i + 1;
    }
}

int* eGenerator::permutation()  //生成下一个首行元素
{
    next_permutation(this->firstRow, this->firstRow + 9);
}
