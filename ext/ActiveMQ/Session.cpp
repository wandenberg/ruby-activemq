#include "activemq.hpp"

template<>
Rice::Object to_ruby<cms::Session::AcknowledgeMode >(cms::Session::AcknowledgeMode const & a) {
	return Rice::Data_Object<cms::Session::AcknowledgeMode >(new cms::Session::AcknowledgeMode(a), Rice::Data_Type<cms::Session::AcknowledgeMode >::klass(), 0, 0);
}

void register_Session(Module rb_module) {

//	cms::MessageConsumer* (cms::Session::*Session_createConsumer1)(const cms::Destination*) = &cms::Session::createConsumer;
//	cms::MessageConsumer* (cms::Session::*Session_createConsumer2)(const cms::Destination*, const std::string&) = &cms::Session::createConsumer;
//	cms::MessageConsumer* (cms::Session::*Session_createConsumer3)(const cms::Destination*, const std::string&, bool) = &cms::Session::createConsumer;
	cms::TextMessage* (cms::Session::*Session_createTextMessage1)(const std::string&) = &cms::Session::createTextMessage;
//	cms::BytesMessage* (cms::Session::*Session_createBytesMessage0)() = &cms::Session::createBytesMessage;
//	cms::BytesMessage* (cms::Session::*Session_createBytesMessage2)(const unsigned char* bytes, int bytesSize) = &cms::Session::createBytesMessage;
//	cms::QueueBrowser* (cms::Session::*Session_createBrowser1)(const cms::Queue* queue) = &cms::Session::createBrowser;
//	cms::QueueBrowser* (cms::Session::*Session_createBrowser2)(const cms::Queue* queue, const std::string& selector) = &cms::Session::createBrowser;

	Data_Type< cms::Session > rb_cSession =  define_class_under< cms::Session >(rb_module, "Session");
	rb_cSession.define_method("instance?", &instance, (Arg("class")));
//	rb_cSession.define_method("createBytesMessage", Session_createBytesMessage0);
//	rb_cSession.define_method("createBytesMessage2", Session_createBytesMessage2, (Arg("bytes"), Arg("bytesSize")));

	rb_cSession.define_method("create_text_message", Session_createTextMessage1, (Arg("text") = new std::string("")));

	rb_cSession.define_method("create_message", &cms::Session::createMessage);

//	rb_cSession.define_method("create_stream_message", &cms::Session::createStreamMessage);
//	rb_cSession.define_method("create_map_message", &cms::Session::createMapMessage);

//	rb_cSession.define_method("createConsumer", Session_createConsumer1, (Arg("destination")));
//	rb_cSession.define_method("createConsumer2", Session_createConsumer2, (Arg("destination"), Arg("selector")));
//	rb_cSession.define_method("createConsumer3", Session_createConsumer3, (Arg("destination"), Arg("selector"), Arg("noLocal")));

//	rb_cSession.define_method("create_durable_consumer", &cms::Session::createDurableConsumer, (Arg("destination"), Arg("name"), Arg("selector"), Arg("noLocal") = (bool)(false)));
	rb_cSession.define_method("create_producer", &cms::Session::createProducer, (Arg("destination")));

	rb_cSession.define_method("create_queue", &cms::Session::createQueue, (Arg("name")));
	rb_cSession.define_method("create_topic", &cms::Session::createTopic, (Arg("name")));
	rb_cSession.define_method("create_temporary_queue", &cms::Session::createTemporaryQueue);
	rb_cSession.define_method("create_temporary_topic", &cms::Session::createTemporaryTopic);

	rb_cSession.define_method("acknowledge_mode", &cms::Session::getAcknowledgeMode);

	rb_cSession.define_method("transacted?", &cms::Session::isTransacted);

	rb_cSession.define_method("close", &cms::Session::close);
	rb_cSession.define_method("commit", &cms::Session::commit);
	rb_cSession.define_method("rollback", &cms::Session::rollback);
	rb_cSession.define_method("recover", &cms::Session::recover);

//	rb_cSession.define_method("unsubscribe", &cms::Session::unsubscribe, (Arg("name")));

//	rb_cSession.define_method("createBrowser", Session_createBrowser1, (Arg("queue")));
//	rb_cSession.define_method("createBrowser2", Session_createBrowser2, (Arg("queue"), Arg("selector")));

	Enum<cms::Session::AcknowledgeMode> rb_eAcknowledgeMode = define_enum<cms::Session::AcknowledgeMode>("AcknowledgeMode", rb_cSession);

	rb_eAcknowledgeMode.define_value("AUTO_ACKNOWLEDGE", cms::Session::AUTO_ACKNOWLEDGE);
	rb_eAcknowledgeMode.define_value("DUPS_OK_ACKNOWLEDGE", cms::Session::DUPS_OK_ACKNOWLEDGE);
	rb_eAcknowledgeMode.define_value("CLIENT_ACKNOWLEDGE", cms::Session::CLIENT_ACKNOWLEDGE);
	rb_eAcknowledgeMode.define_value("SESSION_TRANSACTED", cms::Session::SESSION_TRANSACTED);
}
