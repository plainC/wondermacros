int
json_char_to_string(char* self, char* buffer, size_t size)
{
    char tmp[256];
    int len = sprintf(tmp, "%d", *self);

    if (len >= size)
        return -1;

    strncpy(buffer, tmp, len);

    return len;
}

int
json_char_from_string(const char* buffer, const char** endptr, char* self)
{
    unsigned long value = strtoul(buffer, (char**) endptr, 10);

    if (value > 255)
        return 1;

    *self = (char) value;

    return 0;
}
