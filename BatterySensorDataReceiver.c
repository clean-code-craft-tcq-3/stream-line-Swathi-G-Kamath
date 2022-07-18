#include "BatterySensorDataReceiver.h"


float sensor1Data[SENSOR_DATA_SIZE];
float sensor2Data[SENSOR_DATA_SIZE];

void getDataFromSender()
{
    for (int dataStreamInterator = 0 ; dataStreamInterator < SENSOR_DATA_SIZE ; dataStreamInterator++)
    {
        scanf("%f,%f\n", &sensor1Data[dataStreamInterator], &sensor2Data[dataStreamInterator]);
    }
}

float getMinValueFromSensorDataStream(float SensorData[], int streamDataSize)
{
    float min = SensorData[0];
    for (int minValueIter = 0; minValueIter < streamDataSize; minValueIter++)
    {
        min = (min < SensorData[minValueIter]) ? min : SensorData[minValueIter];
    }
    return min;
}

float getMaxValueFromSensorDataStream(float SensorData[], int streamDataSize)
{
    float max = SensorData[0];
    for (int maxValueIter = 0; maxValueIter < streamDataSize; maxValueIter++)
    {
        max = (max > SensorData[maxValueIter]) ? max : SensorData[maxValueIter];
    }
    return max;
}

float calculateAverageValueFromSensorDataStream(float SensorData[], int streamDataSize)
{
    float average = 0;
    for (int averValueIter = 0; averValueIter < streamDataSize; averValueIter++)
    {
        average = average + SensorData[averValueIter];
    }
    return (average/streamDataSize);
}

float calculateSimpleMovingAverage(float SensorData[], int streamDataSize, int lastSampleValue)
{
    float simpleMovingAver = 0;
    for(int simpleMovAverIter = (streamDataSize - lastSampleValue); simpleMovAverIter < streamDataSize; simpleMovAverIter++)
    {
        simpleMovingAver = simpleMovingAver + SensorData[simpleMovAverIter];
    }
    return (simpleMovingAver/lastSampleValue);
}

void displayStatistics(statsData result)
{
    
    printf("\n***************************\nMIN_VALUE      = %f\nMAX_VALUE      = %f\nAVERAGE_VALUE  = %f\nMOVING_AVERAGE = %f\n***************************\n", result.minValue, result.maxValue, result.average, result.movingAverage);
}

statsData computeStatistics(float sensorData[], int streamDataSize, int movingAverageRange)
{
    statsData result;
    result.minValue = getMinValueFromSensorDataStream(sensorData, streamDataSize);
    result.maxValue = getMaxValueFromSensorDataStream(sensorData, streamDataSize);
    result.average = calculateAverageValueFromSensorDataStream(sensorData, streamDataSize);
    result.movingAverage = calculateSimpleMovingAverage(sensorData, streamDataSize, movingAverageRange);
    return result;
}

