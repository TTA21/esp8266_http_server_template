#ifndef FILE_HANDLERS_H
#define FILE_HANDLERS_H

void print_directory(const char* directory ){
    const char* THIS_TAG = "printDirectory";
    ESP_LOGI(THIS_TAG, "Listing files in directory: %s", directory);
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (directory)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            ESP_LOGI (THIS_TAG, "\t%s", ent->d_name);
        }
        closedir (dir);
    } else {
        ESP_LOGE(THIS_TAG, "Could not opendir(): %s", directory);
    }
}

void print_spiffs_details(){
    const char* THIS_TAG = "printSpiffsDetails";
    size_t total = 0, used = 0;
    esp_err_t ret = esp_spiffs_info(NULL, &total, &used);
    if (ret != ESP_OK) {
        ESP_LOGE(THIS_TAG, "Failed to get SPIFFS partition information (%s)", esp_err_to_name(ret));
    } else {
        ESP_LOGI(THIS_TAG, "Partition size: total: %d bytes, used: %d bytes", total, used);
    }
}

bool write_to_file(const char* relative_directory, const char* content){
    const char* THIS_TAG = "writeTofile";

    char full_dir[32];
    strcpy(full_dir, BASE_PATH);
    strcpy(full_dir, relative_directory);

    //ESP_LOGI(THIS_TAG, "Opening file: %s", full_dir);
    FILE* f = fopen(relative_directory, "w");
    if (f == NULL) {
        ESP_LOGE(THIS_TAG, "Failed to open file for writing");
        return false;
    }
    fprintf(f, content);
    fclose(f);
    //ESP_LOGI(THIS_TAG, "File written");
    return true;
}

/*Remember to free the returned buffer after use*/
char* read_file(char *relative_directory)
{
    const char* THIS_TAG = "readTextFile";

    char full_dir[32];
    strcpy(full_dir, BASE_PATH);
    strcpy(full_dir, relative_directory);

    //ESP_LOGI(THIS_TAG, "Opening file: %s", full_dir);
    FILE *handler = fopen(relative_directory, "rb");

    char *buffer = NULL;
    int string_size, read_size;

    if (handler)
    {
        // Seek the last byte of the file
        fseek(handler, 0, SEEK_END);
        // Offset from the first to the last byte, or in other words, filesize
        string_size = ftell(handler);
        // go back to the start of the file
        rewind(handler);

        // Allocate a string that can hold it all
        buffer = (char*) calloc(sizeof(char) * (string_size + 1), sizeof(char) );
        // Read it all in one operation
        read_size = fread(buffer, sizeof(char), string_size, handler);

        if (string_size != read_size)
        {
            // Something went wrong, throw away the memory and set
            // the buffer to NULL
            free(buffer);
            buffer = NULL;
            ESP_LOGE(THIS_TAG, "Something went wrong");
        }

        // Always remember to close the file.
        fclose(handler);
        //ESP_LOGI(THIS_TAG, "File read successfully");
    }

    return buffer;
}

#endif