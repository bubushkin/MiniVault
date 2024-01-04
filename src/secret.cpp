//
// Created by iskandar on 1/3/24.
//

#include "secret.h"

Secret::Secret(std::string cname, std::string raw_secret) {

    this->_cname = std::move(cname);
    this->_raw_secret = std::move(raw_secret);
}

std::string Secret::getCname() const {
    return this->_cname;
}
std::string Secret::getSecret() const {
    return this->_secret;
}
std::string Secret::getRawSecret() const {
    return this->_raw_secret;
}

void Secret::generateSecret() {

}