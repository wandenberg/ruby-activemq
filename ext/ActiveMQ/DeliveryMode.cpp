#include "activemq.hpp"

void register_DeliveryMode(Module rb_module) {
	Data_Type< cms::DeliveryMode > rb_cDeliveryMode =  define_class_under< cms::DeliveryMode >(rb_module, "DeliveryMode");
	rb_cDeliveryMode.define_constructor(Constructor< cms::DeliveryMode >());
	rb_cDeliveryMode.define_method("instance?", &instance, (Arg("class")));

	rb_cDeliveryMode.const_set("PERSISTENT", to_ruby((int)cms::DeliveryMode::PERSISTENT));
	rb_cDeliveryMode.const_set("NON_PERSISTENT", to_ruby((int)cms::DeliveryMode::NON_PERSISTENT));
}
