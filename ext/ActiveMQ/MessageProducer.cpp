#include "activemq.hpp"

void register_MessageProducer(Module rb_module) {
	Data_Type< cms::MessageProducer > rb_cMessageProducer =  define_class_under< cms::MessageProducer >(rb_module, "MessageProducer");


	rb_cMessageProducer.define_method("time_to_live", &cms::MessageProducer::getTimeToLive);
//	rb_cMessageProducer.define_method("time_to_live=", &cms::MessageProducer::setTimeToLive, (Arg("time")));
	{
		typedef void ( cms::MessageProducer::*setTimeToLive_func_type )( long long int time );
		rb_cMessageProducer.define_method("time_to_live=", setTimeToLive_func_type( &cms::MessageProducer::setTimeToLive ), (Arg("time")));
	}


	rb_cMessageProducer.define_method("delivery_mode", &cms::MessageProducer::getDeliveryMode);
	rb_cMessageProducer.define_method("delivery_mode=", &cms::MessageProducer::setDeliveryMode, (Arg("mode")));

	rb_cMessageProducer.define_method("priority", &cms::MessageProducer::getPriority);
	rb_cMessageProducer.define_method("priority=", &cms::MessageProducer::setPriority, (Arg("priority")));

	rb_cMessageProducer.define_method("disable_message_time_stamp?", &cms::MessageProducer::getDisableMessageTimeStamp);
	rb_cMessageProducer.define_method("disable_message_time_stamp=", &cms::MessageProducer::setDisableMessageTimeStamp, (Arg("value")));

	rb_cMessageProducer.define_method("disable_message_id", &cms::MessageProducer::getDisableMessageID);
	rb_cMessageProducer.define_method("disable_message_id=", &cms::MessageProducer::setDisableMessageID, (Arg("value")));

	{
		typedef void ( cms::MessageProducer::*send_func_type )( cms::Message* message, int deliveryMode, int priority, long long int timeToLive );
		rb_cMessageProducer.define_method("send_message_with_attrs", send_func_type( &cms::MessageProducer::send ), (Arg("message"), Arg("delivery_mode"), Arg("priority"), Arg("time_to_live")));
	}

	{
		typedef void ( cms::MessageProducer::*send_func_type )( cms::Message* message );
		rb_cMessageProducer.define_method("send_message", send_func_type( &cms::MessageProducer::send ), (Arg("message")));
	}

	{
		typedef void ( cms::MessageProducer::*send_func_type )( const cms::Destination* destination, cms::Message* message );
		rb_cMessageProducer.define_method("send_message_to", send_func_type( &cms::MessageProducer::send ), (Arg("destination"), Arg("message")));
	}

	{
		typedef void ( cms::MessageProducer::*send_func_type )( const cms::Destination* destination, cms::Message* message, int deliveryMode, int priority, long long int timeToLive );
		rb_cMessageProducer.define_method("send_message_to_with_attrs", send_func_type( &cms::MessageProducer::send ), (Arg("destination"), Arg("message"), Arg("deliveryMode"), Arg("priority"), Arg("timeToLive")));
	}

}
