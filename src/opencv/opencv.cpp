#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <stdio.h>
#include <stdlib.h>
enum ParamterOption 
{
    START,
    MIDDLE,
    END
};
int main(int argc, char const *argv[]) 
{
    
   cv::String keys =
        "{f first |11.5   | First paramter is a floating number.}"    
        "{s second |5   | Second parameter has default value [5].}"    
        "{t third |false   | Third parameter has enabling feature [Boolean Type].}"    
        "{o fourth |false   | Fourth parameter has enabling feature [Boolean Type].}"    
        "{i fith |<none>           | Fith parameter is a required string.}"                
        "{x sixth |1           | Sixth parameter has a set of options with default value[1].}"                
        "{help h usage ?    |      | show help message}";      
  
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("./bin/opencv [options]");
    if (parser.has("help")) 
    {
        parser.printMessage();
        return 0;
    }
    bool hasFith = parser.has("fith");
    cv::String fith = parser.get<cv::String>("fith"); 
    float first = parser.get<float>("first"); 
    int second = parser.get<int>("second"); 
    bool third = parser.get<bool>("third"); 
    bool fourth = parser.get<bool>("fourth"); 
    int sixth = parser.get<int>("sixth"); 
 
    if (!parser.check()) 
    {
        parser.printErrors();
        return -1;
    }

unsigned int fourthDef = START;
switch (sixth)
{
    case 1:
        fourthDef = START;
        break;
    case 2:
        fourthDef = MIDDLE;
        break;
    case 3:
        fourthDef = END;
        break;

    default:
        fourthDef = START;
        break;
}

        printf("[First] parameter is set to [%f]\n", first);
        printf("[Second] parameter is set to [%d]\n", second);
        printf("[Third] parameter is set to [%s]\n", third ? "true" : "false");
        printf("[Fourth] parameter is set to [%s]\n", fourth ? "true" : "false");
        printf("[Fith] parameter is set to [%s]\n", fith.c_str());
        printf("[Sixth] parameter is set to [%s]\n", fourthDef == START ? "START":(fourthDef == MIDDLE ? "MIDDLE":"END"));


    return 0;
}