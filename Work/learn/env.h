#ifndef ENV_H
#define ENV_H

#if defined(DEV) // checks whether the DEV macro is defined
    #define API_URL "http://localhost"
#elif defined(TEST) // checks whether the TEST macro is defined
    #define API_URL "http://test-server"
#else // if neither DEV nor TEST is defined, it defaults to production
    #define API_URL "http://prod-server"
#endif
#endif