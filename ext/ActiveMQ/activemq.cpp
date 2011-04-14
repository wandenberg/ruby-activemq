#include "activemq.hpp"

void register_Connection(Module rb_module);
void register_ConnectionFactory(Module rb_module);
void register_Session(Module rb_module);
void register_Message(Module rb_module);
void register_Destinations(Module rb_module);
void register_MessageProducer(Module rb_module);
void register_DeliveryMode(Module rb_module);
void register_TextMessage(Module rb_module);

extern "C"
void Init_ActiveMQ() {
	Module rb_mActivemq = define_module("ActiveMQ");

	activemq::library::ActiveMQCPP::initializeLibrary();

	register_Connection(rb_mActivemq);
	register_ConnectionFactory(rb_mActivemq);
	register_Session(rb_mActivemq);
	register_Message(rb_mActivemq);
	register_Destinations(rb_mActivemq);
	register_MessageProducer(rb_mActivemq);
	register_DeliveryMode(rb_mActivemq);
	register_TextMessage(rb_mActivemq);
}

template<>
long long from_ruby<long long>(Object x)
{
	return protect(detail::num2long, x);
}

template<>
Object to_ruby<long long>(long long const & x)
{
	return protect(detail::long2num, x);
}

Object
instance(Object self, Object class_name)
{
   return to_ruby<bool>(self.class_of().value() == class_name.value());
}
