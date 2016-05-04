/*************************************************************************
 * filename: "OI_dynapro.cpp"
 * purpose : Identifies Microtouch controller
 * description: Comm with controller. It takes one argument as a firmware commnad. 
 *          Returns 0 when controller executes the command successfully.  
 *          It would be used in FPTS image software init scripts to help X to load 
 *          with the appropiate config file.
 *          
 * author: Aliosha Gonzalez    04/30/2014 
 * **********************************************************************/

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
        //test for one argument provided 
        if (argc != 2)
        {
                printf("One argument must be provided. Program abort!!!!\n");
                exit(EXIT_FAILURE);
        }

        std::string dataStr = "";
        //add header
        dataStr += static_cast<char>(1);        //<SOH>
        //add argument
        
        //printf("%s\n", argv[1]);

        //if (*argv[1] == (char *) "OI")
        //{
        //        printf("\nyes");
        //        ****************************************************************************
                dataStr += static_cast<char>(79);   //ASCII <O>
                dataStr += static_cast<char>(73);   //ASCII <I>
              //  dataStr += static_cast<char>(82);   //ASCII <R>
             //   dataStr += static_cast<char>(79);   //ASCII <O>
                
        //************************************************************************************        
        //};
        //add terminator
        dataStr += static_cast<char>(13);   //<CR>
        
        FILE *out_serial;
        out_serial =fopen("/dev/ttyS3", "w");
        
        if (out_serial == NULL)
        {
                printf("Can't not open serial\n");
                exit(1);
        }else
        {
                char *charMessage = (char *) dataStr.c_str();
                fprintf(out_serial, "%s", charMessage);
                printf("%s", (char *)dataStr.c_str());
        }
        
        //printf("%s\n", (char *)dataStr.c_str());
        
        fclose(out_serial);
        return 0;
}
