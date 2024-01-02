//
// Created by iskandar on 12/29/23.
//

#ifndef MINIVAULT_MYFACTORY_H
#define MINIVAULT_MYFACTORY_H

#include <string>
#include <cstdlib>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <vector>
#include "Agent.h"

class MyFactory {

public:
	MyFactory(std::unordered_map<std::string, std::string> &);

    const std::string *getHostname();
    const std::string *getSchema();
    Agent *getAgent(std::string *);
    std::vector<Agent*>*  getAgents();

private:
    std::string _host;
    std::string _schema;
    std::string _user;
    std::string _password;

    sql::mysql::MySQL_Driver *_pdriver;
    sql::Connection *_pconn;
    sql::PreparedStatement *_pstmt;
    sql::ResultSet *_prset;

};


#endif //MINIVAULT_MYFACTORY_H
