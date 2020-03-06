#include <string>
/*This parseJson is based on how the urls were originally printing in 
the terminal before they were parsed. Each one had a beginning in common
and could pretty reliably be divided into separate urls based on those 
beginning statements. By finding the start and end of the urls 
and the characters we wanted to remove, the program is able to parse 
the url we want.*/
std::string parseJson(std::string j)
{
    std::string header = "\"original\":{\"url\":\"" ;
    int first = j.find(header); int last = j.find(".gif", first + 1);
    int length = last - first + 4 - header.length();
    
    j = j.substr(first + header.length(),length);
    std::string url = "";
    
    for (int i = 0; i < j.length(); ++i) {
		if (j[i] != '\\'){
		  url += j[i];
	  }
    }
    return url;
}
