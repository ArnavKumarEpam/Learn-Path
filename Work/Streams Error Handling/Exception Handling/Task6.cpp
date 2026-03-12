#include<iostream>
#include <cstring>
#include <ctime>

class MedicalMemoryTracker{
    public:
    static int totalMemAllocated;
    static int totalMemDeallocated;
    MedicalMemoryTracker(){
        
    }
    static void recordAllocation(const char* medicalResource, int size){
        totalMemAllocated += size;
        std::cout<<"Memory Allocated in recordAllocation function! "<<std::endl;
    }
    static void recordDeallocation(const char* medicalResource, int size){
        totalMemDeallocated += size;
        std::cout<<"Memory got deallocated in recordDeallocation! "<<std::endl;
    }
    static bool reportLeak(){
        if(totalMemAllocated - totalMemDeallocated == 0) return false;
        return true;
    }
    static void reset(){
        totalMemAllocated = 0;
        totalMemDeallocated = 0;
    }
};

int MedicalMemoryTracker::totalMemAllocated = 0;
int MedicalMemoryTracker::totalMemDeallocated = 0;

class MedicalDeviceException : public std::runtime_error{
    std::string message;
    public:
    MedicalDeviceException(std::string message) : std::runtime_error(message), message(message){}

};

class PatientDataException : public std::runtime_error{
    std::string message;
    public:
    PatientDataException(std::string message) : std::runtime_error(message), message(message){}

};

class PatientVitalMonitor {
    private:

        int * heartRateData; //  (int pointer) - for heart rate monitoring
        float * bloodPressureData; // (float pointer) - for BP monitoring
        bool deviceConnected; // (bool) - device status
        char *patientId; // (char array)
    public:
        PatientVitalMonitor(const char *Id){
            heartRateData = nullptr;
            bloodPressureData = nullptr;
            deviceConnected = false;
            patientId = new char[strlen(Id) + 1];
            strcpy(patientId, Id);
            heartRateData = new int[36000];
            MedicalMemoryTracker::recordAllocation("Heart Rate Buffer", 36000 * sizeof(int));
            bloodPressureData = new float[18000];
            MedicalMemoryTracker::recordAllocation("Blood Pressure Buffer", 18000 * sizeof(float));
            connecToMedicalDevice();
            calibrateSensors();
        }
        void connecToMedicalDevice(){
            if (rand() % 2 == 0) {
                throw MedicalDeviceException("E303: Corrupted medical device detected!");
            }
        }
        void calibrateSensors(){
            if (rand() % 2 == 0) {
                throw PatientDataException("E303: Corrupted vital signs detected while calibrating sensors!");
            }
        }
        void validatePatientData(){
            
            if (rand() % 2 == 0) {
                throw PatientDataException("E303: Corrupted vital signs detected while validating patient data!");
            }
        
        }
        void analyzeCriticalTrend(){
            if (rand() % 2 == 0) {
                throw PatientDataException("E303: Corrupted vital signs detected while analyzing critical trend!");
            }
        }
        void monitorPatientVitals(int durationMinutes){
            if (durationMinutes <= 0) {
                throw std::invalid_argument("E001: Monitoring duration must be positive! \n");
            }
            float *ecgAnalysisBuffer = new float[5000];
            MedicalMemoryTracker::recordAllocation("ECG Analysis Buffer Allocation", 5000 * sizeof(float));
            validatePatientData();
            int *criticalTrendBuffer = new int[1000];
            MedicalMemoryTracker::recordAllocation("Critical Trend BufferAllocation", 1000 * sizeof(int));
            analyzeCriticalTrend();

            delete[] ecgAnalysisBuffer;
            MedicalMemoryTracker::recordDeallocation("ECG Buffer Deallocation", 5000 * sizeof(float));
            delete[] criticalTrendBuffer;
            MedicalMemoryTracker::recordDeallocation("Critical Trend Buffer Deallocation", 1000 * sizeof(int));

            
        }
        ~PatientVitalMonitor(){
            std::cout<<"Destructor called\n";
            delete[] patientId;
            if(heartRateData) {
                delete[](heartRateData);
                MedicalMemoryTracker::recordDeallocation("Heart Rate Buffer", 36000 * sizeof(int));
            }
            if(bloodPressureData) {
                delete[](bloodPressureData);
                MedicalMemoryTracker::recordDeallocation("Blood Pressure Buffer", 18000 * sizeof(float));
            }
        }
};

int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    int n;
    std::cout<<"Enter the number of Attempts (5-10): ";
    std::cin>>n;
    MedicalMemoryTracker::reset();
    PatientVitalMonitor * emergencyMonitor = nullptr;
    bool setupSuccessfull = false;
    while(n){
        setupSuccessfull = false;
        emergencyMonitor = nullptr;
        try{
            emergencyMonitor = new PatientVitalMonitor("EMERGENCY-001");
            if(emergencyMonitor){
                setupSuccessfull = true;
                std::cout<<"Object created Successfully! "<<std::endl;

            }
            else throw MedicalDeviceException("Unsuccessfull! \n");

        }
        catch(const MedicalDeviceException &e){
            std::cout<<"Medical Device Exception: "<<e.what();
        }
        if (setupSuccessfull && emergencyMonitor){
            try{
                emergencyMonitor -> monitorPatientVitals(10);
            }
            catch (const PatientDataException& e){
                std::cout<<e.what();
            }
            catch(const std::invalid_argument &e){
                std::cout<<e.what();
            }
        }
        delete emergencyMonitor;
        if(MedicalMemoryTracker::reportLeak()){
            std::cout<<"Memory Leak Identified! \n";
        }
        else std::cout<<"No Memory Leak Detected! \n";
        n--;
    }
}