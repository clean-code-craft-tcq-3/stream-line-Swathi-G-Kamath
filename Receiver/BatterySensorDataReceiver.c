#include "BatterySensorDataReceiver.h"


int sensor1Data[SENSOR_DATA_SIZE];
int sensor2Data[SENSOR_DATA_SIZE];

void getDataFromSender()
{
    for (int dataStreamInterator = 0 ; dataStreamInterator < SENSOR_DATA_SIZE ; dataStreamInterator++)
    {
        scanf("%d,%d\n", &sensor1Data[dataStreamInterator], &sensor2Data[dataStreamInterator]);
    }
}

int getMinValueFromSensorDataStream(int SensorData[], int streamDataSize)
{
    int min = SensorData[0];
    for (int minValueIter = 0; minValueIter < streamDataSize; minValueIter++)
    {
        min = (min < SensorData[minValueIter]) ? min : SensorData[minValueIter];
    }
    return min;
}

int getMaxValueFromSensorDataStream(int SensorData[], int streamDataSize)
{
    int max = SensorData[0];
    for (int maxValueIter = 0; maxValueIter < streamDataSize; maxValueIter++)
    {
        max = (max > SensorData[maxValueIter]) ? max : SensorData[maxValueIter];
    }
    return max;
}

float calculateAverageValueFromSensorDataStream(int SensorData[], int streamDataSize)
{
    float average = 0;
    for (int averValueIter = 0; averValueIter < streamDataSize; averValueIter++)
    {
        average = average + float(SensorData[averValueIter]);
    }
    return (average/streamDataSize);
}

float calculateSimpleMovingAverage(float SensorData[], int streamDataSize, int lastSampleValue)
{
    float simpleMovingAver = 0;
    for(int simpleMovAverIter = (streamDataSize - lastSampleValue); simpleMovAverIter < streamDataSize; simpleMovAverIter++)
    {
        simpleMovingAver = simpleMovingAver + float(SensorData[simpleMovAverIter]);
    }
    return (simpleMovingAver/lastSampleValue);
}

void displayStatistics(statsData result)
{
    
    printf("\n***************************\nMIN_VALUE      = %d\nMAX_VALUE      = %d\nAVERAGE_VALUE  = %f\nMOVING_AVERAGE = %f\n***************************\n", result.minValue, result.maxValue, result.average, result.movingAverage);
}

statsData computeStatistics(int sensorData[], int streamDataSize, int movingAverageRange)
{
    statsData result;
    result.minValue = getMinValueFromSensorDataStream(sensorData, streamDataSize);
    result.maxValue = getMaxValueFromSensorDataStream(sensorData, streamDataSize);
    result.average = calculateAverageValueFromSensorDataStream(sensorData, streamDataSize);
    result.movingAverage = calculateSimpleMovingAverage(sensorData, streamDataSize, movingAverageRange);
    return result;
}

int main()
{
    statsData result, result1;
    getDataFromSender();
    printf("Received data from Sender \n ");
    for (int dataStreamInterator = 0 ; dataStreamInterator < SENSOR_DATA_SIZE ; dataStreamInterator++)
    {
        printf("%d,%d\n", sensor1Data[dataStreamInterator], sensor2Data[dataStreamInterator]);
    }
    result = computeStatistics(sensor1Data, SENSOR_DATA_SIZE, 5);
    displayStatistics(result);
    result1 = computeStatistics(sensor2Data, SENSOR_DATA_SIZE, 5);
    displayStatistics(result1);
    
    return 0;
}

