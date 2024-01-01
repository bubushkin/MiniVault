//
// Created by iskandar on 12/29/23.
//

#ifndef MINIVAULT_MYFACTORY_H
#define MINIVAULT_MYFACTORY_H

#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class myfactory {

public:
    myfactory();
    void init_cnx();
    const std::string *getHostname();
    const std::string *getSchemaname();

private:
    std::string host;
    std::string schema;
    std::string username;
    std::string password;
    sql::mysql::MySQL_Driver *pdriver;
    sql::Connection *pconn;
    sql::Statement *pstmt;
    sql::ResultSet *prset;

};


#endif //MINIVAULT_MYFACTORY_H
