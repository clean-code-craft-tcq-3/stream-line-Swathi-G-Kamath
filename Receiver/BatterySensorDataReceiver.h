#ifndef RECEIVER_H
#define RECEIVER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SENSOR_DATA_SIZE 100 

typedef struct 
{
    int minValue;
    int maxValue;
    float average;
    float movingAverage;
}statsData;


void displayStatistics(statsData result);
void getDataFromSender();
int getMinValueFromSensorDataStream(int SensorData[], int streamDataSize);
int getMaxValueFromSensorDataStream(int SensorData[], int streamDataSize);
float calculateAverageValueFromSensorDataStream(int SensorData[], int streamDataSize);
float calculateSimpleMovingAverage(int SensorData[], int entrySize, int lastSampleValue);
statsData computeStatistics(int sensorData[], int streamDataSize, int movingAverageRange);


#endif

