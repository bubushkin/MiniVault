//
// Created by iskandar on 1/3/24.
//

#include "secret.h"

Secret::Secret(std::string cname, std::string raw_secret, std::string key):_cname(cname), _raw_secret(raw_secret), _key(key){
    this->_psecret = new unsigned char[sizeof(char) * 4096];

}

std::string Secret::getCname() const {
    return this->_cname;
}
unsigned char *Secret::getSecret() const {
    return this->_psecret;
}
std::string Secret::getRawSecret() const {
    return this->_raw_secret;
}

void Secret::setKey(std::string key) {
    this->_key = key
}

void Secret::encrypt(){

    EVP_CIPHER_CTX *pctx = EVP_CIPHER_CTX_new();
    int len = 0;

    if(!pctx){
        PERROR("EVP_CIPHER_CTX_new")
        exit(EXIT_FAILURE);
    }

    if(!EVP_EncryptInit_ex(pctx, EVP_aes_128_ecb(), NULL, reinterpret_cast<const unsigned char *>(this->_key.c_str()), NULL )) {
        PERROR("EVP_aes_128_ecb");
        EVP_CIPHER_CTX_free(pctx);
        exit(EXIT_FAILURE);
    }

    if(!EVP_EncryptUpdate(pctx, this->_psecret, &len, reinterpret_cast<const unsigned char *>(this->_raw_secret.c_str()), this->_raw_secret.length())){
        PERROR("EVP_EncryptUpdate");
        EVP_CIPHER_CTX_free(pctx);
        exit(EXIT_FAILURE);
    }
    this->_cipher_len += len;
}

std::string Secret::decrypt() {

    EVP_CIPHER_CTX *pctx = EVP_CIPHER_CTX_new();

    unsigned char *pxdecrypted = new unsigned char[4096];
    int dec_len = 0;
    if(!pctx){
        PERROR("EVP_CIPHER_CTX_new")
        exit(EXIT_FAILURE);
    }
    if(!EVP_DecryptInit_ex(pctx, EVP_aes_128_ecb(), NULL, reinterpret_cast<const unsigned char *>(this->_key.c_str()), NULL)){
        PERROR("EVP_DecryptInit_ex");
        EVP_CIPHER_CTX_free(pctx);
        exit(EXIT_FAILURE);
    }

    if(!EVP_DecryptUpdate(pctx, pxdecrypted, &dec_len, this->_psecret, this->_cipher_len)){
        PERROR("EVP_DecryptUpdate");
        EVP_CIPHER_CTX_free(pctx);
        exit(EXIT_FAILURE);
    }

    if(!EVP_DecryptFinal_ex(pctx, pxdecrypted + dec_len, &dec_len)){
        PERROR("EVP_DecryptFinal_ex");
        EVP_CIPHER_CTX_free(pctx);
        exit(EXIT_FAILURE);
    }

    std::string str(reinterpret_cast<const char*>(pxdecrypted), sizeof(pxdecrypted) / sizeof(pxdecrypted[0]));
    this->_raw_secret = str;

    EVP_CIPHER_CTX_free(pctx);
    delete pxdecrypted;

    return str;
}