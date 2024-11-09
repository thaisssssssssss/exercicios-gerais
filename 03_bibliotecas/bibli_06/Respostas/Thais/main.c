#include "temperature_conversor.h"
#include <stdio.h>

int main(){
    float temperature;
    char currentTemperature, conversor;

    scanf("%f ", &temperature);
    scanf("%c %c", &currentTemperature, &conversor);

    if(currentTemperature == 'c'){
        if(conversor == 'k'){
            printf("Temperature: %.2fK", convert_celsius_to_kelvin(temperature));
        }
        else if(conversor == 'f'){
            printf("Temperature: %.2fFº", convert_celsius_to_fahrenheit(temperature));
        }
    }
    else if(currentTemperature == 'k'){
        if(conversor == 'c'){
            printf("Temperature: %.2fCº", convert_kelvin_to_celsius(temperature));
        }
        else if(conversor == 'f'){
            printf("Temperature: %.2fFº", convert_kelvin_to_fahrenheit(temperature));
        }
    }
    else if(currentTemperature == 'f'){
        if(conversor == 'c'){
            printf("Temperature: %.2fCº", convert_fahrenheit_to_celsius(temperature));
        }
        else if(conversor == 'k'){
            printf("Temperature: %.2fK", convert_fahrenheit_to_kelvin(temperature));
        }
    }
}