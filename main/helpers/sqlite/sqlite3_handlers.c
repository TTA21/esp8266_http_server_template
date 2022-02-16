#include "esp_log.h"
#include "esp_err.h"
#include "../../statics.c"
static int callback(void *rows, int argc, char **argv, char **azColName) {
    json_value* row = json_object_new(0);
    for (int i = 0; i<argc; i++){
        json_object_push(row, azColName[i], json_string_new(argv[i] ? argv[i] : "NULL"));
    }
    if(rows != NULL)
        json_array_push((json_value*)rows, row);
    return 0;
}

int db_open(const char *filename, sqlite3 **db) {
    const char* THIS_TAG = "db_open";
    int rc = sqlite3_open(filename, db);
    if (rc) {
        ESP_LOGE(THIS_TAG, "Can't open database: %s\n", sqlite3_errmsg(*db));
        return rc;
    }else{
        ESP_LOGI(THIS_TAG, "Opened [%s] database successfully", filename);
    }
    return rc;
}

int db_exec(sqlite3 *db, const char *sql, json_value* rows, bool verbose) {
    const char* THIS_TAG = "db_exec";
    if(verbose)
        ESP_LOGI(THIS_TAG, "[VERBOSE] Running query: %s", sql);
    char *zErrMsg = 0;
    int rc = sqlite3_exec(db, sql, callback, (void*)rows, &zErrMsg);
    if (rc != SQLITE_OK) {
        ESP_LOGE(THIS_TAG, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    return rc;
}