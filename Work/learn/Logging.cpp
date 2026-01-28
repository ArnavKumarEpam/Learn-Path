#include<iostream>
#include "logger.h"

int main(){
    LOG(LOG_ERROR, "This is an error message.");
    LOG(LOG_WARN, "This is a warning message.");
    LOG(LOG_INFO, "This is an info message.");
    LOG(LOG_DEBUG, "This is a debug message.");
    return 0;
}