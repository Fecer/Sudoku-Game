//
//  Sudoku.h
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#ifndef Sudoku_h
#define Sudoku_h

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Sudoku
{
private:
    string outputE;         //输出终局用string
    int displace[9];        //每行向右位移量
    int cntAlready;         //已经生成的数量
    int numNeed;            //需要生成的数量
    string path;            //谜题路径
    bool goOn;              //是否完成读入
  
	//用于解题的变量
	int cnt;
	int reg[10][10];    //保存对应位的数字可能性
	int all = (1 << 9) - 1;   //0111111111
	int res[10][10];    //结果
	int num[1 << 10];   //num[1024]

    int ID;                 //答案编号
    bool hasOneAnswer;      //已经输出一个答案
public:
    Sudoku(const string &);
    Sudoku(const int &);
    void rowToSqr(int firstRow[]);              //由首行生成方块
    void exchange(int firstRow[]);              //交换得到更多终局
    void prntIntoFileE();                       //输出到文件(生成终局）
    void prntIntoFileS();                       //输出到文件(解数独）
    bool isEnough();                            //结果是否足够
    void solve();                               //解数独
    void dfs(const int &);
    void finishSolve();                         //读到文件结尾
    bool isFinish();                            //是否结束解题
    void init();                                //初始化相关变量
};


#endif /* Sudoku_h */
