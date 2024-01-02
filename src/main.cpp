#include <iostream>
#include <unistd.h>
#include "include/Config.h"
#include "include/MyFactory.h"


#define USAGE() \
	std::cout << "minivault -c=CONF_FILE_PATH\n"; \
	std::cout << "where\t\nc: path to configuration file"; \
	return EXIT_FAILURE;


int main(int argc, char **argv) {

	int c;

	if(argc < 2){
		USAGE()
	}

	Config *pconfig = nullptr;
	MyFactory *pdb = nullptr;

	while((c = getopt(argc, argv, "c:")) != -1){
		switch(c){
			case 'c': {
				char *pname = optarg;
				try {
					pconfig = new Config(std::string(pname));
				} catch (const std::exception &ex){
					delete pconfig;
				}
				break;
			}
			default: {
				USAGE()
			}
		}
	}

	pdb = new MyFactory(pconfig->getConfigMap());
	auto a = pdb->getAgents();

	delete a;
	delete pdb;
	delete pconfig;
	return EXIT_SUCCESS;

}
