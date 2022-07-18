#ifndef RECEIVER_H
#define RECEIVER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SENSOR_DATA_SIZE 50 

typedef struct 
{
    float minValue;
    float maxValue;
    float average;
    float movingAverage;
}statsData;

float sensor1Data[SENSOR_DATA_SIZE];
float sensor2Data[SENSOR_DATA_SIZE];

void displayStatistics(statsData result);
void getDataFromSender();
float getMinValueFromSensorDataStream(float SensorData[], int streamDataSize);
float getMaxValueFromSensorDataStream(float SensorData[], int streamDataSize);
float calculateAverageValueFromSensorDataStream(float SensorData[], int streamDataSize);
float calculateSimpleMovingAverage(float SensorData[], int entrySize, int lastSampleValue);
statsData computeStatistics(float sensorData[], int streamDataSize, int movingAverageRange);


#endif