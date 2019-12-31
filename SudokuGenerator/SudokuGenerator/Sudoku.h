//
//  Sudoku.h
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#ifndef Sudoku_h
#define Sudoku_h

#include <string>
using namespace std;

class Sudoku
{
private:
    string output;          //输出用string
    int displace[9];        //每行向右位移量
    int cnt;                //已经生成的数量
    int num;                //需要生成的数量
public:
    Sudoku(const int &);
    void rowToSqr(int firstRow[]);              //由首行生成方块
    void exchange(int firstRow[]);              //交换得到更多终局
    void prntIntoFile();                        //输出到文件
    bool isEnough();                            //结果是否足够
};


#endif /* Sudoku_h */
