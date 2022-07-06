
#include <iostream>
#include "BatterySensor.hpp"

class displaySensorDataInterface
{
    public:
        virtual void displayDataOnConsole(std::string data)=0;
        virtual std::string displayFormattedData(unsigned int SOC, signed int temp)=0;
};

class displaySensorData:public displaySensorDataInterface
{
    public:
        void displayDataOnConsole(std::string data)
        {
            std::cout<<data<<std::endl;
        }
        
        std::string displayFormattedData(unsigned int SOC, unsigned int temp)
        {
            std::string formattedData;
            formattedData=std::to_string(SOC)+","+std::to_string(temp);
            return formattedData;
        }
};

class mockSensorData:public displaySensorDataInterface
{
    public:
        int displayCounter,formatCounter=0;
        
        void displayDataOnConsole(std::string /*data*/)
        {
            displayCounter++;
        }
        
        std::string displayFormattedData(unsigned int /*SOC*/,unsigned int /*temp*/)
        {
            formatCounter++;
            return "";
        }
};
