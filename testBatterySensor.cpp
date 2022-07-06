#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "BatterySensorDataSender.hpp"

TEST_CASE("Test the generation of the sensor values")
{
    batterySensor batterySensorValues=getBatteryParameters();

    REQUIRE(batterySensorValues.SOCList.size()==100);
    for(int i=0;i<100;i++)
    {
        REQUIRE(20<=batterySensorValues.SOCList[i]);
        REQUIRE(batterySensorValues.SOCList[i]<=80);
    }
    REQUIRE(batterySensorValues.tempValueList.size()==100);
    for(int i=0;i<100;i++)
    {
        REQUIRE(-20<=batterySensorValues.tempValueList[i]);
        REQUIRE(batterySensorValues.tempValueList[i]<=60);
    }
}

TEST_CASE("Test if the battery data is displaying on the console")
{
  batterySensor batterySensorValues=getBatteryParameters();
  mockSensorData mockSensorDataInstance;
  displayBatterSensorValues(batterySensorValues,mockSensorDataInstance);
  REQUIRE(mockSensorDataInstance.displayCounter==100);
  REQUIRE(mockSensorDataInstance.formatCounter==100);
}


TEST_CASE("Test where data is sent to receiver")
{
    displaySensorData actualSensorData;
    bool output=true;
    REQUIRE(sendBatteryParameters(actualSensorData)==output);
}

TEST_CASE("Test where data is sent to receiver through mock data")
{
    mockSensorData mockSensorDataInstance;
    bool output=true;
    REQUIRE(sendBatteryParameters(mockSensorDataInstance)==output);
    REQUIRE(mockSensorDataInstance.displayCounter==100);
    REQUIRE(mockSensorDataInstance.formatCounter==100);
}
