#include <iostream>
#include <unistd.h>
#include "include/config.h"
#include "include/myfactory.h"


#define USAGE() \
	std::cout << "minivault -c=CONF_FILE_PATH\n"; \
	std::cout << "where\t\nc: path to configuration file"; \
	return EXIT_FAILURE;

int main(int argc, char **argv) {

	int c;

    std::string err = std::string(__FILE__ + ":" + __FUNCTION__ + ":")

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
                    std::cerr << ex.what() << std::endl;
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
