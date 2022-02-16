#ifndef GET_REQUESTS_C
#define GET_REQUESTS_C

void get_url_query_array(httpd_req_t *req, char* arr){

    char*  buf;
    size_t buf_len;
    /*http://192.168.25.5/hello?asd=asd&qwe=qwe&query1=123
    generates:
        I (147719) APP: Found header => Host: 192.168.25.5
        I (147722) APP: Found URL query => asd=asd&qwe=qwe&query1=123
        I (147724) APP: Found URL query parameter => query1=123
        I (147739) APP: Request headers lost

    */ 
    /* Read URL query string length and allocate memory for length + 1,
     * extra byte for null termination */
    buf_len = httpd_req_get_url_query_len(req) + 1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
            ESP_LOGI(TAG, "Found URL query => %s", buf);
            char param[32];
            /* Get value of expected key from query string */
            if (httpd_query_key_value(buf, "query1", param, sizeof(param)) == ESP_OK) {
                ESP_LOGI(TAG, "Found URL query parameter => query1=%s", param);
            }
            if (httpd_query_key_value(buf, "query3", param, sizeof(param)) == ESP_OK) {
                ESP_LOGI(TAG, "Found URL query parameter => query3=%s", param);
            }
            if (httpd_query_key_value(buf, "query2", param, sizeof(param)) == ESP_OK) {
                ESP_LOGI(TAG, "Found URL query parameter => query2=%s", param);
            }
        }
        free(buf);
    }

}

#endif