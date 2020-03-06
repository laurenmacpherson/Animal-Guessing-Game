#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include "mashape.h"

/* handleData is a callback function to get the picture */
size_t handleData(char* p, size_t s, size_t n, std::ofstream* u)
{
    u->write(p,s*n);
    return s * n; 
    /*If this returns zero, it means there's nothing else to receive*/
}

void getImage(std::string u)
{
    CURL *curl;
    CURLcode res;
    std::ofstream ofs("animal.gif", std::ios::binary);
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, u.c_str());
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handleData);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ofs);

        /* res = the return code*/
        res = curl_easy_perform(curl);

        /* print out an error statement if it fails */
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}
