#include<iostream>
using namespace std;
#include <vector>

#define MIN_CHARGERATE 0
#define MAX_CHARGERATE 0.8
#define MIN_SOC 20
#define MAX_SOC 80
#define TOTAL_COUNT 60

struct batterySensor
{
    vector<unsigned int> SOCList;
    vector<unsigned int> chargeRateList;
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
    batterySensorValues.chargeRateList=generateRandomValues<unsigned int>(MIN_CHARGERATE,MAX_CHARGERATE);
    return batterySensorValues;
}

