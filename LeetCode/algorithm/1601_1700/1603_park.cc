/**
 * @author 2mu
 * @date 2024/7/27
 * @brief easy 设计停车系统
 * 
 * 1. 模拟
 * 直接按照规则模拟即可, 逻辑判断使用switch美观一些;
 * 要是哈希表会不会好一点? 估计也差不多, 就是3个选项而已...
 * 
 * 时间复杂度: O(1)
 * 空间复杂度: O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ParkingSystem
{
private:
    int bg;
    int med;
    int sam;

public:
    ParkingSystem(int big, int medium, int small) 
        :bg(big), med(medium), sam(small){
    }
    
    bool addCar(int carType) {
        switch (carType)
        {
        case 1:
            if(this->bg <= 0)
                return false;
            else
                --bg;
            break;
        case 2:
            if(this->med <= 0)
                return false;
            else
                --this->med;
            break;
        case 3:
           if(this->sam <= 0)
                return false;
            else
                --this->sam;
        default:
            break;
        }
        return true;
    }
};

int main()
{
    return 0;
}
