#include "activemq.hpp"

using namespace Rice;

void register_ConnectionFactory(Module rb_module) {

    cms::Connection* (cms::ConnectionFactory::*ConnectionFactory_createConnection0)() = &cms::ConnectionFactory::createConnection;
    cms::Connection* (cms::ConnectionFactory::*ConnectionFactory_createConnection2)(const std::string&, const std::string&) = &cms::ConnectionFactory::createConnection;
    cms::Connection* (cms::ConnectionFactory::*ConnectionFactory_createConnection3)(const std::string&, const std::string&, const std::string&) = &cms::ConnectionFactory::createConnection;

	Data_Type< cms::ConnectionFactory > rb_cConnectionFactory =  define_class_under< cms::ConnectionFactory >(rb_module, "ConnectionFactory");

	rb_cConnectionFactory.define_method("createConnection", ConnectionFactory_createConnection0);
	rb_cConnectionFactory.define_method("createConnection2", ConnectionFactory_createConnection2, (Arg("username"), Arg("password")));
	rb_cConnectionFactory.define_method("createConnection3", ConnectionFactory_createConnection3, (Arg("username"), Arg("password"), Arg("clientId")));

	rb_cConnectionFactory.define_singleton_method("createCMSConnectionFactory", &cms::ConnectionFactory::createCMSConnectionFactory, (Arg("brokerURI")));

}
