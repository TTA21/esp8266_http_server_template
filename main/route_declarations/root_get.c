/* An HTTP GET handler */
esp_err_t root_get_handler(httpd_req_t *req)
{
    const char* resp_str = (const char*) req->user_ctx;
    char* page = read_file("routes/root.html");

    if(page){
        httpd_resp_send(req, page, strlen(page));
    }else{
        httpd_resp_send(req, resp_str, strlen(resp_str));
    }

    free(page);
    return ESP_OK;
}

httpd_uri_t root = {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = root_get_handler,
    .user_ctx  = "<!DOCTYPE> <head></head> <body>Root</body>"
};
