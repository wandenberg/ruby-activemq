#include "activemq.hpp"

void register_Connection(Module rb_module) {

	cms::Session* (cms::Connection::*Connection_createSession0)() = &cms::Connection::createSession;
	cms::Session* (cms::Connection::*Connection_createSession1)(cms::Session::AcknowledgeMode) = &cms::Connection::createSession;

	Data_Type< cms::Connection > rb_cConnection =  define_class_under< cms::Connection >(rb_module, "Connection");

	rb_cConnection.define_method("create_session", Connection_createSession0);
	rb_cConnection.define_method("create_session1", Connection_createSession1, (Arg("acknowledgeMode")));
	rb_cConnection.define_method("clientID", &cms::Connection::getClientID);
	rb_cConnection.define_method("clientID=", &cms::Connection::setClientID, (Arg("clientID")));

//	rb_cConnection.define_method("close", &cms::Connection::close);

//	{
//		typedef const cms::ConnectionMetaData* ( cms::Connection::*getMetaData_func_type )(  ) const;
//		rb_cConnection.define_method("get_meta_data", getMetaData_func_type( &cms::Connection::getMetaData ));
//	}
//
//	{
//		typedef cms::ExceptionListener* ( cms::Connection::*getExceptionListener_func_type )(  ) const;
//		rb_cConnection.define_method("get_exception_listener", getExceptionListener_func_type( &cms::Connection::getExceptionListener ));
//	}
//
//	{
//		typedef void ( cms::Connection::*setExceptionListener_func_type )( cms::ExceptionListener* listener );
//		rb_cConnection.define_method("set_exception_listener", setExceptionListener_func_type( &cms::Connection::setExceptionListener ), (Arg("listener")));
//	}
}
