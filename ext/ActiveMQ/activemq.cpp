#include "activemq.hpp"

void register_Connection(Module rb_module);
void register_ConnectionFactory(Module rb_module);
void register_Session(Module rb_module);
void register_Message(Module rb_module);
void register_Destinations(Module rb_module);
void register_MessageProducer(Module rb_module);
void register_DeliveryMode(Module rb_module);
void register_TextMessage(Module rb_module);

void register_ActiveMQConnectionFactory(Module rb_module);


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

	register_ActiveMQConnectionFactory(rb_mActivemq);
}

