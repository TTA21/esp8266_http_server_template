#ifndef ROUTES_H
#define ROUTES_H

#include "root_get.c"
#include "hello_get.c"
#include "echo_post.c"
#include "ctrl_put.c"

static json_value* global_json;

void register_routes(httpd_handle_t server){
    global_json = json_parse("[]", strlen("[]"));

    httpd_register_uri_handler(server, &root);
    httpd_register_uri_handler(server, &hello);
    httpd_register_uri_handler(server, &echo);
    httpd_register_uri_handler(server, &ctrl);
}

#endif