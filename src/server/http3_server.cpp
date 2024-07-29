#include "server/http3_server.h"
#include "utils/logger.h"
#include <thread>
#include <chrono>
#include <fstream>
#include <openssl/ssl.h>
#include <openssl/err.h>

Http3Server::Http3Server(const Config& config) : config(config), running(false) {}

Http3Server::~Http3Server() {}

bool Http3Server::initialize() {
    // Initialize OpenSSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    const SSL_METHOD* method = TLS_server_method();
    SSL_CTX* ctx = SSL_CTX_new(method);

    if (!ctx) {
        Logger::error("Unable to create SSL context");
        ERR_print_errors_fp(stderr);
        return false;
    }

    // Set the certificate and private key
    if (SSL_CTX_use_certificate_file(ctx, config.getSSLCertPath().c_str(), SSL_FILETYPE_PEM) <= 0) {
        Logger::error("Failed to load certificate");
        ERR_print_errors_fp(stderr);
        return false;
    }

    if (SSL_CTX_use_PrivateKey_file(ctx, config.getSSLKeyPath().c_str(), SSL_FILETYPE_PEM) <= 0) {
        Logger::error("Failed to load private key");
        ERR_print_errors_fp(stderr);
        return false;
    }

    Logger::info("Server initialized with SSL/TLS");
    return true;

}

void Http3Server::start() {
    running = true;
    Logger::info("Server started");
    run();
}

void Http3Server::run() {
    while (running) {

        // if (handle_http3_request()) {
        //     // Respond with "Samia server is Handling request!"
        //     Logger::info("Handled request and sent response");
        // }

        // Simulate server work (e.g., handling connections)
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Http3Server::stop() {
    running = false;
}

bool Http3Server::handle_http3_request() {
    // Pseudo-code for handling HTTP/3 requests
    // For actual implementation, use HTTP/3 library functions to accept and process requests

    // Example response
    std::string response = "HTTP/3 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 13\r\n\r\nHello, World!";

    // Send the response (pseudo-code)
    // send_response_to_client(response);

    return true; // Indicate that a request was handled
}