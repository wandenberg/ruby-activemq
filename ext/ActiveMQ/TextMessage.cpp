#include "activemq.hpp"

void register_TextMessage(Module rb_module) {
	Data_Type< cms::TextMessage > rb_cTextMessage =  define_class_under< cms::TextMessage,cms::Message >(rb_module, "TextMessage");
	rb_cTextMessage.define_method("text", &cms::TextMessage::getText);

	{
		typedef void ( cms::TextMessage::*setText_func_type )( const std::string& msg );
		rb_cTextMessage.define_method("text=", setText_func_type( &cms::TextMessage::setText ), (Arg("msg")));
	}
}
