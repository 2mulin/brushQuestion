/********************************************************************************************
 * @author reddragon
 * @date 2021/3/19
 * @brief easy 设计停车系统
 * 
 * 1. 模拟
 * 非常简单, 不说思路了
 * 时间复杂度: O(1)     空间复杂度: O(1)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ParkingSystem {
private:
    int bg;
    int med;
    int sam;
public:
    ParkingSystem(int big, int medium, int small) 
        :bg(big), med(medium), sam(small){
        
    }
    
    bool addCar(int carType) {
        if(carType == 1)
        {
            if(bg <= 0)
                return false;
            else
             --bg;
        }else if(carType == 2)
        {
            if(med <= 0)
                return false;
            else
                --med;
        }
        else
        {
            if(sam <= 0)
                return false;
            else
                --sam;
        }
        return true;
    }
};

int main()
{
    return 0;
}
