#define CATCH_CONFIG_MAIN 

#include "catch.hpp"
#include "Receiver/BatterySensorDataReceiver.h"

#define TEST_ENV 

#ifdef TEST_ENV

SCENARIO("Get Sensor values from Sender part and get some statistics related data from it ")
{
    GIVEN("The Sensor Stream Data from sender is received from console")
    {	
	    int Sensor1[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99};
		int Sensor2[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99};
	    int noOfSensor1Sample = 100;
	    int noOfSensor2Sample = 100 ;
		float expectedMovAverageSensor1 = 5.325000 ;
		float expectedMovAverageSensor2 = 8.050000 ;
		int expectedMinSensor1 = 0 ;
		int expectedMaxSensor1 = 99 ;
		int expectedMinSensor2  = 0 ;
		int expectedMaxSensor2  = 99 ;
        float expectedAverageSensor1 = 5.645714;
        float expectedAverageSensor2 = 16.714285;
     	int entrySize = 2;
        statsData result1, result2;
        WHEN("Data is available from the sensor")
        {
            getDataFromSender();
            THEN("extract statistics data from the stream sensor data")
            {
		    REQUIRE( getMinValueFromSensorDataStream(Sensor1, noOfSensor1Sample) == expectedMinSensor1 );
		    REQUIRE( getMinValueFromSensorDataStream(Sensor2, noOfSensor2Sample) == expectedMinSensor2);

            REQUIRE( getMaxValueFromSensorDataStream(Sensor1, noOfSensor1Sample) == expectedMaxSensor1 );
		    REQUIRE( getMaxValueFromSensorDataStream(Sensor2, noOfSensor2Sample) == expectedMaxSensor2);

            REQUIRE( calculateAverageValueFromSensorDataStream(Sensor1, noOfSensor1Sample) == expectedAverageSensor1 );
		    REQUIRE( calculateAverageValueFromSensorDataStream(Sensor2, noOfSensor2Sample) == expectedAverageSensor2);

            REQUIRE( calculateSimpleMovingAverage(Sensor1, noOfSensor1Sample, entrySize) == expectedMovAverageSensor1 );
		    REQUIRE( calculateSimpleMovingAverage(Sensor2, noOfSensor2Sample, entrySize) == expectedMovAverageSensor2);

            result1 = computeStatistics(Sensor1, noOfSensor1Sample, entrySize);
            result2 = computeStatistics(Sensor2, noOfSensor2Sample, entrySize);

            displayStatistics(result1);
            displayStatistics(result2);



            }
	    
        }
    }
}
#endif
