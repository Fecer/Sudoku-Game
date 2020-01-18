//
//  main.cpp
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include "Sudoku.h"
#include "endingGenerator.h"
using namespace std;

#define MAX 1000000
#define MIN 1

void generateEnding(const int num)
{
    eGenerator eg;
    Sudoku s(num);
    int times;  //不同的首行数量
    
    time_t start, stop; //计时
    start = time(0);    //开始计时
    
    times = (num / 36) + 1;   //计算需要多少个不同的首行
    for(int i = 0; i < times; i++)
    {
        if(s.isEnough())  //数量足够
            break;
        // 1. get FR
        // 2. 1R -> 9R
        s.rowToSqr(eg.getFirstRow());       // 1 row to 9 rows

        // 3. exchange
        s.exchange(eg.getFirstRow());
        
        eg.permutation();   //生成下一个首行排列
    }
    
    s.prntIntoFileE();   //写入文件
    
    stop = time(0);
    cout << difftime(stop, start) << "seconds" << endl;
}

void solveSudoku(string path)
{
    Sudoku result(path);
    time_t start, stop; //计时
    start = time(0);    //开始计时
    
    result.solve();     //解数独
    result.prntIntoFileS();  //写入文件
    
    stop = time(0);
    cout << difftime(stop, start) << "seconds" << endl;
}

int main(int argc, const char * argv[])
{
    //参数数量合法检测
    if(argc != 3)
    {
        cout << "Wrong argument quantity!" << endl;
        return 0;
    }

    string oprationType = argv[1];  //查看操作类型

    if(oprationType == "-c")    //生成终局
    {
        //确认输入的确实是数字
        int num;
        try{
            num = atoi(argv[2]);
        }
        catch (invalid_argument e){
            cout << "Not a Number" << endl;
            return 0;
        }

        //判断数字是否越界
        if (num < MIN || num > MAX)
        {
            //越界
            cout << "Illegal result quantity\n" << endl;
        }
        else
            generateEnding(num);    //生成
    }
    else if(oprationType == "-s")   //求解数独
    {
        string path = argv[2];
        ifstream inFile;

        inFile.open(path);
        if(inFile)  //打开成功，文件存在
        {
            //solve
            solveSudoku(path);
        }
        else    //路径文件不存在
        {
            cout << "Invalid puzzlefile path!" << endl;
        }

    }
    else    //参数正确性合法检测
    {
        cout << "Illegal input" << endl;
        return 0;
    }
 //   generateEnding(1000000);
//	  solveSudoku("/Users/fever/Desktop/problem.txt");
    return 0;
}
