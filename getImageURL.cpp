/* \fbox{The following is very similar to the getImage file,}
\fbox{but it returns the URL instead of just performing a void function} */
#include <stdio.h>
#include <curl/curl.h>
#include "mashape.h"

size_t handleData(char* p, size_t s, size_t n, std::string* u)
{
    *u += p;
    return s * n; 
}

std::string getImageURL(std::string k)
{
    CURL *curl;
    CURLcode res;
    std::string s = "gif: ";
    
    std::string r = url + api + "&q=" + k + "&limit=1";

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
/* \newpage */
    if(curl)
    {
        curl_easy_setopt(curl,
                         CURLOPT_URL, r.c_str());

        curl_easy_setopt(curl,
                         CURLOPT_WRITEFUNCTION, handleData);

        curl_easy_setopt(curl,
                         CURLOPT_WRITEDATA, &s);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return s;
}
