#include "activemq.hpp"

void register_ConnectionFactory(Module rb_module)
{
	Data_Type< activemq::core::ActiveMQConnectionFactory > rb_cConnectionFactory =  define_class_under< activemq::core::ActiveMQConnectionFactory >(rb_module, "ConnectionFactory");
	rb_cConnectionFactory.define_method("instance?", &instance, (Arg("class")));

	rb_cConnectionFactory.define_constructor(Constructor< activemq::core::ActiveMQConnectionFactory,const std::string&,const std::string&,const std::string& >(), (Arg("broker_url") = new std::string(activemq::core::ActiveMQConnectionFactory::DEFAULT_URI), Arg("username") = new std::string(""), Arg("password") = new std::string("")));
	rb_cConnectionFactory.const_set("DEFAULT_URI", to_ruby(activemq::core::ActiveMQConnectionFactory::DEFAULT_URI));

	rb_cConnectionFactory.define_method("username", &activemq::core::ActiveMQConnectionFactory::getUsername);
	rb_cConnectionFactory.define_method("username=", &activemq::core::ActiveMQConnectionFactory::setUsername, (Arg("username")));

	rb_cConnectionFactory.define_method("password", &activemq::core::ActiveMQConnectionFactory::getPassword);
	rb_cConnectionFactory.define_method("password=", &activemq::core::ActiveMQConnectionFactory::setPassword, (Arg("password")));

	rb_cConnectionFactory.define_method("broker_url", &activemq::core::ActiveMQConnectionFactory::getBrokerURL);
	rb_cConnectionFactory.define_method("broker_url=", &activemq::core::ActiveMQConnectionFactory::setBrokerURL, (Arg("broker_url")));

	rb_cConnectionFactory.define_method("client_id", &activemq::core::ActiveMQConnectionFactory::getClientId);
	rb_cConnectionFactory.define_method("client_id=", &activemq::core::ActiveMQConnectionFactory::setClientId, (Arg("client_id")));

	cms::Connection* (activemq::core::ActiveMQConnectionFactory::*ConnectionFactory_createConnection0)() = &activemq::core::ActiveMQConnectionFactory::createConnection;
	cms::Connection* (activemq::core::ActiveMQConnectionFactory::*ConnectionFactory_createConnection2)(const std::string&, const std::string&) = &activemq::core::ActiveMQConnectionFactory::createConnection;
	cms::Connection* (activemq::core::ActiveMQConnectionFactory::*ConnectionFactory_createConnection3)(const std::string&, const std::string&, const std::string&) = &activemq::core::ActiveMQConnectionFactory::createConnection;

	rb_cConnectionFactory.define_method("create_connection", ConnectionFactory_createConnection0);
	rb_cConnectionFactory.define_method("create_connection_for", ConnectionFactory_createConnection2, (Arg("username"), Arg("password")));
	rb_cConnectionFactory.define_method("create_connection_for_client", ConnectionFactory_createConnection3, (Arg("username"), Arg("password"), Arg("clientId")));
}
