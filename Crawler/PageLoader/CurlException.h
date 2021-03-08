class CurlException
{
    private:
        const char* msg;
        int code;
    public:
        CurlException(const char* msg, int code);
        const char* getMessage() const;
        int getCode() const;
};