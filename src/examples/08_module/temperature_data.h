//temperature_data.h
#include<fstream>
#include "temperature.h"
#include<vector>
#include<string>
#ifndef TEMPERATURE_DATA_H
#define TEMPERATURE_DATA_H

class TemperatureData
{
    public:
        void save_temps(std::vector<Temperature>& ts);
        std::vector<Temperature> get_temps() const;
    
    private:
        const std::string file_name{"temperature.dat"};  

};

#endif