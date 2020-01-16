//
//  Sudoku.cpp
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku(const int &n)
{
    //初始化displace
    int stndrd[9] = {0, 3, 6, 1, 4, 7, 2, 5, 8};
    
    memcpy(this->displace, stndrd, sizeof(stndrd));
    this->num = n;
    this->cntAlready = 0;
}

Sudoku::Sudoku(const string &p)
{
    this->path = p;
    this->goOn = true;
    this->curInfo.cnt = 0;
}

//由displace + firstRow生成整个数独
void Sudoku::rowToSqr(int firstRow[])
{
    for(int i = 0; i < 9; i++)  //生成9行
    {
        int bgn = displace[i];  //从新的位置开始
        for(int j = bgn; j < bgn + 9; j++)
        {
            outputE += (firstRow[(j % 9)] + '0');    //错位放入
            if(j != bgn + 8)
                outputE += ' ';
            else
                outputE += '\n';
        }
    }
    outputE += '\n'; //两个数独间的空行
    this->cntAlready++;    //计数
    
}

//交换行
void Sudoku::exchange(int firstRow[])
{
    //更改displace以达到交换行的效果
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(this->num == this->cntAlready)  //数量足够
                break;
            next_permutation(this->displace + 3, this->displace + 6);
            this->rowToSqr(firstRow);   //根据新的displace再写入
        }
        next_permutation(this->displace + 6, this->displace + 9);
    }
    
}

//打印查看终局
void Sudoku::prntIntoFileE()
{
    ofstream fs;
    
    cout << "---「开始生成终局」---" << endl;
    fs.open("/Users/fever/Desktop/answer.txt");
    fs << this->outputE;
    fs.close();
    cout << "共" << cntAlready << "个终局" << endl;
    cout << "---「完成生成终局」---" << endl;
}

void Sudoku::prntIntoFileS()
{
    ofstream fs;
    
    cout << "---「开始输出结果」---" << endl;
    fs.open("/Users/fever/Desktop/answer.txt");
    fs << this->outputE;
    fs.close();
    cout << "---「完成输出结果」---" << endl;
}

//判断是否达到需求上限
bool Sudoku::isEnough()
{
    if(this->cntAlready == this->num)
        return true;
    return false;
}

//解数独
void Sudoku::solve()
{
    ifstream inFile;
    char curStr[20] = {0};
    
    inFile.open(this->path);    //打开文件
    
    //判断文件是否空
    if(inFile.peek() == EOF)    //空文件
    {
        cout << "Empty file!" << endl;
        this->finishSolve();
        return;
    }
    
    this->init();   //初始化
    //计算1 - 1023每个数（二进制）有几个1
    for(int i = 1; i <= 1023; i++)
    {
        this->curInfo.num[i] = __builtin_popcount(i); //有几个1
    }
    
    int i = 1;
    while(!inFile.eof())
    {
        int input;
        int j;
        
        inFile.getline(curStr, 18); //读入一行
        
        if(curStr[0] == '\0')   //数独间空行
            goto cal;
        
        //存入
        for(int t = 0; t < 18; t++)
        {
            
            if(t % 2 == 0)
            {
                input = curStr[t] - '0';
                
                if(input)
                {
                    j = t / 2 + 1;
                    
                    this->curInfo.res[i][j] = curStr[t] - '0';
                    
                    for(int k = 1; k <= 9; k++)     //行
                        this->curInfo.reg[k][j] &= ( (1 << 9) - 1 - (1 << (input - 1)) );
                    for(int k = 1; k <= 9; k++)     //列
                        this->curInfo.reg[i][k] &= ( (1 << 9) - 1 - (1 << (input - 1)) );
                    for(int k = (i - 1) / 3 * 3 + 1; k <= (i - 1) / 3 * 3 + 3; k++)     //小九宫格
                        for(int l = (j - 1) / 3 * 3 + 1; l <= (j - 1) / 3 * 3 + 3; l++)
                            this->curInfo.reg[k][l] &= ( (1 << 9) - 1 - (1 << (input - 1)) );
                    this->curInfo.cnt++;
                }
            }
        }
 cal:   if(i <= 9)
            i++;
        else
        {
            i = 1;
            
            this->dfs(81 - this->curInfo.cnt);
            this->init();   //初始化
        }
    }
    
    return;
    
}

void Sudoku::dfs(const int &dep)
{
    //输出结果数独
    if(!dep)    //if(dep == 0)
    {
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
//                cout << this->curInfo.res[i][j] << " ";
                this->outputE += (this->curInfo.res[i][j] + '0');
                
                if(j != 9)
                    outputE += ' ';
                else
                    outputE += '\n';
            }
//            cout<<endl;
        }
        outputE += '\n';
    }
    
    int b[10][10];  //暂存结果a
    int c[10][10];  //暂存id
    int x = 0, y = 0, z = 9;
    
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            if(!this->curInfo.res[i][j] && !this->curInfo.reg[i][j])   //无结果
            {
                cout << "No result!" << endl;
                return ;
            }
            
            b[i][j] = this->curInfo.res[i][j];    //暂存
            c[i][j] = this->curInfo.reg[i][j];
            
            if(!this->curInfo.res[i][j])    //如果结果a数组该位是0
            {
                if(this->curInfo.num[ this->curInfo.reg[i][j] ] < z)   //寻找id[i][j]中的最小值
                {
                    z = this->curInfo.num[ this->curInfo.reg[i][j] ];
                    x = i;  //记录最小值位置
                    y = j;
                }
            }
        }
    }
    
    for(int i = 0; i < 9; i++)
    {
        if(this->curInfo.reg[x][y] & (1 << i) )  //
        {
            this->curInfo.res[x][y] = i + 1;
            for(int k = 1; k <= 9; k++)
                this->curInfo.reg[k][y] &= ( (1 << 9) - 1 - (1 << i));
            for(int k = 1; k <= 9; k++)
                this->curInfo.reg[x][k] &= ( (1 << 9) - 1 - (1 << i));
            for(int k = (x - 1) / 3 * 3 + 1; k <= (x - 1) / 3 * 3 + 3; k++)
            {
                for(int l = (y - 1) / 3 * 3 + 1; l <= (y - 1) / 3 * 3 + 3; l++)
                {
                    this->curInfo.reg[k][l] &= (( 1 << 9 ) - 1 -( 1 << i ));
                }
            }
            this->dfs(dep - 1);
            for(int i = 1; i <= 9; i++)
            {
                for(int j = 1; j <= 9; j++)
                {
                    this->curInfo.reg[i][j] = c[i][j];
                    this->curInfo.res[i][j] = b[i][j];
                }
            }
        }
    }
    return ;
}

//判断是否结束解题
bool Sudoku::isFinish()
{
    if(this->goOn == false)
    {
        return true;
    }
    return false;
}

//更改goOn状态
void Sudoku::finishSolve()
{
    this->goOn = false;
    
    return;
}

//初始化
void Sudoku::init()
{
    this->curInfo.cnt = 0;
    memset(this->curInfo.reg, 0, sizeof(this->curInfo.reg));
    memset(this->curInfo.res, 0, sizeof(this->curInfo.res));
    this->curInfo.all = (1 << 9) - 1;
    
    //init全部可能
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            this->curInfo.reg[i][j] = this->curInfo.all;
        }
    }
    
    return;
}
