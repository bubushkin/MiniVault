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
#include <unordered_map>

#include <vector>
#include "agent.h"
#include "secret.h"

#define SQLEXCEPTION \
		std::cout << "# ERR: SQLException in " << __FILE__; \
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl; \
		std::cout << "# ERR: " << ex.what(); \
		std::cout << " (MySQL error code: " << ex.getErrorCode(); \
		std::cout << ", SQLState: " << ex.getSQLState() << " )" << std::endl; \

class MyFactory {

public:
	MyFactory(std::unordered_map<std::string, std::string> &);
    ~MyFactory();

    const std::string *getHostname();
    const std::string *getSchema();
    Agent *getAgent(std::string *);
    std::vector<Agent*>*  getAgents();
    void registerAgent(Agent *);
    void registerSecret(Secret *);


private:
    std::string _host;
    std::string _schema;
    std::string _user;
    std::string _password;

    sql::mysql::MySQL_Driver *_pdriver;
    sql::Connection *_pconn;

};


#endif //MINIVAULT_MYFACTORY_H
