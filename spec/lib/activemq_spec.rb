# -*- encoding: utf-8 -*-
require 'spec_helper'

describe ActiveMQ do
  describe "constants" do
    it "should has a defined version" do
      ActiveMQ.constants.should include("VERSION")
    end

    it "should has a string as version" do
      ActiveMQ::VERSION.should be_instance_of(::String)
    end

    it "should has a constant ConnectionFactory" do
      ActiveMQ.constants.should include("ConnectionFactory")
    end

    it "should has a class ConnectionFactory" do
      ActiveMQ::ConnectionFactory.should be_instance_of(::Class)
    end

    it "should has a constant Connection" do
      ActiveMQ.constants.should include("Connection")
    end

    it "should has a class Connection" do
      ActiveMQ::Connection.should be_instance_of(::Class)
    end

    it "should has a constant DeliveryMode" do
      ActiveMQ.constants.should include("DeliveryMode")
    end

    it "should has a class DeliveryMode" do
      ActiveMQ::DeliveryMode.should be_instance_of(::Class)
    end

    it "should has a constant Destination" do
      ActiveMQ.constants.should include("Destination")
    end

    it "should has a class Destination" do
      ActiveMQ::Destination.should be_instance_of(::Class)
    end

    it "should has a constant Message" do
      ActiveMQ.constants.should include("Message")
    end

    it "should has a class Message" do
      ActiveMQ::Message.should be_instance_of(::Class)
    end

    it "should has a constant MessageProducer" do
      ActiveMQ.constants.should include("MessageProducer")
    end

    it "should has a class MessageProducer" do
      ActiveMQ::MessageProducer.should be_instance_of(::Class)
    end

    it "should has a constant Queue" do
      ActiveMQ.constants.should include("Queue")
    end

    it "should has a class Queue" do
      ActiveMQ::Queue.should be_instance_of(::Class)
    end

    it "should has a constant Session" do
      ActiveMQ.constants.should include("Session")
    end

    it "should has a class Session" do
      ActiveMQ::Session.should be_instance_of(::Class)
    end

    it "should has a constant TemporaryQueue" do
      ActiveMQ.constants.should include("TemporaryQueue")
    end

    it "should has a class TemporaryQueue" do
      ActiveMQ::TemporaryQueue.should be_instance_of(::Class)
    end

    it "should has a constant TemporaryTopic" do
      ActiveMQ.constants.should include("TemporaryTopic")
    end

    it "should has a class TemporaryTopic" do
      ActiveMQ::TemporaryTopic.should be_instance_of(::Class)
    end

    it "should has a constant TextMessage" do
      ActiveMQ.constants.should include("TextMessage")
    end

    it "should has a class TextMessage" do
      ActiveMQ::TextMessage.should be_instance_of(::Class)
    end

    it "should has a constant Topic" do
      ActiveMQ.constants.should include("Topic")
    end

    it "should has a class Topic" do
      ActiveMQ::Topic.should be_instance_of(::Class)
    end
  end
end
