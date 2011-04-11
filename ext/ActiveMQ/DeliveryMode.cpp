#include "activemq.hpp"

void register_DeliveryMode(Module rb_module) {
	Data_Type< cms::DeliveryMode > rb_cDeliveryMode =  define_class_under< cms::DeliveryMode >(rb_module, "DeliveryMode");
	rb_cDeliveryMode.define_constructor(Constructor< cms::DeliveryMode >());

	int persistent = cms::DeliveryMode::PERSISTENT;
	rb_cDeliveryMode.const_set("PERSISTENT", to_ruby(persistent));

	int non_persistent = cms::DeliveryMode::NON_PERSISTENT;
	rb_cDeliveryMode.const_set("NON_PERSISTENT", to_ruby(non_persistent));

}
