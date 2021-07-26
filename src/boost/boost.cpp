#include <boost/program_options.hpp>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace boost;
namespace po = boost::program_options;
enum ParamterOption 
{
    START,
    MIDDLE,
    END
};

int main(int argc, char const *argv[])
{

 
    std::string fith; 
    float first = 0; 
    int second = 0; 
    bool third = false; 
    bool fourth = false; 
    int sixth = 0; 
	// command parser
	try 
		{
			po::options_description desc("./bin/boost [options]");
			desc.add_options()
				("help,h", "Show usage")
				("first,f", po::value<float>(),"First paramter is a floating number.")
				("second,s", po::value<int>(&second)->default_value(5),"Second parameter has default value [5].")
				("third,t", po::value<bool>(&third)->implicit_value(true)->default_value(false),"Third parameter has enabling feature [Boolean Type].")
				("fourth,o", po::value<bool>(&fourth)->implicit_value(true)->default_value(false),"Fourth parameter has enabling feature [Boolean Type].")
				("fith,i", po::value<std::string>(),"Fith parameter is a required string.")
				("sixth,x", po::value<int>(&sixth)->default_value(START),"Sixth parameter has a set of options with default value[START].");	
			po::variables_map vm;        
			po::store(po::parse_command_line(argc, argv, desc), vm);
			po::notify(vm);  

			if (vm.count("help")) 
			{
				std::cout<< desc;
				return 0;
			}
 			if (vm.count("first") ) 
        	{

                first =  vm["first"].as<float>();
        	} 
        	else 
       		{
            	std::cout << "First parameter was not set.\n";
				return -1;
        	}  			
            if (vm.count("fith") ) 
        	{

                fith =  vm["fith"].as<std::string>();
        	} 
        	else 
       		{
            	std::cout << "Fith parameter was not set.\n";
				return -1;
        	}            
		}
		catch(std::exception& e)
		{
			std::cout << e.what() <<"\n"; 
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
