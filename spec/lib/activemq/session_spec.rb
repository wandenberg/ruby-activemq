# -*- encoding: utf-8 -*-
require 'spec_helper'

describe ActiveMQ::Session do
  describe "constants" do
    it "should has a defined AcknowledgeMode" do
      ActiveMQ::Session.constants.should include("AcknowledgeMode")
    end

    it "should has a Class as AcknowledgeMode" do
      ActiveMQ::Session::AcknowledgeMode.should be_instance_of(::Class)
    end

    it "should has some constants in the class AcknowledgeMode" do
      ActiveMQ::Session::AcknowledgeMode.constants.should include_all(["AUTO_ACKNOWLEDGE", "DUPS_OK_ACKNOWLEDGE", "CLIENT_ACKNOWLEDGE", "SESSION_TRANSACTED"])
    end
  end

  describe "destinations" do
    it "should create topic from class ActiveMQ::Topic" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_topic("TEST_SESSION").should be_instance_of(ActiveMQ::Topic)
    end

    it "should create queue from class ActiveMQ::Queue" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_queue("TEST_SESSION").should be_instance_of(ActiveMQ::Queue)
    end

    it "should create topic from class ActiveMQ::TemporaryTopic" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_temporary_topic.should be_instance_of(ActiveMQ::TemporaryTopic)
    end

    it "should create queue from class ActiveMQ::TemporaryQueue" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_temporary_queue.should be_instance_of(ActiveMQ::TemporaryQueue)
    end
  end

  describe "producer" do
    it "should create a producer to given destination" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_producer(session.create_topic("TEST_SESSION")).should be_instance_of(ActiveMQ::MessageProducer)
    end
  end

  describe "acknowledge_mode" do
    it "should not be possible change acknowledge_mode" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.should_not respond_to(:acknowledge_mode=)
    end

    it "should be possible get acknowledge_mode" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.should respond_to(:acknowledge_mode)
    end
  end

  describe "message" do
    it "should create a text message" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_message.should be_instance_of(ActiveMQ::Message)
    end

    it "should create a text message" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_text_message.should be_instance_of(ActiveMQ::TextMessage)
    end

    it "should create a text message with a message" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.create_text_message("message").text.should == "message"
    end
  end

  describe "transaction" do
    it "should be possible to know if the session is transacted or not" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.should respond_to(:transacted?)
    end

    it "should return a boolean as response to call method transacted?" do
      session = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
      session.transacted?.should satisfy { |v| v.is_a?(::FalseClass) or v.is_a?(::TrueClass) }
    end

    it "should respond to transactions methods" do
      ActiveMQ::Session.instance_methods.should include_all(["close", "commit", "rollback", "recover"])
    end
  end
end
