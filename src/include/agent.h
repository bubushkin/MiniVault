/*
 * Agent.h
 *
 *  Created on: Jan 1, 2024
 *      Author: iskandar
 */

#ifndef SRC_INCLUDE_AGENT_H_
#define SRC_INCLUDE_AGENT_H_

#include <string>

class Agent {
public:
	Agent(unsigned int, std::string, std::string, unsigned long);


	std::string getIpAddress() const;
	std::string getUUID() const;
	unsigned long getLastContact() const;
	unsigned int getId() const;

	void setIpAddress(std::string *);
	void setUUID(std::string *);
	void setLastContact(unsigned long *);
	void setId(const unsigned int);

private:

	unsigned int _id;
	std::string _ip_address;
	std::string _uuid;
	unsigned long  _last_contact;

};

#endif /* SRC_INCLUDE_AGENT_H_ */
