
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#define LENGTH 128

typedef enum 
{
    STR2INT_SUCCESS,
    STR2INT_OVERFLOW,
    STR2INT_UNDERFLOW,
    STR2INT_INCONVERTIBLE
} str2int_errno;

/* Convert string s to int out.
 *
 * @param[out] out The converted int. Cannot be NULL.
 *
 * @param[in] s Input string to be converted.
 *
 *     The format is the same as strtol,
 *     except that the following are inconvertible:
 *
 *     - empty string
 *     - leading whitespace
 *     - any trailing characters that are not part of the number
 *
 *     Cannot be NULL.
 *
 * @param[in] base Base to interpret string in. Same range as strtol (2 to 36).
 *
 * @return Indicates if the operation succeeded, or why it failed.
 */
str2int_errno str2int(int *out, char *s, int base) {
    char *end;
    if (s[0] == '\0' || isspace(s[0]))
        return STR2INT_INCONVERTIBLE;
    errno = 0;
    long l = strtol(s, &end, base);
    /* Both checks are needed because INT_MAX == LONG_MAX is possible. */
    if (l > INT_MAX || (errno == ERANGE && l == LONG_MAX))
        return STR2INT_OVERFLOW;
    if (l < INT_MIN || (errno == ERANGE && l == LONG_MIN))
        return STR2INT_UNDERFLOW;
    if (*end != '\0')
        return STR2INT_INCONVERTIBLE;
    *out = l;
    return STR2INT_SUCCESS;
}

typedef struct parseParams
{
    float p1;
    int p2;
    bool p3;
    bool p4;
    char p5[LENGTH];
    unsigned int p6;
}CmdParameters;

enum ParamterOption 
{
    START,
    MIDDLE,
    END
};
//Initialize cmdParameters
static CmdParameters initialParameters = {.p1 = 0, .p2 = 5, .p3 = false, .p4 = false, .p5 = {0}, .p6 = START};
static void PrintCommandLineOptions()
{
    printf("#########################################################################\n");
    printf("./bin/gnu [options]\n");
    printf("[options]\n");
    printf("[O]\t-f [Parameter #1]\t\tFirst paramter is a floating number.\n");
    printf("[O]\t-s [Parameter #2]\t\tSecond parameter has default value [5].\n");
    printf("[O]\t-t [Parameter #3]\t\tThird parameter has enabling feature [Boolean Type].\n");
    printf("[O]\t-o [Parameter #4]\t\tFourth parameter has enabling feature [Boolean Type].\n");
    printf("[M]\t-i [Parameter #5]\t\tFith parameter is a required string.\n");
    printf("[O]\t-x [Parameter #6]\t\tSixth parameter has a set of options with default value[START].\n");
    printf("[O]\t-h \t\t\t\tShow usage\n");
}

static int CommandLineParser(int argc, char *argv[], CmdParameters *cmdParameters)
{
    int option = 0;
    while((option = getopt(argc, argv, "f:s:toi:x:h")) > 0)
	{
        switch(option) 
		{
            case 'f':
            {   
                char* str_end;
                //convert string to float
                cmdParameters->p1 = (float) strtof(optarg, &str_end);
                //Conversion fail
                if(strcmp(str_end , optarg) == 0)
                {
                    printf("[ERROR][%s] is not a floating number.\n", optarg);
                }   
                break; 
               
            }      
            case 's':
            {    //convert string to int
                if (str2int(&cmdParameters->p2, optarg, 10) != STR2INT_SUCCESS)
                    {//Conversion fail
                        printf("[ERROR][%s] is not an integer.\n", optarg);
                    }
                break;
                
          }
          case 't':
          {     cmdParameters->p3 = true;
                break;
          }
          
          case 'o':
          {     cmdParameters->p4 = true;
                break;
          }
          case 'i':
           {    strncpy(cmdParameters->p5, optarg, sizeof(cmdParameters->p5));
                break;
           }          
         case 'x':
            {   if((strlen(optarg)==strlen("s") && strncmp(optarg, "s", 1) == 0)
                || (strlen(optarg)==strlen("start") && strncmp(optarg, "start", strlen("start")) == 0)) 
                {
                        cmdParameters->p6 = START;
                    } 
                else if((strlen(optarg)==strlen("m") && strncmp(optarg, "m", 1) == 0)
                || (strlen(optarg)==strlen("middle") && strncmp(optarg, "middle", strlen("middle")) == 0)) 
                {
                        cmdParameters->p6 = MIDDLE;
                    } 
                else if((strlen(optarg)==strlen("e") && strncmp(optarg, "e", 1) == 0)
                || (strlen(optarg)==strlen("end") && strncmp(optarg, "end", strlen("end")) == 0)) 
                {
                        cmdParameters->p6 = END;
                } 
                else 
                    {
                    // default parameters[START]

                    }
                break;
            }
          case 'h':
            {  return -1; 
                break; 
            }        
          default:
            {    printf("Unknown option %c\n", option);
                return -1;
                break;
                }
        }
    }
    if(strlen(cmdParameters->p5) == 0)
    {
        printf("Must specify parameter 5\n");
        return -1;

    }
	
  
    return 0;
}

int main(int argc, char *argv[])
{  

	//CmdParameters *cmdParameters = (CmdParameters*)malloc(sizeof *cmdParameters); 
	CmdParameters * cmdParameters = &initialParameters;
	
	    /* Check command line options */
    if(CommandLineParser(argc, argv, cmdParameters) < 0)
	{

        printf("CommandLineParser [ERROR]\n");
        PrintCommandLineOptions();
        return -1;
    }
    else
    {
        printf("[First] parameter is set to [%f]\n", cmdParameters->p1);
        printf("[Second] parameter is set to [%d]\n", cmdParameters->p2);
        printf("[Third] parameter is set to [%s]\n", cmdParameters->p3 ? "true" : "false");
        printf("[Fourth] parameter is set to [%s]\n", cmdParameters->p4 ? "true" : "false");
        printf("[Fith] parameter is set to [%s]\n", cmdParameters->p5);
        printf("[Sixth] parameter is set to [%s]\n", cmdParameters->p6 == START ? "START":(cmdParameters->p6 == MIDDLE ? "MIDDLE":"END"));
    }

	return 0;
}




	