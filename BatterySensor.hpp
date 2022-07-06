#include<iostream>
using namespace std;
#include <vector>

#define MIN_TEMP -20
#define MAX_TEMP 60
#define MIN_SOC 20
#define MAX_SOC 80
#define TOTAL_COUNT 100

struct batterySensor
{
    vector<unsigned int> SOCList;
    vector<signed int> tempValueList;
};

template<typename T>
vector<T> generateRandomValues(T min, T max)
{
    vector<T> valueList;
    for(int i=0;i<TOTAL_COUNT;i++)
    {
        T randValue=rand()%(max-min+1)+min;
        valueList.push_back(randValue);
    }
    return valueList;
}

batterySensor getBatteryParameters()
{
    batterySensor batterySensorValues;
    batterySensorValues.SOCList=generateRandomValues<unsigned int>(MIN_SOC,MAX_SOC);
    batterySensorValues.tempValueList=generateRandomValues<signed int>(MIN_TEMP,MAX_TEMP);
    return batterySensorValues;
}

