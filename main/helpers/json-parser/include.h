#ifndef JSON_H
#define JSON_H

    #include "json.c"

    /*Dumb function for debugging only*/
    void printJson(const char* name, json_value* arr){
        char * buf = malloc(json_measure(arr));
        json_serialize(buf, arr);
        printf("%s:\t%s\n", name, buf);
    }

#endif