int
json_boolean_to_string(int* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%s", ((char*[]){"false","true"})[*self > 0]);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_boolean_from_string(const char* buffer, const char** endptr, int* self)
{
    if (strncmp(buffer, "true", 4)==0) {
        *endptr = buffer + 4;
        *self = 1;
    } else if (strncmp(buffer, "false", 5)==0) {
        *endptr = buffer + 5;
        *self = 0;
    } else
        return 1;

    return 0;
}
