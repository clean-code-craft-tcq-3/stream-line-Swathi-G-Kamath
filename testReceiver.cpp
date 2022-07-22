#define CATCH_CONFIG_MAIN 

#include "catch.hpp"
#include "Receiver/BatterySensorDataReceiver.h"

#define TEST_ENV 

#ifdef TEST_ENV

SCENARIO("Get Sensor values from Sender part and get some statistics related data from it ")
{
    GIVEN("The Sensor Stream Data from sender is received from console")
    {	
	    float Sensor1[] = {1.0, 22.0, 1.55, 3.67, 0.65, 0.98, 9.67};
		float Sensor2[] = {22.0, 10.0, 15.5, 16.7, 36.7, 6.5, 9.6};
	    int noOfSensor1Sample = 7;
	    int noOfSensor2Sample = 7 ;
		float expectedMovAverageSensor1 = 5.325000 ;
		float expectedMovAverageSensor2 = 8.050000 ;
		float expectedMinSensor1 = 0.650000 ;
		float expectedMaxSensor1 = 22.000000 ;
		float expectedMinSensor2  = 6.500000 ;
		float expectedMaxSensor2  = 36.700001 ;
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
