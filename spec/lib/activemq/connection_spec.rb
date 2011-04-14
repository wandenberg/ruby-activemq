# -*- encoding: utf-8 -*-
require 'spec_helper'

describe ActiveMQ::Connection do

  describe "change attributes" do
    it "should be created with the same client_id from factory" do
      amqcf = ActiveMQ::ConnectionFactory.new BROKER_URL_TEST
      amqcf.client_id = "client_id_fac"

      conn = amqcf.create_connection
      conn.client_id.should == "client_id_fac"
      conn.close
    end

    it "should be possible change client_id attribute" do
      conn = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection
      conn.client_id.should be_empty
      conn.client_id = "client_id"
      conn.client_id.should == "client_id"
      conn.close
    end
  end

  describe "close connection" do
    it "should respond to close method" do
      conn = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection
      conn.should respond_to(:close)
      conn.close
    end

    it "should respond to close method with no argumments" do
      conn = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection
      conn.close.should be_nil
      conn.close
    end
  end

  describe "session" do
    it "should create session using default acknowledge_mode" do
      conn = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection
      conn.create_session.acknowledge_mode.should == ActiveMQ::Session::AcknowledgeMode::AUTO_ACKNOWLEDGE
      conn.close
    end

    it "should create session using given acknowledge_mode" do
      conn = ActiveMQ::ConnectionFactory.new(BROKER_URL_TEST).create_connection
      conn.create_session(ActiveMQ::Session::AcknowledgeMode::DUPS_OK_ACKNOWLEDGE).acknowledge_mode.should == ActiveMQ::Session::AcknowledgeMode::DUPS_OK_ACKNOWLEDGE
      conn.close
    end
  end
end
