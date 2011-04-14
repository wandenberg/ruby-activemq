#include "activemq.hpp"

void register_Destinations(Module rb_module) {
	Data_Type< cms::Destination > rb_cDestination =  define_class_under< cms::Destination >(rb_module, "Destination");
	rb_cDestination.define_method("instance?", &instance, (Arg("class")));

	rb_cDestination.define_method("destination_type", &cms::Destination::getDestinationType);
//	rb_cDestination.define_method("clone", &cms::Destination::clone);
//	rb_cDestination.define_method("copy", &cms::Destination::copy, (Arg("source")));

	Data_Type< cms::Topic > rb_cTopic = define_class_under< cms::Topic, cms::Destination >(rb_module, "Topic");
	rb_cTopic.define_method("name", &cms::Topic::getTopicName);

	Data_Type< cms::Queue > rb_cQueue =  define_class_under< cms::Queue,cms::Destination >(rb_module, "Queue");
	rb_cQueue.define_method("name", &cms::Queue::getQueueName);

	Data_Type< cms::TemporaryTopic > rb_cTemporaryTopic = define_class_under< cms::TemporaryTopic, cms::Destination >(rb_module, "TemporaryTopic");
	rb_cTemporaryTopic.define_method("name", &cms::TemporaryTopic::getTopicName);

	Data_Type< cms::TemporaryQueue > rb_cTemporaryQueue =  define_class_under< cms::TemporaryQueue,cms::Destination >(rb_module, "TemporaryQueue");
	rb_cTemporaryQueue.define_method("name", &cms::TemporaryQueue::getQueueName);

	Enum<cms::Destination::DestinationType> rb_eDestinationType = define_enum<cms::Destination::DestinationType>("DestinationType", rb_cDestination);
	rb_eDestinationType.define_value("TOPIC", cms::Destination::TOPIC);
	rb_eDestinationType.define_value("QUEUE", cms::Destination::QUEUE);
	rb_eDestinationType.define_value("TEMPORARY_TOPIC", cms::Destination::TEMPORARY_TOPIC);
	rb_eDestinationType.define_value("TEMPORARY_QUEUE", cms::Destination::TEMPORARY_QUEUE);
}
