#ifndef HTTP3_SERVER_H
#define HTTP3_SERVER_H

#include "utils/config.h"

class Http3Server {
public:
    Http3Server(const Config& config);
    ~Http3Server();
    
    bool initialize();
    void start();
    void run();
    void stop();


private:
    Config config;
    bool running;

    // more members as needed for QUIC, SSL/TLS, etc.
    bool handle_http3_request();
};

#endif // HTTP3_SERVER_H
