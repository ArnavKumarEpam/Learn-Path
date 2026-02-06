#include <stdio.h> // Preprocessor gets instruction to use stdio.h for input/output

/* Function to take input from the user */
  
void inputData(
    char *sensorRegion,
    int *readingId,
    float *avgSoilMoisture,
    double *lightIntensity,
    short *temperatureCelsius,
    long *totalReadings,
    unsigned int *uploadThreshold,
    unsigned char *sensorMode
) {
    printf("Enter sensor region (N/S/E/W): ");
    scanf(" %c", sensorRegion);
  
    /*Validation check whether the direction is valid or not*/
    if(*sensorRegion != 'N' &&
        *sensorRegion != 'S' &&
        *sensorRegion != 'E' && 
        *sensorRegion != 'W'){
            printf("Invalid Region! selecting N as default \n");
            *sensorRegion = 'N'; // Selecting direction as N if not valid
        }

    printf("Enter reading ID: ");
    scanf("%d", readingId);

    printf("Enter average soil moisture (%%): ");
    scanf("%f", avgSoilMoisture);

    printf("Enter light intensity (lumens): ");
    scanf("%lf", lightIntensity);

    printf("Enter temperature (Celsius): ");
    scanf("%hd", temperatureCelsius);

    printf("Enter total readings collected: ");
    scanf("%ld", totalReadings);

    printf("Enter upload threshold: ");
    scanf(" %u", uploadThreshold);
    

    printf("Enter sensor mode (1 = Active, 0 = Idle): ");
    scanf("%hhu", sensorMode);
}

/* Function to display the output */

void displayData(
    char sensorRegion,
    int readingId,
    float avgSoilMoisture,
    double lightIntensity,
    short temperatureCelsius,
    long totalReadings,
    unsigned int uploadThreshold,
    unsigned char sensorMode
) {
    printf("\nEnvironmental Data Logger Configuration\n"); // heading
    printf("--------------------------------------\n");

    printf("Sensor Region           : %c region\n", sensorRegion);
    printf("Current Reading ID      : %d\n", readingId);
    printf("Average Soil Moisture   : %.2f %%\n", avgSoilMoisture);
    printf("Light Intensity         : %.2lf lumens\n", lightIntensity);
    printf("Temperature             : %hd °C\n", temperatureCelsius);
    printf("Total Readings Collected: %ld readings\n", totalReadings);
    printf("Upload Threshold        : %u readings\n", uploadThreshold);

    if (sensorMode == 1)
        printf("Sensor Mode             : Active (0x%02X)\n", sensorMode);
    else
        printf("Sensor Mode             : Idle (0x%02X)\n", sensorMode);
}


int main() {
    /* Declaration of Variables */
    
    char sensorRegion; // Region of the sensor (N/S/E/W)
    int readingId; // Unique id of current reading
    float avgSoilMoisture; // Average Soil Moisture percentage
    double lightIntensity; // Light intensity in lumens
    short temperatureCelsius; // Temerature in degree celsius
    long totalReadings; // Total readings collected
    unsigned int uploadThreshold; // Uploaded threshold
    unsigned char sensorMode; // Sensor mode (Active/Idle)

    /* Function to take input from the user */
  
    inputData(
        &sensorRegion,
        &readingId,
        &avgSoilMoisture,
        &lightIntensity,
        &temperatureCelsius,
        &totalReadings,
        &uploadThreshold,
        &sensorMode
    );
    
    /* Function to display the sensor configurations */
    
    displayData(
        sensorRegion,
        readingId,
        avgSoilMoisture,
        lightIntensity,
        temperatureCelsius,
        totalReadings,
        uploadThreshold,
        sensorMode
    );

    return 0;
}
