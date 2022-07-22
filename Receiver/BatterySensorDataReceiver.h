#ifndef RECEIVER_H
#define RECEIVER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SENSOR_DATA_SIZE 100 

typedef struct 
{
    float minValue;
    float maxValue;
    float average;
    float movingAverage;
}statsData;


void displayStatistics(statsData result);
void getDataFromSender();
float getMinValueFromSensorDataStream(float SensorData[], int streamDataSize);
float getMaxValueFromSensorDataStream(float SensorData[], int streamDataSize);
float calculateAverageValueFromSensorDataStream(float SensorData[], int streamDataSize);
float calculateSimpleMovingAverage(float SensorData[], int entrySize, int lastSampleValue);
statsData computeStatistics(float sensorData[], int streamDataSize, int movingAverageRange);


#endif

