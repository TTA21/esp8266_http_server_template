#ifndef INCLUDES_H
#define INCLUDES_H

///Libraries

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "esp_netif.h"
#include "esp_event.h"
#include "protocol_examples_common.h"
#include "nvs.h"
#include "nvs_flash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <dirent.h>

#include "esp_err.h"
#include "esp_spiffs.h"
#include "esp_log.h"

#include <esp_http_server.h>

///Static data
#include "statics.c"

///Helpers
#include "helpers/c-vector/include.h"
#include "helpers/json-parser/include.h"
#include "helpers/spiff/include.h"

///Data permanency
#include "permanence.c"

///Http route definitions
#include "route_declarations/routes.h"

///Common server handlers
#include "server_intrinsics/base_server_handlers.c"
#include "server_intrinsics/get_requests.c"





#endif