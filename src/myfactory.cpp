//
// Created by iskandar on 12/29/23.
//

#include "include/myfactory.h"

MyFactory::MyFactory(std::unordered_map<std::string, std::string> &pconfig) {


	this->_schema = pconfig["schema"];
	this->_user = pconfig["user"];
	this->_password = pconfig["password"];

	try{
		this->_pdriver = sql::mysql::get_mysql_driver_instance();
		this->_pconn = this->_pdriver->connect(this->_host, this->_user, this->_password);
		this->_pconn->setSchema(pconfig["schema"]);
	} catch(sql::SQLException &ex){
		SQLEXCEPTION
		exit(EXIT_FAILURE);
	}
}

MyFactory::~MyFactory(){
    this->_pconn->close();
}

Agent *MyFactory::getAgent(std::string *pip_address){


	Agent *pagent = nullptr;
	std::string SQL = "SELECT id, ip_address, uuid, last_contact FROM " + this->_schema + " WHERE ip_address = ?";
	sql::PreparedStatement *pstmt = nullptr;
	sql::ResultSet *prset = nullptr;

	try{
		pstmt = this->_pconn->prepareStatement(SQL);
		pstmt->setString(1, *pip_address);
		prset = pstmt->executeQuery();
		while(prset->next()){
			pagent = new Agent(prset->getInt(1), prset->getString(2), prset->getString(3), prset->getUInt64(4));
		}

	} catch(sql::SQLException &ex){
		SQLEXCEPTION
	}

	if(pstmt) delete pstmt;
	if(prset) delete prset;
	return pagent;

}

std::vector<Agent*>* MyFactory::getAgents(){
	std::vector<Agent *> *pagents = new std::vector<Agent *>();

	std::string SQL = "SELECT id, ip_address, uuid, last_contact FROM " + this->_schema + ".mv_agent" ;
	sql::PreparedStatement *pstmt = nullptr;
	sql::ResultSet *prset = nullptr;

	try{
		pstmt = this->_pconn->prepareStatement(SQL);
		prset = pstmt->executeQuery();
		while(prset->next()){
			pagents->push_back(new Agent(prset->getInt(1), prset->getString(2), prset->getString(3), prset->getUInt64(4)));
		}

	} catch(sql::SQLException &ex){
		SQLEXCEPTION
	}

	delete pstmt;
	delete prset;
	return pagents;
}


void MyFactory::registerSecret(Secret *psecret) {

    std::string SQL = "INSERT INTO " + this->_schema + ".mv_secret(cname, secret) values(?, ?)";
    sql::PreparedStatement *pstmt = nullptr;

    try{
        pstmt = this->_pconn->prepareStatement(SQL);
        pstmt->setString(1, psecret->getCname());
        pstmt->setString(2, psecret->getSecret());
        pstmt->executeQuery();

    } catch(sql::SQLException &ex){
        SQLEXCEPTION
    }
    delete pstmt;

}

void MyFactory::registerAgent(Agent *pagent) {

    std::string SQL = "INSERT INTO " + this->_schema + ".mv_agent(ip_address, uuid) values(?, ?)";
    sql::PreparedStatement *pstmt = nullptr;

    try{
        pstmt = this->_pconn->prepareStatement(SQL);
        pstmt->setString(1, pagent->getIpAddress());
        pstmt->setString(2, pagent->getUUID());
        pstmt->executeQuery();
    } catch(sql::SQLException &ex){
        SQLEXCEPTION
    }
    delete pstmt;
}

