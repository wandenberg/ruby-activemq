# -*- encoding: utf-8 -*-
require 'spec_helper'

describe ActiveMQ::MessageProducer do

  let :session do
    ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection.create_session
  end

  let :producer do
    session.create_producer(session.create_topic("TEST_MESSAGE_PRODUCER"))
  end

  describe "attributes" do
    it "should respond to some attributes accessors methods" do
      ActiveMQ::MessageProducer.instance_methods.should include_all(["time_to_live", "time_to_live=", "delivery_mode", "delivery_mode=", "priority", "priority=", "disable_message_time_stamp?", "disable_message_time_stamp=", "disable_message_id?", "disable_message_id="])
    end

    it "should have default time to live equal 0" do
      producer.time_to_live.should == 0
    end

    it "should accept a interger as value for time to live attribute" do
      producer.time_to_live = 5
      producer.time_to_live.should == 5
    end

    it "should have default delivery mode equal ActiveMQ::DeliveryMode::PERSISTENT" do
      producer.delivery_mode.should == ActiveMQ::DeliveryMode::PERSISTENT
    end

    it "should accept a interger as value for delivery mode attribute" do
      producer.delivery_mode = ActiveMQ::DeliveryMode::NON_PERSISTENT
      producer.delivery_mode.should == 1
    end

    it "should have default priority equal 4" do
      producer.priority.should == 4
    end

    it "should accept a interger as value for priority attribute" do
      producer.priority = 5
      producer.priority.should == 5
    end

    it "should have default disable_message_time_stamp equal false" do
      producer.disable_message_time_stamp?.should be_false
    end

    it "should accept a boolean as value for disable_message_time_stamp attribute" do
      producer.disable_message_time_stamp = true
      producer.disable_message_time_stamp?.should be_true
    end

    it "should have default disable_message_id equal false" do
      producer.disable_message_id?.should be_false
    end

    it "should accept a boolean as value for disable_message_id attribute" do
      producer.disable_message_id = true
      producer.disable_message_id?.should be_true
    end

  end

  describe "send message" do
    it "should respond to some send message methods" do
      ActiveMQ::MessageProducer.instance_methods.should include_all(["send_message"])
    end

    it "should be possible send a message" do
      message = session.create_text_message "TEST_MESSAGE"
      expect { producer.send_message(message) }.to_not raise_error
    end

  end
end
