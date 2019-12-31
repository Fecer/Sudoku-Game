//
//  Sudoku.cpp
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#include <iostream>
#include "Sudoku.h"
#include <fstream>
#include <sstream>

Sudoku::Sudoku(const int &n)
{
    //初始化displace
    int stndrd[9] = {0, 3, 6, 1, 4, 7, 2, 5, 8};
    memcpy(this->displace, stndrd, sizeof(stndrd));
    
    num = n;
    cnt = 0;
}

//由displace + firstRow生成整个数独
void Sudoku::rowToSqr(int firstRow[])
{
//    //放入首行
//    for(int i = 0; i < 9; i++)
//    {
//        output += (firstRow[i] + '0');
//        if(i != 8)
//            output += ' ';
//        else
//            output += '\n';
//    }
//
    for(int i = 0; i < 9; i++)  //生成9行
    {
        int bgn = displace[i];  //从新的位置开始
        for(int j = bgn; j < bgn + 9; j++)
        {
            output += (firstRow[(j % 9)] + '0');    //错位放入
            if(j != bgn + 8)
                output += ' ';
            else
                output += '\n';
        }
    }
    output += '\n'; //两个数独间的空行
    this->cnt++;    //计数
    
}

//交换行
void Sudoku::exchange(int firstRow[])
{
    //更改displace以达到交换行的效果
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(this->num == this->cnt)  //数量足够
                break;
            next_permutation(this->displace + 3, this->displace + 6);
            this->rowToSqr(firstRow);   //根据新的displace再写入
        }
        next_permutation(this->displace + 6, this->displace + 9);
    }
    
}

//打印查看
void Sudoku::prntIntoFile()
{
//    cout << this->output;
    ofstream fs;
    
    cout << "开始生成：" << endl;
    fs.open("/Users/fever/Desktop/ending.txt");
    fs << this->output;
    fs.close();
    
    cout << cnt << endl;
    
}

bool Sudoku::isEnough()
{
    if(this->cnt == this->num)
        return true;
    return false;
}
