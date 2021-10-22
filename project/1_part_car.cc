/*
 * @Description: 用栈和链队实现停车场
 * @Author: HailayLin
 * @Date: 2021-10-18 10:21:16
 * @LastEditTime: 2021-10-18 16:12:21
 * @FilePath: \Algorithm\project\1_part_car.cc
 */

#include<iostream>
#include<string>
using namespace std;

// 参考google C++ 编码规范编写
// https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/naming/#constant-names

// 最大车牌号
const int kPlateNumMaxSize = 10;
// 停车场大小
const int kParkingLotSize = 2;

const int OK = 1;
const int ERROR = 0;
typedef int Status;


// 一个车的信息
typedef struct CarNode
{
    string plate;   // 车牌信息
    int spot;   // 车辆位置
}CarNode, *Car;

// 停车场信息，top和parked_car_num有点重复
typedef struct ParkingLot
{
    CarNode cars[kParkingLotSize];  // 存放车信息的数组，顺序栈操作
    int top;    // 用数组下标，指向栈顶（最后的车的后一位）
    int parked_car_num;     // 统计有多少辆车
}ParkingLot, *Park;

// 初始化停车场，新建个停车场类型的结构体
Status InitParkingLot(Park &P)
{
    P = new ParkingLot;
    P->parked_car_num = 0;
    P->top = 0;
    return OK;
}

// 停车，也就是入栈，给车牌号
Status ParkingCar(Park &P, string &plate)
{
    // 0. 判断停车场有没有满
    if(P->parked_car_num >= kParkingLotSize)
        return ERROR;
    
    // 1. 输入车牌，判断输入有无正确
    if(plate.length() > kPlateNumMaxSize) 
    {
        cout << "您输入的车牌号太长了，不超过" << kPlateNumMaxSize << "位！"<< endl;
        return ERROR;
    }
    else if (plate.length() < 5)
    {
        cout << "您输入的车牌号太短了！要5位以上！" << endl;
        return ERROR;
    }

    // 2. 输入正确后，放入栈（停车场） 
    P->cars[P->top].plate = plate;
    P->cars[P->top].spot = P->parked_car_num;
    P->parked_car_num++;
    P->top++;

    return OK;
}

bool EmptyParkingLot(Park &P)
{
    // 0. 车数量0
    if (P->parked_car_num == 0)
    {
        cout << "停车场没车啦~" << endl;
        return true;
    }
    else return false;
}

Status ShowParkingLot(Park &P)
{
    // 1. 循环输出停车场车辆信息
    int car_spot_i = P->top;    // car 数组下标
    cout << "一共有" << P->parked_car_num << "辆车，停车场车辆位置：" << endl;
    while(--car_spot_i >= 0)
    {
        cout << "位置 " << P->cars[car_spot_i].spot << " 车，车牌： " << P->cars[car_spot_i].plate << endl;
    }

    return OK;
}

Status PopCar(Park &P)
{
    cout << P->cars[P->top-1].spot << " 车，车牌" << P->cars[P->top-1].plate << "出去啦~" << endl;
    P->top--;
    P->parked_car_num--;
    cout << "剩下有" << P->parked_car_num << "辆车" << endl;
    return OK;
}

int main()
{
    Park P;
    InitParkingLot(P);
    
    cout << "[简易停车场管理程序]" << endl;
    cout << "请输入" << kParkingLotSize << "个7字符内车牌号的车：" << endl;

    for(int i=0; i<kParkingLotSize; i++)
    {
        string car_plate;
        cin >> car_plate;
        ParkingCar(P,car_plate);
    }

    ShowParkingLot(P);

    while(!EmptyParkingLot(P))
    {
        PopCar(P);
    }
}