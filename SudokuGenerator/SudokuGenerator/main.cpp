//
//  main.cpp
//  SudokuGenerator
//
//  Created by Fever on 2019/12/25.
//  Copyright © 2019 BIT. All rights reserved.
//

#include <iostream>
#include <string>
#include "Sudoku.h"
#include "endingGenerator.h"
using namespace std;

#define MAX 1000000
#define MIN 1


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
        
        if(num >= MIN && num <= MAX)    //在合理范围内，生成num个终局
        {
            eGenerator eg(num);
        }
        else
        {
            cout << "Illegal result quantity\n" << endl;
        }
    }
    else if(oprationType == "-s")   //求解数独
    {
        string path = argv[2];
        
        solve
    }
    else    //参数正确性合法检测
    {
        cout << "Illegal input" << endl;
        return 0;
    }
    
    return 0;
}
