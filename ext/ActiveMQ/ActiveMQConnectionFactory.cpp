#include "activemq.hpp"

void register_ActiveMQConnectionFactory(Module rb_module)
{
	Data_Type< activemq::core::ActiveMQConnectionFactory > rb_cActiveMQConnectionFactory =  define_class_under< activemq::core::ActiveMQConnectionFactory, cms::ConnectionFactory >(rb_module, "ActiveMQConnectionFactory");
	rb_cActiveMQConnectionFactory.define_constructor(Constructor< activemq::core::ActiveMQConnectionFactory >());
	rb_cActiveMQConnectionFactory.define_constructor(Constructor< activemq::core::ActiveMQConnectionFactory,const std::string&,const std::string&,const std::string& >());
	rb_cActiveMQConnectionFactory.const_set("DEFAULT_URI", to_ruby(activemq::core::ActiveMQConnectionFactory::DEFAULT_URI));

	rb_cActiveMQConnectionFactory.define_method("username", &activemq::core::ActiveMQConnectionFactory::getUsername);
	rb_cActiveMQConnectionFactory.define_method("username=", &activemq::core::ActiveMQConnectionFactory::setUsername, (Arg("username")));

	rb_cActiveMQConnectionFactory.define_method("password", &activemq::core::ActiveMQConnectionFactory::getPassword);
	rb_cActiveMQConnectionFactory.define_method("password=", &activemq::core::ActiveMQConnectionFactory::setPassword, (Arg("password")));

	rb_cActiveMQConnectionFactory.define_method("broker_url", &activemq::core::ActiveMQConnectionFactory::getBrokerURL);
	rb_cActiveMQConnectionFactory.define_method("broker_url=", &activemq::core::ActiveMQConnectionFactory::setBrokerURL, (Arg("broker_url")));
}
