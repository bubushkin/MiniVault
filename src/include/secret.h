//
// Created by iskandar on 1/3/24.
//

#ifndef MINIVAULT_SECRET_H
#define MINIVAULT_SECRET_H

#include <string>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <iostream>

#define PERROR(X) \
        std::cerr << __FILE__ << ":" << __FUNCTION__ << ":" <<  X  << errno; \

class Secret {

public:

    Secret(std::string cname, std::string raw_secret, std::string key);

    std::string getCname() const;
    unsigned char * getSecret() const;
    std::string getRawSecret() const;
    void setKey(std::string);
    void encrypt();
    std::string decrypt();

private:
    std::string _cname;
    unsigned char *_psecret;
    std::string _key;
    std::string _raw_secret;
    int _cipher_len = 0;

};


#endif //MINIVAULT_SECRET_H
