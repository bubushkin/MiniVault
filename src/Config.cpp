/*
 * Config.cpp
 *
 *  Created on: Dec 29, 2023
 *      Author: iskandar
 */

#include "include/Config.h"

Config::Config(std::string name) {
	// TODO Auto-generated constructor stub
	this->filepath = name;
	if(std::filesystem::exists(this->filepath)){

		std::ifstream inputConfig(this->filepath);
		try{
			if(inputConfig.is_open()){
				this->generateConfig(inputConfig);
				inputConfig.close();
			} else {
	            throw std::runtime_error("Error opening config file " + name);
	        }
		} catch(const std::exception &exp){
			inputConfig.close();
			throw std::ifstream::failure("Error reading config file " + name + " : " + exp.what());
		}
	} else{
		throw std::runtime_error("File not found: " + name);
	}
}

void Config::generateConfig(std::ifstream &inputFile){

	std::string line;
	while(std::getline(inputFile, line)){
		if(!line.length()) continue;
		if(line[0] != '#'){

			std::string token;
			std::vector<std::string> buffer;
			std::istringstream tstream(line);

			while(std::getline(tstream, token, '=')){
				buffer.push_back(token);
			}
			this->configMap[buffer[0]] = buffer[1];
		}
	}
}

const std::unordered_map<std::string, std::string> Config::getConfigMap(){
	return this->configMap;
}
