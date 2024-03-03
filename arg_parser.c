#include "arg_parser.h"



struct Option help = {'h',"help","Shows all supported commands",_help};

static struct Option * _find_option_by_shortname(struct Option *options, char shortname)
{
    struct Option * op = options;
    if(shortname == 'h'){
        return &help;
    }
    while(op->shortname != 0){
        if(op->shortname == shortname){
            return op;
        }
        op++;
    }
    return NULL;

}
static struct Option * _find_option_by_longname(struct Option *options, char * longname)
{
    struct Option * op = options;
    if(!strcmp(longname,"help")){
        return &help;
    }
    while(op->shortname != 0){
        if(!strcmp(op->longname,longname)){
          
            return op;
        }
        op++;
    }
    return NULL;
}

void _help(void *h)
{
    struct Option * op = (struct Option *) h;
    while(op->shortname != 0){
        printf("-%c, --%s, %s\n",op->shortname,op->longname,op->description);
        op++;
    }    
}

void arg_parse(struct Option *options, int argc, char *argv[])
{
    for(int i = 1; i < argc; i++){

        struct Option * op = NULL;

        if(argv[i][0] == '-'){
            if(argv[i][1] == '-'){
                op = _find_option_by_longname(options,&argv[i][2]);
            }
            else{
                op = _find_option_by_shortname(options,argv[i][1]);    
            }
            if(op == &help){
                op->action((void *)options);
            }
            else if(op != NULL){
                if((i <= argc-2) && (argv[i+1][0] != '-')){
                    op->action((void *) argv[i+1]);       
                    i++;
                }
                else{
                    op->action(NULL);      
                }
            }
            else{
                printf("Sorry this command is not supported !..\n");
            }
        }
        else{
            printf("Sorry this command is not valid !..\n");
        }
    }
}