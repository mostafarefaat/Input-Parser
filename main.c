#include "arg_parser.h"

int count = 0;
char *msg = NULL;

void _msg(void *m)
{
    msg = (char *)m;
    printf("The Message is: %s\n",msg);
    
}

void _count(void *c)
{
    count = atoi((char *) c);
    printf("The Count is: %d\n",count);
       
}

struct Option options[] = {

    {'m', "msg", "The message to be printed", _msg},
    {'c', "count", "How many times to print the message", _count},
    {0},

};
int main(int argc, char * argv[]){
    
    arg_parse(options,argc,argv);
    printf("The Output is:\n");
    for(int i = 0; i < count; i++){
        printf(" %s\n",msg);
    }
    return 0;
}