/*
 * Agent.cpp
 *
 *  Created on: Jan 1, 2024
 *      Author: iskandar
 */

#include "include/Agent.h"

Agent::Agent(unsigned int id, std::string ip_address, std::string uuid, unsigned long last_contact){
	this->_id = id;
	this->_ip_address = ip_address;
	this->_uuid = uuid;
	this->_last_contact = last_contact;

}

std::string Agent::getIpAddress() const{
	return this->_ip_address;

}
std::string Agent::getUUID() const {
	return this->_uuid;

}
unsigned long Agent::getLastContact() const {
	return this->_last_contact;
}

unsigned int Agent::getId() const {
	return this->_id;
}


void Agent::setId(const unsigned int id) {
	this->_id = id;
}


void Agent::setIpAddress(std::string *pip_address) {
	this->_ip_address = *pip_address;

}
void Agent::setUUID(std::string *puuid) {
	this->_uuid = *puuid;

}
void Agent::setLastContact(unsigned long *plast_contact) {
	this->_last_contact = *plast_contact;
}
