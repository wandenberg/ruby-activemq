#ifndef __ACTIVEMQ_HPP__
#define __ACTIVEMQ_HPP__

#include <rice/Object.hpp>
#include <rice/Data_Type.hpp>
#include <rice/Data_Object.hpp>
#include <rice/String.hpp>
#include <rice/Class.hpp>
#include <rice/Module.hpp>
#include <rice/Exception.hpp>
#include <rice/Array.hpp>
#include <rice/Arg.hpp>
#include <rice/global_function.hpp>
#include <rice/Constructor.hpp>
#include <rice/Enum.hpp>

#include <activemq/core/ActiveMQConnectionFactory.h>
#include <activemq/library/ActiveMQCPP.h>
#include <cms/Connection.h>
#include <cms/ConnectionFactory.h>
#include <cms/Session.h>
#include <cms/Message.h>
#include <cms/Destination.h>
#include <cms/Topic.h>
#include <cms/MessageProducer.h>
#include <cms/DeliveryMode.h>
#include <cms/TextMessage.h>

using namespace Rice;

template<>
long long from_ruby<long long>(Rice::Object x);

template<>
Rice::Object to_ruby<long long>(long long const & x);

Object
instance(Object self, Object class_name);

#endif // __ACTIVEMQ_HPP__
