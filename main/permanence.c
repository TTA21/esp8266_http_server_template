#ifndef PERMANENCE_H
#define PERMANENCE_H
#include "includes.h"
#include "sqlite3.h"
#include "./helpers/sqlite/include.h"

int create_sql_tables();

sqlite3* database;  ///Global permanence object, add more as needed

/*
    Start the sqlite connection, or re-create it if needed.
    CALLED AFTER SPIFFS IS SET

    if return code is 0, something went wrong
*/
int boot_sqlite(char* database_path, bool recreate_db){
    const char* THIS_TAG = "boot_sqlite";
    char full_dir[32];
    strcpy(full_dir, BASE_PATH);
    strcpy(full_dir, database_path);

    if(recreate_db)
        {ESP_LOGI(THIS_TAG, "Recreating database at %s", full_dir); unlink(full_dir);}
    else
        ESP_LOGI(THIS_TAG, "Loading database at %s", full_dir);
    

    sqlite3_initialize();

    if (db_open(full_dir, &database))
        return 0;

    if(recreate_db)
        if(!create_sql_tables()) return 0;

    ESP_LOGI(THIS_TAG, "Database succesfully connected");
    return 1;
}

/*Called after the database is re-created*/
int create_sql_tables(){
    const char* THIS_TAG = "create_sql_tables";
    ESP_LOGI(THIS_TAG, "Creating tables");

    int rc;
    rc = db_exec(database, "CREATE TABLE test1 (id INTEGER, content, content2);", NULL);
    if (rc != SQLITE_OK) {
        sqlite3_close(database);
        return 0;
    }

    return 1;
}
#endif