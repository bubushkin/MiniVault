/*
 * Config.h
 *
 *  Created on: Dec 29, 2023
 *      Author: iskandar
 */

#ifndef SRC_INCLUDE_CONFIG_H_
#define SRC_INCLUDE_CONFIG_H_

#include <string>
#include <filesystem>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>


class Config {
public:
	Config(std::string);

	Config(Config &&other);
	Config(const Config &other);
	Config& operator=(const Config &other);
	Config& operator=(Config &&other);
	std::unordered_map<std::string, std::string>& getConfigMap();

private:
	std::string filepath;
	std::unordered_map<std::string, std::string> configMap; // @suppress("Invalid template argument")

	void generateConfig(std::ifstream &);
};

#endif /* SRC_INCLUDE_CONFIG_H_ */
