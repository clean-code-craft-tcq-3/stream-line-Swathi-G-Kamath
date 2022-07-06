#include "BatterySensorDataDisplay.hpp"

void displayBatterSensorValues(batterySensor batterySensorValues,displaySensorDataInterface &displaySensorDataInstance)
{
    for(int i=0;i<TOTAL_COUNT;i++)
    {
        std::string formattedSensorData=displaySensorDataInstance.displayFormattedData(batterySensorValues.SOCList.at(i),batterySensorValues.chargeRateList.at(i));
        displaySensorDataInstance.displayDataOnConsole(formattedSensorData);
    }
}

bool sendBatteryParameters(displaySensorDataInterface &displaySensorDataInstance)
{
    batterySensor batterySensorValues=getBatteryParameters();
    if(batterySensorValues.SOCList.empty()||batterySensorValues.chargeRateList.empty())
    {
        return false;
    }
    displayBatterSensorValues(batterySensorValues,displaySensorDataInstance);
    return true;
}
