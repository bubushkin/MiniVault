//
// Created by iskandar on 1/3/24.
//

#ifndef MINIVAULT_SECRET_H
#define MINIVAULT_SECRET_H

#include <string>

class Secret {

public:

    Secret(std::string cname, std::string raw_secret);

    std::string getCname() const;
    std::string getSecret() const;
    std::string getRawSecret() const;
    void generateSecret();

private:
    std::string _cname;
    std::string _secret;
    std::string _raw_secret;

};


#endif //MINIVAULT_SECRET_H
