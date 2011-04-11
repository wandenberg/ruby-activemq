#include "activemq.hpp"

void register_Message(Module rb_module) {
	Data_Type< cms::Message > rb_cMessage = define_class_under< cms::Message >(rb_module, "Message");

	rb_cMessage.define_method("getIntProperty", &cms::Message::getIntProperty, (Arg("name")));
	rb_cMessage.define_method("setIntProperty", &cms::Message::setIntProperty, (Arg("name"), Arg("value")));

	rb_cMessage.define_method("getByteProperty", &cms::Message::getByteProperty, (Arg("name")));
	rb_cMessage.define_method("setByteProperty", &cms::Message::setByteProperty, (Arg("name"), Arg("value")));

	rb_cMessage.define_method("getBooleanProperty", &cms::Message::getBooleanProperty, (Arg("name")));
	rb_cMessage.define_method("setBooleanProperty", &cms::Message::setBooleanProperty, (Arg("name"), Arg("value")));

	rb_cMessage.define_method("getDoubleProperty", &cms::Message::getDoubleProperty, (Arg("name")));
	rb_cMessage.define_method("setDoubleProperty", &cms::Message::setDoubleProperty, (Arg("name"), Arg("value")));

	rb_cMessage.define_method("getFloatProperty", &cms::Message::getFloatProperty, (Arg("name")));
	rb_cMessage.define_method("setFloatProperty", &cms::Message::setFloatProperty, (Arg("name"), Arg("value")));

	rb_cMessage.define_method("getLongProperty", &cms::Message::getLongProperty, (Arg("name")));
	rb_cMessage.define_method("setLongProperty", &cms::Message::setLongProperty, (Arg("name"), Arg("value")));

	rb_cMessage.define_method("getShortProperty", &cms::Message::getShortProperty, (Arg("name")));
	rb_cMessage.define_method("setShortProperty", &cms::Message::setShortProperty, (Arg("name"), Arg("value")));

	rb_cMessage.define_method("getStringProperty", &cms::Message::getStringProperty, (Arg("name")));
	rb_cMessage.define_method("setStringProperty", &cms::Message::setStringProperty, (Arg("name"), Arg("value")));

	rb_cMessage.define_method("clone", &cms::Message::clone);

	rb_cMessage.define_method("acknowledge", &cms::Message::acknowledge);
	rb_cMessage.define_method("clearBody", &cms::Message::clearBody);
	rb_cMessage.define_method("clearProperties", &cms::Message::clearProperties);
	rb_cMessage.define_method("propertyExists?", &cms::Message::propertyExists, (Arg("name")));
	rb_cMessage.define_method("propertyNames", &cms::Message::getPropertyNames);

	rb_cMessage.define_method("destination", &cms::Message::getCMSDestination);
	rb_cMessage.define_method("destination=", &cms::Message::setCMSDestination, (Arg("destination")));

	rb_cMessage.define_method("expiration", &cms::Message::getCMSExpiration);
	rb_cMessage.define_method("expiration=", &cms::Message::setCMSExpiration, (Arg("expireTime")));

	rb_cMessage.define_method("message_id", &cms::Message::getCMSMessageID);
	rb_cMessage.define_method("message_id=", &cms::Message::setCMSMessageID, (Arg("id")));

	rb_cMessage.define_method("priority", &cms::Message::getCMSPriority);
	rb_cMessage.define_method("priority=", &cms::Message::setCMSPriority, (Arg("priority")));

	rb_cMessage.define_method("redelivered?", &cms::Message::getCMSRedelivered);
	rb_cMessage.define_method("redelivered=", &cms::Message::setCMSRedelivered, (Arg("redelivered")));

	rb_cMessage.define_method("reply_to", &cms::Message::getCMSReplyTo);
	rb_cMessage.define_method("reply_to=", &cms::Message::setCMSReplyTo, (Arg("destination")));

	rb_cMessage.define_method("timestamp", &cms::Message::getCMSTimestamp);
	rb_cMessage.define_method("timestamp=", &cms::Message::setCMSTimestamp, (Arg("timeStamp")));

	rb_cMessage.define_method("type", &cms::Message::getCMSType);
	rb_cMessage.define_method("type=", &cms::Message::setCMSType, (Arg("type")));

	rb_cMessage.define_method("correlation_id", &cms::Message::getCMSCorrelationID);
	rb_cMessage.define_method("correlation_id=", &cms::Message::setCMSCorrelationID, (Arg("correlationId")));

	rb_cMessage.define_method("delivery_mode", &cms::Message::getCMSDeliveryMode);
	rb_cMessage.define_method("delivery_mode=", &cms::Message::setCMSDeliveryMode, (Arg("mode")));
}
